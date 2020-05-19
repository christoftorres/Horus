pragma solidity ^0.4.26;

// Simple Options is a binary option smart contract. This is version 2 of the contract. There are a few improvements.

// Users are given a 1 hour window to determine whether the price of ETH will increase or decrease.
// Winners will divide a percentage of the house pot. That percentage is based on odds of winning. 
// The lower the odds of winning, the higher the percentage the winners will receive.
// Odds of winning is equal to Winners Tickets / Total Tickets.
// Payout percent: 10% + 40% x (1 - Odds of Winning)
// Max payout is 50% of the pot
// Only during the first 30 minutes of each round can users buy tickets.
// Once the time has expired, users can force the round to end which will trigger
// a payout from the house pot to the winning side and start a new round with the current price set as the starting price; however,
// if they don't, a cron job ran externally will automatically close the round.
// The user that closes the round will get the gasCost reimbursement from the house pot

// The price per ticket is fixed at 1/10th of the house pot but the minimum price is 0.0001 ETH and max is 1 ETH. Users can buy more than 1 ticket.

// The price Oracle for this contract is the Compound PriceOracle (0x2c9e6bdaa0ef0284eecef0e0cc102dcdeae4887e), which updates
// frequently around every 10 minutes. cToken used is USDC (0x39aa39c021dfbae8fac545936693ac917d5e7563)

// The contract charges a fee that goes to the contract feeAddress. It is 5%. This fee is taken from the winners' payout
// If there are no losers (see below), there are no fees subtracted.

// If at the end of the round, the price stays the same, there are no winners or losers. Everyone can withdraw their balance.
// If the round is not ended within 3 minutes after the deadline, the price is considered stale and there are no winners or
// losers. Everyone can withdraw their balance.
// If at the end of the round, there is no competition, the winners will receive 10% of the house pot split evenly between them.

contract Compound_ETHUSDC {
  function getUnderlyingPrice(address cToken) external view returns (uint256);
}

contract Simple_Options_v2 {

  // Administrator information
  address public feeAddress; // This is the address of the person that collects the fees, nothing more, nothing less. It can be changed.
  uint256 public feePercent = 5000; // This is the percent of the fee (5000 = 5.0%, 1 = 0.001%)
  uint256 constant roundCutoff = 1800; // The cut-off time (in seconds) to submit a bet before the round ends. Currently 12 hours
  uint256 constant roundLength = 3600; // The length of the round (in seconds)
  address constant compoundOracleProxy = 0x2C9e6BDAA0EF0284eECef0e0Cc102dcDEaE4887e; // Contract address for the Compound price oracle proxy
  address constant cUSDCAddress = 0x39AA39c021dfbaE8faC545936693aC917d5E7563;

  // Different types of round Status
  enum RoundStatus {
    OPEN,
    CLOSED,
    STALEPRICE, // No winners due to price being too late
    NOCONTEST // No winners
  }

  struct Round {
    uint256 roundNum; // The round number
    RoundStatus roundStatus; // The round status
    uint256 startPriceWei; // ETH price at start of round
    uint256 endPriceWei; // ETH price at end
    uint256 startTime; // Unix seconds at start of round
    uint256 endTime; // Unix seconds at end
    uint256 endPotSize; // The contract pot size at the end of the round
    uint256 totalCallTickets; // Tickets for expected price increase
    uint256 totalCallPotWei; // Pot size for the users who believe in call
    uint256 totalPutTickets; // Tickets for expected price decrease
    uint256 totalPutPotWei; // Pot size for the users who believe in put

    uint256 totalUsers; // Total users in this round
    mapping (uint256 => address) userList;
    mapping (address => User) users;
  }

  struct User {
    uint256 numCallTickets;
    uint256 numPutTickets;
    uint256 callBalanceWei;
    uint256 putBalanceWei;
  }

  mapping (uint256 => Round) roundList; // A mapping of all the rounds based on an integer
  uint256 public currentRound = 0; // The current round
  uint256 public currentPotSize = 0; // This is the size of the house pot, used to incentivise activity

  event ChangedFeeAddress(address _newFeeAddress);
  event FailedFeeSend(address _user, uint256 _amount);
  event FeeSent(address _user, uint256 _amount);
  event BoughtCallTickets(address _user, uint256 _ticketNum, uint256 _roundNum);
  event BoughtPutTickets(address _user, uint256 _ticketNum, uint256 _roundNum);
  event FailedPriceOracle();
  event StartedNewRound(uint256 _roundNum);

  constructor() public {
    feeAddress = msg.sender; // Set the contract creator to the first feeAddress
  }

  // View function
  // View round information
  function viewRoundInfo(uint256 _numRound) public view returns (
    uint256 _startPriceWei,
    uint256 _endPriceWei,
    uint256 _startTime,
    uint256 _endTime,
    uint256 _totalCallPotWei,
    uint256 _totalPutPotWei,
    uint256 _totalCallTickets, 
    uint256 _totalPutTickets,
    RoundStatus _status,
    uint256 _endPotSize
  ) {
    assert(_numRound <= currentRound);
    assert(_numRound >= 1);
    Round memory _round = roundList[_numRound];
    if(_numRound == currentRound) { _round.endPotSize = currentPotSize; } // For the current Round, current pot is its size
    return (_round.startPriceWei, _round.endPriceWei, _round.startTime, _round.endTime, _round.totalCallPotWei, _round.totalPutPotWei, _round.totalCallTickets, _round.totalPutTickets, _round.roundStatus, _round.endPotSize);
  }

  // View user information that is round specific
  function viewUserInfo(uint256 _numRound, address _userAddress) public view returns (
    uint256 _numCallTickets,
    uint256 _numPutTickets,
    uint256 _balanceWei
  ) {
    assert(_numRound <= currentRound);
    assert(_numRound >= 1);
    Round storage _round = roundList[_numRound];
    User memory _user = _round.users[_userAddress];
    uint256 balance = _user.callBalanceWei + _user.putBalanceWei;
    return (_user.numCallTickets, _user.numPutTickets, balance);
  }

  // View the current round's ticket cost
  function viewCurrentCost() public view returns (
    uint256 _cost
  ) {
    uint256 cost = calculateCost();
    return (cost);
  }

  // Action functions
  // Change contract fee address
  function changeContractFeeAddress(address _newFeeAddress) public {
    require (msg.sender == feeAddress); // Only the current feeAddress can change the feeAddress of the contract
    
    feeAddress = _newFeeAddress; // Update the fee address

     // Trigger event.
    emit ChangedFeeAddress(_newFeeAddress);
  }

  // Add to the contract pot in case it becomes too small to incentivise
  function addToHousePot() public payable {
    require(msg.value > 0);
    currentPotSize = currentPotSize + msg.value;
  }

  // This function creates a new round if the time is right (only after the endTime of the previous round) or if no rounds exist
  // Anyone can request to start a new round, it is not priviledged
  function startNewRound() public {
    uint256 gasUsed = gasleft();
    if(currentRound == 0){
      // This is the first round of the contract
      Round memory _newRound;
      currentRound = currentRound + 1;
      _newRound.roundNum = currentRound;
      
      // Obtain the current price from the Maker Oracle
      _newRound.startPriceWei = getOraclePrice(); // This function must return a price

      // Set the timers up
      _newRound.startTime = now;
      _newRound.endTime = _newRound.startTime + roundLength; // 24 Hour rounds
      roundList[currentRound] = _newRound;

      emit StartedNewRound(currentRound);
    }else if(currentRound > 0){
      // The user wants to close the current round and start a new one
      uint256 cTime = now;
      uint256 feeAmount = 0;
      Round storage _round = roundList[currentRound];
      require( cTime >= _round.endTime ); // Cannot close a round unless the endTime is reached

      // Obtain the current price from the Maker Oracle
      _round.endPriceWei = getOraclePrice();
      _round.endPotSize = currentPotSize; // The pot size will now be distributed

      bool no_contest = false; 

      // If the price is stale, the current round has no losers or winners   
      if( cTime - 180 > _round.endTime){ // More than 3 minutes after round has ended, price is stale
        no_contest = true;
        _round.endTime = cTime;
        _round.roundStatus = RoundStatus.STALEPRICE;
      }

      if(no_contest == false && _round.endPriceWei == _round.startPriceWei){
        no_contest = true; // The price hasn't changed, so no one wins
        _round.roundStatus = RoundStatus.NOCONTEST;
      }

      if(no_contest == false && _round.totalCallTickets == 0 && _round.totalPutTickets == 0){
        no_contest = true; // There are no players in this round
        _round.roundStatus = RoundStatus.NOCONTEST;
      }

      if(no_contest == false){
        // Distribute winnings
        feeAmount = distributeWinnings(_round);

        // Close out the round completely which allows users to withdraw balance
        _round.roundStatus = RoundStatus.CLOSED;
      }

      // Open up a new round using the endTime for the last round as the startTime
      // and the endprice of the last round as the startprice
      Round memory _nextRound;
      currentRound = currentRound + 1;
      _nextRound.roundNum = currentRound;
      
      // The current price will be the previous round's end price
      _nextRound.startPriceWei = _round.endPriceWei;

      // Set the timers up
      _nextRound.startTime = _round.endTime; // Set the start time to the previous round endTime
      _nextRound.endTime = _nextRound.startTime + roundLength; // 24 Hour rounds
      roundList[currentRound] = _nextRound;

      // Send the fee if present
      if(feeAmount > 0){
        bool sentfee = feeAddress.send(feeAmount);
        if(sentfee == false){
          emit FailedFeeSend(feeAddress, feeAmount); // Create an event in case of fee sending failed, but don't stop ending the round
        }else{
          emit FeeSent(feeAddress, feeAmount); // Record that the fee was sent
        }
      }
      emit StartedNewRound(currentRound);
    }

    // Pay back the caller of this function the gas fees from the house pot
    // This is an expensive method so payback caller
    gasUsed = gasUsed - gasleft() + 21000; // Cover the gas for the future send
    uint256 gasCost = tx.gasprice; // This is the price of the gas in wei
    if(gasCost > 15000000000) { gasCost = 15000000000; } // Gas price cannot be greater than 15 Gwei
    gasCost = gasCost * gasUsed;
    if(gasCost > currentPotSize) { gasCost = currentPotSize; } // Cannot be greater than the pot
    currentPotSize = currentPotSize - gasCost;
    if(gasCost > 0){
      msg.sender.transfer(gasCost); // If this fails, revert the entire transaction, they will lose a lot of gas
    }
  }

  // Buy some call tickets
  function buyCallTickets() public payable {
    buyTickets(0);
  }

  // Buy some put tickets
  function buyPutTickets() public payable {
    buyTickets(1);
  }

  // Withdraw from a previous round
  // Cannot withdraw partial funds, all funds are withdrawn
  function withdrawFunds(uint256 roundNum) public {
    require( roundNum > 0 && roundNum < currentRound); // Can only withdraw from previous rounds
    Round storage _round = roundList[roundNum];
    require( _round.roundStatus != RoundStatus.OPEN ); // Round must be closed
    User storage _user = _round.users[msg.sender];
    uint256 balance = _user.callBalanceWei + _user.putBalanceWei;
    require( _user.callBalanceWei + _user.putBalanceWei > 0); // Must have a balance to send out
    _user.callBalanceWei = 0;
    _user.putBalanceWei = 0;
    msg.sender.transfer(balance); // Protected from re-entrancy
  }

  // Private functions
  function calculateCost() private view returns (uint256 _weiCost){
    uint256 cost = currentPotSize / 10;
    cost = ceil(cost,100000000000000);
    if(cost < 100000000000000) { cost = 100000000000000; } // Minimum cost of 0.0001 ETH
    if(cost > 10000000000000000000) { cost = 10000000000000000000; } // Maximum cost of 1 ETH 
    return cost;
  }

  function calculateWinAmount(uint256 _fundSize, uint256 _winTickets, uint256 _totalTickets) private pure returns (uint256 _amount){
    uint256 percent = 10000 + (40000 * (100000 - ((_winTickets * 100000) / _totalTickets))) / 100000; // 100% = 100 000, 1% = 1000
    return (_fundSize * percent) / 100000;
  }

  function ceil(uint a, uint m) private pure returns (uint256 _ceil) {
    return ((a + m - 1) / m) * m;
  }

  // Grabs the price from the Compound price oracle
  function getOraclePrice() private view returns (uint256 _price){
    Compound_ETHUSDC oracle = Compound_ETHUSDC(compoundOracleProxy);
    uint256 usdcPrice = oracle.getUnderlyingPrice(cUSDCAddress); // This returns the price in relation to 1 ether
    usdcPrice = usdcPrice / 1000000000000; // Normalize the price value
    usdcPrice = 1000000000000000000000 / usdcPrice; // The precision level will be 3 decimal places
    return (usdcPrice * 1000000000000000 + currentRound * 1 ether); // Now back to Wei units
  }

  // Distributes the players winnings from the house pot and returns the fee
  // This function is needed to get around Ethereum's variable max
  // Losers funds go to house pot for the next round
  function distributeWinnings(Round storage _round) private returns (uint256 _fee){
    // There are winners and losers
    uint256 feeAmount = 0;
    uint256 addAmount = 0;
    uint256 it = 0;
    uint256 rewardPerTicket = 0;
    uint256 roundTotal = 0;
    uint256 remainBalance = 0;
    if(_round.endPriceWei > _round.startPriceWei){
      // The calls have won the game
      // Divide the house funds appropriately based on odds
      roundTotal = calculateWinAmount(currentPotSize, _round.totalCallTickets, _round.totalCallTickets+_round.totalPutTickets);

      if(_round.totalCallTickets > 0){
        // There may not be call tickets, but still subtract the losers fee
        currentPotSize = currentPotSize - roundTotal; // Take this balance from the pot
        feeAmount = (roundTotal * feePercent) / 100000; // Fee is deducted from the winners amount
        roundTotal = roundTotal - feeAmount;
        rewardPerTicket = roundTotal / _round.totalCallTickets; // Split the pot among the winners
      }
      remainBalance = roundTotal;
      
      for(it = 0; it < _round.totalUsers; it++){ // Go through each user in the round
        User storage _user = _round.users[_round.userList[it]];
        if(_user.numPutTickets > 0){
          // We have some losing tickets, set our put balance to zero
          _user.putBalanceWei = 0;
        }
        if(_user.numCallTickets > 0){
          // We have some winning tickets, add to our call balance
          addAmount = _user.numCallTickets * rewardPerTicket;
          if(addAmount > remainBalance){addAmount = remainBalance;} // Cannot be greater than what is left
          _user.callBalanceWei = _user.callBalanceWei + addAmount;
          remainBalance = remainBalance - addAmount;
        }
      }

      // Now add the losers funds to the remaining pot for the next round
      currentPotSize = currentPotSize + _round.totalPutPotWei;
    }else{
      // The puts have won the game, price has decreased
      // Divide the house funds appropriately based on odds
      roundTotal = calculateWinAmount(currentPotSize, _round.totalPutTickets, _round.totalCallTickets+_round.totalPutTickets);
      if(_round.totalPutTickets > 0){
        // There may not be put tickets, but still subtract the losers fee
        currentPotSize = currentPotSize - roundTotal; // Take this balance from the pot
        feeAmount = (roundTotal * feePercent) / 100000; // Fee is deducted from the winners amount
        roundTotal = roundTotal - feeAmount;
        rewardPerTicket = roundTotal / _round.totalPutTickets; // Split the pot among the winners
      }
      remainBalance = roundTotal;

      for(it = 0; it < _round.totalUsers; it++){ // Go through each user in the round
        User storage _user2 = _round.users[_round.userList[it]];
        if(_user2.numCallTickets > 0){
          // We have some losing tickets, set our call balance to zero
          _user2.callBalanceWei = 0;
        }
        if(_user2.numPutTickets > 0){
          // We have some winning tickets, add to our put balance
          addAmount = _user2.numPutTickets * rewardPerTicket;
          if(addAmount > remainBalance){addAmount = remainBalance;} // Cannot be greater than what is left
          _user2.putBalanceWei = _user2.putBalanceWei + addAmount;
          remainBalance = remainBalance - addAmount;
        }
      }

      // Now add the losers funds to the remaining pot for the next round
      currentPotSize = currentPotSize + _round.totalCallPotWei;
    }
    return feeAmount;
  } 

  function buyTickets(uint256 ticketType) private {
    require( currentRound > 0 ); // There must be an active round ongoing
    Round storage _round = roundList[currentRound];
    uint256 endTime = _round.endTime;
    uint256 currentTime = now;
    require( currentTime <= endTime - roundCutoff); // Cannot buy a ticket after the cutoff time
    uint256 currentCost = calculateCost(); // Calculate the price
    require(msg.value % currentCost == 0); // The value must be a multiple of the cost
    require(msg.value >= currentCost); // Must have some value
    require(_round.totalUsers <= 1000); // Cannot have more than 1000 users per round
    require(_round.roundStatus == RoundStatus.OPEN); // Round is still open, it should be
    
    uint256 numTickets = msg.value / currentCost; // The user can buy multple tickets

    // Check if user is in the mapping
    User memory _user = _round.users[msg.sender];
    if(_user.numCallTickets + _user.numPutTickets == 0){
      // No tickets yet for user, new user
      _round.userList[_round.totalUsers] = msg.sender;
      _round.totalUsers = _round.totalUsers + 1;
    }

    if(ticketType == 0){
      // Call ticket
      _user.numCallTickets = _user.numCallTickets + numTickets;
      _user.callBalanceWei = _user.callBalanceWei + msg.value;
      _round.totalCallTickets = _round.totalCallTickets + numTickets;
      _round.totalCallPotWei = _round.totalCallPotWei + msg.value;

      emit BoughtCallTickets(msg.sender, numTickets, currentRound);
    }else{
      // Put ticket
      _user.numPutTickets = _user.numPutTickets + numTickets;
      _user.putBalanceWei = _user.putBalanceWei + msg.value;
      _round.totalPutTickets = _round.totalPutTickets + numTickets;
      _round.totalPutPotWei = _round.totalPutPotWei + msg.value;

      emit BoughtPutTickets(msg.sender, numTickets, currentRound);
    }

    _round.users[msg.sender] = _user; // Add the user information to the game
  }
}