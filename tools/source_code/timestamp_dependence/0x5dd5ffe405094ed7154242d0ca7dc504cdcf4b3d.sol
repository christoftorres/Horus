pragma solidity ^0.4.24;

contract ERC20Basic {
  function totalSupply() public view returns (uint256);
  function balanceOf(address _who) public view returns (uint256);
  function transfer(address _to, uint256 _value) public returns (bool);
  event Transfer(address indexed from, address indexed to, uint256 value);
}

contract ERC20 is ERC20Basic {
  function allowance(address _owner, address _spender)
    public view returns (uint256);

  function transferFrom(address _from, address _to, uint256 _value)
    public returns (bool);

  function approve(address _spender, uint256 _value) public returns (bool);
  event Approval(
    address indexed owner,
    address indexed spender,
    uint256 value
  );
}

contract BasicToken is ERC20Basic {
  using SafeMath for uint256;

  mapping(address => uint256) internal balances;

  uint256 internal totalSupply_;

  /**
  * @dev Total number of tokens in existence
  */
  function totalSupply() public view returns (uint256) {
    return totalSupply_;
  }

  /**
  * @dev Transfer token for a specified address
  * @param _to The address to transfer to.
  * @param _value The amount to be transferred.
  */
  function transfer(address _to, uint256 _value) public returns (bool) {
    require(_value <= balances[msg.sender]);
    require(_to != address(0));

    balances[msg.sender] = balances[msg.sender].sub(_value);
    balances[_to] = balances[_to].add(_value);
    emit Transfer(msg.sender, _to, _value);
    return true;
  }

  /**
  * @dev Gets the balance of the specified address.
  * @param _owner The address to query the the balance of.
  * @return An uint256 representing the amount owned by the passed address.
  */
  function balanceOf(address _owner) public view returns (uint256) {
    return balances[_owner];
  }

}

contract StandardToken is ERC20, BasicToken {

  mapping (address => mapping (address => uint256)) internal allowed;


  /**
   * @dev Transfer tokens from one address to another
   * @param _from address The address which you want to send tokens from
   * @param _to address The address which you want to transfer to
   * @param _value uint256 the amount of tokens to be transferred
   */
  function transferFrom(
    address _from,
    address _to,
    uint256 _value
  )
    public
    returns (bool)
  {
    require(_value <= balances[_from]);
    require(_value <= allowed[_from][msg.sender]);
    require(_to != address(0));

    balances[_from] = balances[_from].sub(_value);
    balances[_to] = balances[_to].add(_value);
    allowed[_from][msg.sender] = allowed[_from][msg.sender].sub(_value);
    emit Transfer(_from, _to, _value);
    return true;
  }

  /**
   * @dev Approve the passed address to spend the specified amount of tokens on behalf of msg.sender.
   * Beware that changing an allowance with this method brings the risk that someone may use both the old
   * and the new allowance by unfortunate transaction ordering. One possible solution to mitigate this
   * race condition is to first reduce the spender's allowance to 0 and set the desired value afterwards:
   * https://github.com/ethereum/EIPs/issues/20#issuecomment-263524729
   * @param _spender The address which will spend the funds.
   * @param _value The amount of tokens to be spent.
   */
  function approve(address _spender, uint256 _value) public returns (bool) {
    allowed[msg.sender][_spender] = _value;
    emit Approval(msg.sender, _spender, _value);
    return true;
  }

  /**
   * @dev Function to check the amount of tokens that an owner allowed to a spender.
   * @param _owner address The address which owns the funds.
   * @param _spender address The address which will spend the funds.
   * @return A uint256 specifying the amount of tokens still available for the spender.
   */
  function allowance(
    address _owner,
    address _spender
   )
    public
    view
    returns (uint256)
  {
    return allowed[_owner][_spender];
  }

  /**
   * @dev Increase the amount of tokens that an owner allowed to a spender.
   * approve should be called when allowed[_spender] == 0. To increment
   * allowed value is better to use this function to avoid 2 calls (and wait until
   * the first transaction is mined)
   * From MonolithDAO Token.sol
   * @param _spender The address which will spend the funds.
   * @param _addedValue The amount of tokens to increase the allowance by.
   */
  function increaseApproval(
    address _spender,
    uint256 _addedValue
  )
    public
    returns (bool)
  {
    allowed[msg.sender][_spender] = (
      allowed[msg.sender][_spender].add(_addedValue));
    emit Approval(msg.sender, _spender, allowed[msg.sender][_spender]);
    return true;
  }

  /**
   * @dev Decrease the amount of tokens that an owner allowed to a spender.
   * approve should be called when allowed[_spender] == 0. To decrement
   * allowed value is better to use this function to avoid 2 calls (and wait until
   * the first transaction is mined)
   * From MonolithDAO Token.sol
   * @param _spender The address which will spend the funds.
   * @param _subtractedValue The amount of tokens to decrease the allowance by.
   */
  function decreaseApproval(
    address _spender,
    uint256 _subtractedValue
  )
    public
    returns (bool)
  {
    uint256 oldValue = allowed[msg.sender][_spender];
    if (_subtractedValue >= oldValue) {
      allowed[msg.sender][_spender] = 0;
    } else {
      allowed[msg.sender][_spender] = oldValue.sub(_subtractedValue);
    }
    emit Approval(msg.sender, _spender, allowed[msg.sender][_spender]);
    return true;
  }

}

contract Ownable {
  address public owner;


  event OwnershipRenounced(address indexed previousOwner);
  event OwnershipTransferred(
    address indexed previousOwner,
    address indexed newOwner
  );


  /**
   * @dev The Ownable constructor sets the original `owner` of the contract to the sender
   * account.
   */
  constructor() public {
    owner = msg.sender;
  }

  /**
   * @dev Throws if called by any account other than the owner.
   */
  modifier onlyOwner() {
    require(msg.sender == owner);
    _;
  }

  /**
   * @dev Allows the current owner to relinquish control of the contract.
   * @notice Renouncing to ownership will leave the contract without an owner.
   * It will not be possible to call the functions with the `onlyOwner`
   * modifier anymore.
   */
  function renounceOwnership() public onlyOwner {
    emit OwnershipRenounced(owner);
    owner = address(0);
  }

  /**
   * @dev Allows the current owner to transfer control of the contract to a newOwner.
   * @param _newOwner The address to transfer ownership to.
   */
  function transferOwnership(address _newOwner) public onlyOwner {
    _transferOwnership(_newOwner);
  }

  /**
   * @dev Transfers control of the contract to a newOwner.
   * @param _newOwner The address to transfer ownership to.
   */
  function _transferOwnership(address _newOwner) internal {
    require(_newOwner != address(0));
    emit OwnershipTransferred(owner, _newOwner);
    owner = _newOwner;
  }
}

contract MintableToken is StandardToken, Ownable {
  event Mint(address indexed to, uint256 amount);
  event MintFinished();

  bool public mintingFinished = false;


  modifier canMint() {
    require(!mintingFinished);
    _;
  }

  modifier hasMintPermission() {
    require(msg.sender == owner);
    _;
  }

  /**
   * @dev Function to mint tokens
   * @param _to The address that will receive the minted tokens.
   * @param _amount The amount of tokens to mint.
   * @return A boolean that indicates if the operation was successful.
   */
  function mint(
    address _to,
    uint256 _amount
  )
    public
    hasMintPermission
    canMint
    returns (bool)
  {
    totalSupply_ = totalSupply_.add(_amount);
    balances[_to] = balances[_to].add(_amount);
    emit Mint(_to, _amount);
    emit Transfer(address(0), _to, _amount);
    return true;
  }

  /**
   * @dev Function to stop minting new tokens.
   * @return True if the operation was successful.
   */
  function finishMinting() public onlyOwner canMint returns (bool) {
    mintingFinished = true;
    emit MintFinished();
    return true;
  }
}

contract Pausable is Ownable {
  event Pause();
  event Unpause();

  bool public paused = false;


  /**
   * @dev Modifier to make a function callable only when the contract is not paused.
   */
  modifier whenNotPaused() {
    require(!paused);
    _;
  }

  /**
   * @dev Modifier to make a function callable only when the contract is paused.
   */
  modifier whenPaused() {
    require(paused);
    _;
  }

  /**
   * @dev called by the owner to pause, triggers stopped state
   */
  function pause() public onlyOwner whenNotPaused {
    paused = true;
    emit Pause();
  }

  /**
   * @dev called by the owner to unpause, returns to normal state
   */
  function unpause() public onlyOwner whenPaused {
    paused = false;
    emit Unpause();
  }
}

contract PausableToken is StandardToken, Pausable {

  function transfer(
    address _to,
    uint256 _value
  )
    public
    whenNotPaused
    returns (bool)
  {
    return super.transfer(_to, _value);
  }

  function transferFrom(
    address _from,
    address _to,
    uint256 _value
  )
    public
    whenNotPaused
    returns (bool)
  {
    return super.transferFrom(_from, _to, _value);
  }

  function approve(
    address _spender,
    uint256 _value
  )
    public
    whenNotPaused
    returns (bool)
  {
    return super.approve(_spender, _value);
  }

  function increaseApproval(
    address _spender,
    uint _addedValue
  )
    public
    whenNotPaused
    returns (bool success)
  {
    return super.increaseApproval(_spender, _addedValue);
  }

  function decreaseApproval(
    address _spender,
    uint _subtractedValue
  )
    public
    whenNotPaused
    returns (bool success)
  {
    return super.decreaseApproval(_spender, _subtractedValue);
  }
}

contract Controller is MintableToken, PausableToken {
    address public thisAddr; // matches delegation slot in proxy
    uint256 public cap;      // the max cap of this token

    string public constant name = "DivTwo"; // solium-disable-line uppercase
    string public constant symbol = "DivTwo"; // solium-disable-line uppercase
    uint8 public constant decimals = 2; // solium-disable-line uppercase

    constructor() public {}

    /**
    * @dev Function to initialize storage, only callable from proxy.
    * @param _controller The address where code is loaded from through delegatecall
    * @param _cap The cap that should be set for the token
    */
    function initialize(address _controller, uint256 _cap) public onlyOwner {
        require(cap == 0, "Cap is already set");
        require(_cap > 0, "Trying to set an invalid cap");
        require(thisAddr == _controller, "Not calling from proxy");
        cap = _cap;
        totalSupply_ = 0;
    }

    /**
    * @dev Function to mint tokens
    * @param _to The address that will receive the minted tokens.
    * @param _amount The amount of tokens to mint.
    * @return A boolean that indicates if the operation was successful.
    */
    function mint(address _to, uint256 _amount) public onlyOwner canMint returns (bool) {
        require(cap > 0, "Cap not set, not initialized");
        require(totalSupply_.add(_amount) <= cap, "Trying to mint over the cap");
        return super.mint(_to, _amount);
    }
}

library SafeMath {

  /**
  * @dev Multiplies two numbers, throws on overflow.
  */
  function mul(uint256 a, uint256 b) internal pure returns (uint256 c) {
    if (a == 0) {
      return 0;
    }
    c = a * b;
    assert(c / a == b);
    return c;
  }

  /**
  * @dev Integer division of two numbers, truncating the quotient.
  */
  function div(uint256 a, uint256 b) internal pure returns (uint256) {
    // assert(b > 0); // Solidity automatically throws when dividing by 0
    // uint256 c = a / b;
    // assert(a == b * c + a % b); // There is no case in which this doesn't hold
    return a / b;
  }

  /**
  * @dev Subtracts two numbers, throws on overflow (i.e. if subtrahend is greater than minuend).
  */
  function sub(uint256 a, uint256 b) internal pure returns (uint256) {
    assert(b <= a);
    return a - b;
  }

  /**
  * @dev Adds two numbers, throws on overflow.
  */
  function add(uint256 a, uint256 b) internal pure returns (uint256 c) {
    c = a + b;
    assert(c >= a);
    return c;
  }
}

contract LockedController is Controller {

    /**
    * Defining locked balance data structure
    **/
    struct tlBalance {
        uint256 timestamp;
        uint256 balance;
    }

    mapping(address => tlBalance[]) lockedBalances;

    event Locked(address indexed to, uint256 amount, uint256 timestamp);

    /**
    * @dev Returns the amount of locked balances of the specified address.
    * @param _owner The address to query the balance of.
    * @return An uint256 representing the length of the array of locked balances owned by the passed address.
    */
    function lockedBalanceLength(address _owner) public view returns (uint256) {
        return lockedBalances[_owner].length;
    }

    /**
    * @dev Returns the locked balance of the specified address.
    * @param _owner The address to query the balance of.
    * @return An uint256 representing the amount owned by the passed address.
    */
    function lockedBalanceOf(address _owner) public view returns (uint256) {
        uint256 lockedBalance = 0;
        for(uint256 i = 0; i < lockedBalanceLength(_owner); i++){
            if(lockedBalances[_owner][i].timestamp>now) {
                lockedBalance += lockedBalances[_owner][i].balance;
            }
        }
        return lockedBalance;
    }

    /**
    * @dev Returns the unlocked balance of the specified address.
    * @param _owner The address to query the the balance of.
    * @return An uint256 representing the amount owned by the passed address.
    */
    function unlockedBalanceOf(address _owner) public view returns (uint256) {
        return super.balanceOf(_owner)-lockedBalanceOf(_owner);
    }

    /**
    * @dev Removes the already unlocked tokens from the lockedBalances array for the specified address.
    * @param _owner The address to consolidate the balance of.
    */
    function consolidateBalance(address _owner) public returns (bool) {
        tlBalance[] storage auxBalances = lockedBalances[_owner];
        delete lockedBalances[_owner];
        for(uint256 i = 0; i<auxBalances.length; i++){
            if(auxBalances[i].timestamp > now) {
                lockedBalances[_owner].push(auxBalances[i]);
            }
        }
        return true;
    }

    /**
    * @dev transfer token for a specified address
    * @param _to The address to transfer to.
    * @param _amount The amount to be transferred.
    */
    function transfer(address _to, uint256 _amount) public returns (bool) {
        require(_to != address(0), "You can not transfer to address(0).");
        require(_amount <= unlockedBalanceOf(msg.sender), "There is not enough unlocked balance.");
        consolidateBalance(msg.sender);
        return super.transfer(_to, _amount);
    }

    /**
    * @dev Transfer tokens from one address to another
    * @param _from address The address which you want to send tokens from
    * @param _to address The address which you want to transfer to
    * @param _amount uint256 the amount of tokens to be transferred
    */
    function transferFrom(address _from, address _to, uint256 _amount) public returns (bool) {
        require(_to != address(0), "You can not transfer to address(0).");
        require(_amount <= unlockedBalanceOf(_from), "There is not enough unlocked balance.");
        require(_amount <= allowed[_from][msg.sender], "There is not enough allowance.");
        consolidateBalance(_from);
        return super.transferFrom(_from, _to, _amount);
    }

    /**
    * @dev Unlocks balance of the specified address, only callable by owner
    * @param _owner The address to query the the balance of.
    */
    function unlockAllFunds(address _owner) public onlyOwner returns (bool){
        delete lockedBalances[_owner];
        return true;
    }

    /**
    * @dev transfer token to a specified address
    * @param _to The address to transfer to.
    * @param _amount The amount to be transferred.
    * @param _timestamp Unlock timestamp.
    */
    function transferLockedFunds(address _to, uint256 _amount, uint256 _timestamp) public returns (bool){
        transfer(_to, _amount);
        lockedBalances[_to].push(tlBalance(_timestamp,_amount));
        emit Locked(_to, _amount, _timestamp);
        return true;
    }

    /**
    * @dev Transfer tokens from one address to another
    * @param _from address The address which you want to send tokens from
    * @param _to address The address which you want to transfer to
    * @param _amount uint256 the amount of tokens to be transferred
    * @param _timestamp Unlock timestamp.
    */
    function transferLockedFundsFrom(address _from, address _to, uint256 _amount, uint256 _timestamp) public returns (bool) {
        transferFrom(_from, _to, _amount);
        lockedBalances[_to].push(tlBalance(_timestamp,_amount));
        emit Locked(_to, _amount, _timestamp);
        return true;
    }

    /**
    * @dev transfer token to a specified address
    * @param _to The address to transfer to.
    * @param _amounts The amounts to be transferred.
    * @param _timestamps Unlock timestamps.
    */
    function transferListOfLockedFunds(address _to, uint256[] _amounts, uint256[] _timestamps) public returns (bool) {
        require(_amounts.length==_timestamps.length, "There is not the same number of amounts and timestamps.");
        uint256 _amount = 0;
        for(uint256 i = 0; i<_amounts.length; i++){
            _amount += _amounts[i];
        }
        transfer(_to, _amount);
        for(i = 0; i<_amounts.length; i++){
            lockedBalances[_to].push(tlBalance(_timestamps[i],_amounts[i]));
            emit Locked(_to, _amounts[i], _timestamps[i]);
        }
        return true;
    }

    /**
    * @dev Transfer tokens from one address to another
    * @param _from address The address which you want to send tokens from
    * @param _to address The address which you want to transfer to
    * @param _amounts uint256 the amount of tokens to be transferred
    * @param _timestamps Unlock timestamps.
    */
    function transferListOfLockedFundsFrom(address _from, address _to, uint256[] _amounts, uint256[] _timestamps) public returns (bool) {
        require(_amounts.length==_timestamps.length, "There is not the same number of amounts and timestamps.");
        uint256 _amount = 0;
        for(uint256 i = 0; i<_amounts.length; i++){
            _amount += _amounts[i];
        }
        transferFrom(_from, _to, _amount);
        for(i = 0; i<_amounts.length; i++){
            lockedBalances[_to].push(tlBalance(_timestamps[i],_amounts[i]));
            emit Locked(_to, _amounts[i], _timestamps[i]);
        }
        return true;
    }

    /**
    * @dev Function to mint locked tokens
    * @param _to The address that will receive the minted tokens.
    * @param _amount The amount of tokens to mint.
    * @param _timestamp When the tokens will be unlocked
    * @return A boolean that indicates if the operation was successful.
    */
    function mintLockedBalance(address _to, uint256 _amount, uint256 _timestamp) public onlyOwner canMint returns (bool) {
        require(_timestamp > now, "You can not add a token to unlock in the past.");
        super.mint(_to, _amount);
        lockedBalances[_to].push(tlBalance(_timestamp,_amount));
        emit Locked(_to, _amount, _timestamp);
        return true;
    }
}

contract IDealsSupport {

// Any user

  /**
   * @dev Checks whether a deal can be cancelled by merchant
   * @param _dealIndex deal index
   * @return whether a deal can be cancelled by merchant
   */
  function canBeCancelledByMerchant(uint _dealIndex) public view returns(bool);

  /**
   * @dev Returns affiliate reward info
   * @param _referenceHash affiliate's reference hash(index)
   * @param _affiliateRewardIndex affiliate reward index
   * @return affiliate reward info
   */
  function getAffiliateRewardInfo(uint _referenceHash, uint _affiliateRewardIndex) public view returns(uint, uint);

  /**
   * @dev Returns deal index by reference hash
   * @param _referenceHash affiliate's reference hash(index)
   * @return deal index
   */
  function getDealIndex(uint _referenceHash) public view returns(uint);

  /**
   * @dev Returns dynamic deal info: reference hashes.
   * @param _dealIndex deal index
   * @return array of reference hashes in deal
   */
  function getDynamicDealInfo(uint _dealIndex) public view returns(uint[]);

  /**
   * @dev Returns reference hash that should be passed in reference links
   * @param _dealIndex deal index
   * @param _affiliateAddress affiliate address
   * @return reference hash
   */
  function getReferenceHash(uint _dealIndex, address _affiliateAddress) public view returns(uint);

  /**
   * @dev Checks whether deal is cancelled
   * @param _dealIndex deal index
   * @return bool whether deal is cancelled
   */
  function isDealCancelled(uint _dealIndex) public view returns(bool);

  /**
   * @dev Checks whether deal is closed
   * @param _dealIndex deal index
   * @return bool whether deal is closed
   */
  function isDealClosed(uint _dealIndex) public view returns(bool);

// Admin

  /**
   * @dev Blocks/unblocks affiliate. As an admin i would like to block the selected affiliate.
   * @param _referenceHash affiliate's reference hash(index)
   */
  function toggleBlockAffiliate(uint _referenceHash) public;

  /**
   * @dev Cancells deal immediately. As an admin I would like to immediately cancel the selected deal in order to prevent fraudulent behaviour.
   * @notice Will immediately move the selected deal into 'cancelled' state
   * @param _dealIndex deal index
   */
  function cancelDealByAdmin(uint _dealIndex) public;

  /**
   * @dev Changes admin address(transfer ownership)
   * @param _newAdminAddress new admin address
   */
  function changeAdmin(address _newAdminAddress) public;

// Affiliate

  /**
   * @dev Withdraws a reward by affiliate. As an affiliate i would like to get my reward for the selected deal in order to get money.
   * Preconditions:
   *  1. The Deal index is valid.
   *  2. Affiliate is not blocked.
   *  3. The reward amount is non zero for the selected affiliate.
   *  4. The reward amount is non zero for the selected deal.
   * @param _dealIndex deal index
   * Result:
   *   All reward tokens are transferred from the current MultistageCrowdsale contract to the affiliate.
   *   The reward amount for the selected affiliate is set to zero.
   *   The reward amount for the selected deal is decreased.
   */
  function getMyReward(uint _dealIndex) public;

// Merchant

  /**
   * @dev Approves affiliate address for deal. As a merchant i would like to manually approve selected affiliate in order to provide incentives.
   * @notice The same affiliate address can have different reference hashes because the same affiliate address can participate in multiple deals.
   * @param _dealIndex deal index
   * @param _affiliateAddress affiliate address
   */
  function approveAffiliate(uint _dealIndex, address _affiliateAddress) public;

  /**
   * @dev Cancels all deals by merchant
   */
  function cancelAllDealsByMerchant() public;

  /**
   * @dev Marks deal to be cancelled by merchant. As a merchant I would like to request a deal cancelation in order to cancel it after “Cancelation period” is elapsed.
   * @param _dealIndex deal index
   */
  function cancelDealByMerchant(uint _dealIndex) public;

  /**
   * @dev Creates a new deal by merchant. As a merchant i would like to create new deal in order to add incentives for affiliates.
   * @param _rewardTokenAddress ERC20 token address used for affiliates' rewards
   * @param _rewardRatePpm reward rate ppm, 100% == 1000000
   * @param _daysOfCancellation when deal is marked as cancelled it is still live for _daysOfCancellation number of days
   * @param _daysBeforeClose number of days since deal creation when deal is still live, the deal is over and any left over staked tokens can be withdrawn by merchant
   */
  function createDeal(bytes4 _dealID, address _rewardTokenAddress, uint _rewardRatePpm, uint _daysOfCancellation, uint _daysBeforeClose, bool _isAcceptAnyAffiliate) public;

  /**
   * @dev Stakes ERC20 tokens as reward for affiliates by merchant. As a merchant i would like to transfer ERC20 tokens to the selected deal in order to stake them.
   * @notice Merchant should allow _amount of tokens to be withdrawn (use ERC20.approve() method) BEFORE calling this method.
   * Preconditions:
   *  1. The Deal was created by Merchant before
   *  2. isCancelled == false
   *  3. isClosed == false
   *  4. Merchant allowed current MultistageCrowdsale to withdraw correct amount of tokens
   * @param _dealIndex deal index
   * @param _amount amount in wei
   */
  function fillStake(uint _dealIndex, uint _amount) public;

  /**
   * @dev Returns tokens at stake back to merchant if deal is cancelled. As a merchant i would like to get my stake back in order to get my tokens back (if deal is cancelled).
   * Preconditions:
     *  1. The Deal was created by Merchant before.
     *  2. The Deal isCancelled==true.
     *  3. The Deal still has some stake left.
   *  4. The Deal has enough tokens to pay to all affiliates.
   * @param _dealIndex deal index
   * Result:
     *    All staked reward tokens are transferred from the current MultistageCrowdsale contract back to merchant.
     *    The “Current reward stake amount” of the selected Deal is decreased.
   */
  function getMyStakeBack(uint _dealIndex) public;

  /**
   * @dev Updates a deal by merchant
   * @param _dealIndex deal index
   * @param _newRewardRatePpm new reward rate ppm, 100% == 1000000
   */
  function updateDeal(uint _dealIndex, uint _newRewardRatePpm) public;

}

contract DealsSupport is IDealsSupport {
  using SafeMath for uint;

  address public adminAddress;
  address public merchantAddress;

  mapping(uint => Affiliate) public affiliates;
  uint public affiliatesCount;

  mapping(uint => Deal) public deals;
  uint public dealsCount;

  mapping(address => uint[]) public affiliateDealIndexes;
  mapping(address => uint) public affiliateDealIndexesCount;

  mapping(uint => mapping(address => uint)) public dealAffiliateReferenceHash;
  mapping(uint => mapping(address => uint)) public dealAffiliateReferenceHashCount;
  mapping(uint => uint) public referenceHashDealIndex;

  event ApproveAffiliate(bytes4 _dealId, address indexed _merchantAddress, uint indexed _dealIndex, address indexed _affiliateAddress, uint _referenceHash);
  event CreateDeal(bytes4 _dealId, uint _dealIndex, address indexed _merchantAddress, address indexed _rewardTokenAddress, uint _rewardRatePpm, uint _daysOfCancellation, uint _daysBeforeClose, uint _dealsCount);
  event ToggleBlockAffiliate(bytes4 _dealId, uint _referenceHash, bool _isBlocked);
  event DealCancelled(bytes4 _dealId, uint _days, address _who);
  event StakeFilled(bytes4 _dealId, uint _fill, uint _left);
  event RewardClaimed(bytes4 _dealId, uint _referenceHash, uint _rewardAmount);
  event DealUpdated(bytes4 _dealId, uint _newRewardRatePpm);
  event RewardCreated(bytes4 _dealId, uint _referenceHash, uint _purchasedTokenAmount, uint _rewardAmount);

  struct Affiliate {
    address affiliateAddress;
    bool isBlocked;
    uint rewardAmount;
    uint affiliateRewardsCount;
    mapping(uint => AffiliateReward) affiliateRewards;
  }

  struct AffiliateReward {
    uint amount;
    uint createdAt;
  }

  struct Deal {
    address rewardTokenAddress;
    bool isCancelled;
    bool isCancelRequestedByMerchant;
    uint rewardRatePpm;
    uint daysOfCancellation;
    uint daysBeforeClose;
    uint createdAt;
    uint cancelRequestedAt;
    uint leftStakeAmount;
    uint affiliatesCount;
    uint lockedTokensAmount;
    uint[] referenceHashes;

    bytes4 dealId;
    bool allowAdminToAddAffiliate;
  }

  /**
  * Modifiers
  */

  /**
  * Checks that deal is still active, not cancelled or closed
  */
  modifier activeDeal(uint _dealIndex) {
    require(!isDealCancelled(_dealIndex),"Deal is cancelled.");
    require(!isDealClosed(_dealIndex),"Deal is closed.");
    _;
  }

  /**
  * Checks that method is called by admin
  */
  modifier onlyAdmin() {
    require(msg.sender == adminAddress, "Admin rights required.");
    _;
  }

  /**
  * Checks that method is called by merchant
  */
  modifier onlyMerchant() {
    require(msg.sender == merchantAddress, "Merchant rights required.");
    _;
  }

  /**
  * Modifier checks that deal exists
  */
  modifier validDealIndex(uint _dealIndex) {
    require(_dealIndex < dealsCount, "That deal index does not exist.");
    _;
  }

  /**
  * Modifier checks that affiliate exists
  */
  modifier validReferenceHash(uint _referenceHash) {
    // _referenceHash == 0 is reserved for usage in invest() method to distinguish whether user came from affiliate, so _referenceHash == 0 means that user didn't come from any affiliate
    require(_referenceHash != 0, "referenceHash can not be 0");
    require(_referenceHash <= affiliatesCount, "That referenceHash does not exist");
    _;
  }

  /**
  * @dev Contract constructor
  * @param _adminAddress admin address
  * @param _merchantAddress merchant address
  */
  constructor(address _adminAddress, address _merchantAddress) public {
    // validation
    require(_adminAddress != address(0), "Admin address can not be 0.");
    require(_merchantAddress != address(0), "Merchant address can not be 0.");
    // set contract properties
    adminAddress = _adminAddress;
    merchantAddress = _merchantAddress;
    // start affiliate reference hashes from 1 because 0 reference hash is used in invest() to detect whether user has come from affiliate or not
    affiliatesCount = 0;
  }

  /**
  * Public methods
  */

  /**
  * @dev Checks whether a deal can be cancelled by merchant
  * @param _dealIndex deal index
  * @return whether a deal can be cancelled by merchant
  */
  function canBeCancelledByMerchant(uint _dealIndex) public view validDealIndex(_dealIndex) returns(bool) {
    bool canBeCancelled = true;
    if (deals[_dealIndex].isCancelled || deals[_dealIndex].isCancelRequestedByMerchant) {
      canBeCancelled = false;
    }
    return canBeCancelled;
  }

  /**
  * @dev convert Deal ID -> Deal index.
  * @param _dealId deal ID
  * @return dealIndex
  */
  function dealIdToIndex(bytes4 _dealId) public view returns(uint) {
    for (uint i = 0; i<dealsCount; i++) {
      if (deals[i].dealId == _dealId) {
        return i;
      }
    }
    revert("dealID not found");
  }

  /**
  * @dev convert Deal index -> Deal ID
  * @param _dealIndex deal index
  * @return dealId
  */
  //Should
  function dealIndexToId(uint _dealIndex) public view returns(bytes4) {
    return deals[_dealIndex].dealId;
  }

  /**
  * @dev Returns affiliate reward info
  * @param _referenceHash affiliate's reference hash(index)
  * @param _affiliateRewardIndex affiliate reward index
  * @return affiliate reward info
  */
  function getAffiliateRewardInfo(uint _referenceHash, uint _affiliateRewardIndex) public view validReferenceHash(_referenceHash) returns(uint, uint) {
    require(_affiliateRewardIndex < affiliates[_referenceHash].affiliateRewardsCount, "affiliateRewardIndex does not exist.");
    AffiliateReward memory affiliateReward = affiliates[_referenceHash].affiliateRewards[_affiliateRewardIndex];
    return (
      affiliateReward.amount,
      affiliateReward.createdAt
    );
  }

  /**
  * @dev Returns deal index by reference hash
  * @param _referenceHash affiliate's reference hash(index)
  * @return deal index
  */
  function getDealIndex(uint _referenceHash) public view validReferenceHash(_referenceHash) returns(uint) {
    return referenceHashDealIndex[_referenceHash];
  }

  /**
  * @dev Returns array of deal indexes where provided affiliate takes part
  * @param _affiliateAddress affiliate address
  * @return array of deal indexes
  */
  function getDealIndexesByAffiliate(address _affiliateAddress) public view returns(uint[]) {
    require(_affiliateAddress != address(0), "affiliateAddress can not be 0.");
    return affiliateDealIndexes[_affiliateAddress];
  }

  /**
  * @dev Returns dynamic deal info: reference hashes.
  * @param _dealIndex deal index
  * @return array of reference hashes in deal
  */
  function getDynamicDealInfo(uint _dealIndex) public view validDealIndex(_dealIndex) returns(uint[]) {
    return deals[_dealIndex].referenceHashes;
  }

  /**
  * @dev Returns reference hash that should be passed in reference links
  * @param _dealIndex deal index
  * @param _affiliateAddress affiliate address
  * @return reference hash
  */
  function getReferenceHash(uint _dealIndex, address _affiliateAddress) public view validDealIndex(_dealIndex) returns(uint) {
    // validation
    require(_affiliateAddress != address(0), "affiliateAddress can not be 0.");
    require(dealAffiliateReferenceHashCount[_dealIndex][_affiliateAddress] == 1, "dealAffiliateReferenceHash does not exist.");
    // return reference hash
    return dealAffiliateReferenceHash[_dealIndex][_affiliateAddress];
  }

  /**
  * @dev Returns reference hash info: affiliate address and deal index
  * @param _referenceHash affiliate's reference hash(index)
  * @return affiliate address and deal index
  */
  function getReferenceHashInfo(uint _referenceHash) public view validReferenceHash(_referenceHash) returns (address, uint) {
    return (
      affiliates[_referenceHash].affiliateAddress,
      referenceHashDealIndex[_referenceHash]
    );
  }

  /**
  * @dev Checks whether deal is cancelled
  * @param _dealIndex deal index
  * @return bool whether deal is cancelled
  */
  function isDealCancelled(uint _dealIndex) public view validDealIndex(_dealIndex) returns(bool) {
    bool isCancelled = false;
    Deal memory deal = deals[_dealIndex];
    if (deal.isCancelled) {
      isCancelled = true;
    }
    if (deal.isCancelRequestedByMerchant && ((now - deal.cancelRequestedAt) >= (deal.daysOfCancellation * 24 * 60 * 60))) {
      isCancelled = true;
    }
    return isCancelled;
  }

  /**
  * @dev Checks whether deal is closed
  * @param _dealIndex deal index
  * @return bool whether deal is closed
  */
  function isDealClosed(uint _dealIndex) public view validDealIndex(_dealIndex) returns(bool) {
    bool isClosed = false;
    Deal memory deal = deals[_dealIndex];
    if ((now - deal.createdAt) >= (deal.daysBeforeClose * 24 * 60 * 60)) {
      isClosed = true;
    }
    return isClosed;
  }

  /**
  * Admin methods
  */

  /**
  * @dev Blocks/unblocks affiliate. As an admin i would like to block the selected affiliate.
  * @param _referenceHash affiliate's reference hash(index)
  */
  function toggleBlockAffiliate(uint _referenceHash) public onlyAdmin validReferenceHash(_referenceHash) {
    affiliates[_referenceHash].isBlocked = !affiliates[_referenceHash].isBlocked;
    bytes4 dealId = deals[referenceHashDealIndex[_referenceHash]].dealId;
    emit ToggleBlockAffiliate(dealId, _referenceHash, affiliates[_referenceHash].isBlocked);
  }

  /**
  * @dev Cancells deal immediately. As an admin I would like to immediately cancel the selected deal in order to prevent fraudulent behaviour.
  * @notice Will immediately move the selected deal into 'cancelled' state
  * @param _dealIndex deal index
  */
  function cancelDealByAdmin(uint _dealIndex) public onlyAdmin validDealIndex(_dealIndex) {
    deals[_dealIndex].isCancelled = true;
    emit DealCancelled(deals[_dealIndex].dealId, deals[_dealIndex].daysOfCancellation, msg.sender);
  }

  /**
  * @dev Changes admin address(transfer ownership)
  * @param _newAdminAddress new admin address
  */
  function changeAdmin(address _newAdminAddress) public onlyAdmin {
    require(_newAdminAddress != address(0), "newAdmin can not be 0.");
    adminAddress = _newAdminAddress;
  }

  /**
  * Affiliate methods
  */

  /**
  * @dev Withdraws a reward by affiliate. As an affiliate i would like to get my reward for the selected deal in order to get money.
  * Preconditions:
  *  1. The Deal index is valid.
  *  2. Affiliate is not blocked.
  *  3. The reward amount is non zero for the selected affiliate.
  *  4. The reward amount is non zero for the selected deal.
  * @param _dealIndex deal index
  * Result:
  *   All reward tokens are transferred from the current MultistageCrowdsale contract to the affiliate.
  *   The reward amount for the selected affiliate is set to zero.
  *   The reward amount for the selected deal is decreased.
  */
  function getMyReward(uint _dealIndex) public validDealIndex(_dealIndex) {
    // validation
    uint referenceHash = getReferenceHash(_dealIndex, msg.sender);
    require(!affiliates[referenceHash].isBlocked, "Affiliate is blocked.");
    require(affiliates[referenceHash].rewardAmount > 0, "rewardAmount for the affiliate is 0.");
    require(deals[_dealIndex].leftStakeAmount >= affiliates[referenceHash].rewardAmount, "There is not enough stake to pay the reward.");
    // update deal properties
    deals[_dealIndex].leftStakeAmount = deals[_dealIndex].leftStakeAmount.sub(affiliates[referenceHash].rewardAmount);
    // transfer reward tokens to affiliate
    uint tokenAmountToTransfer = affiliates[referenceHash].rewardAmount;
    affiliates[referenceHash].rewardAmount = 0;
    deals[_dealIndex].lockedTokensAmount = deals[_dealIndex].lockedTokensAmount.sub(tokenAmountToTransfer);
    ERC20(deals[_dealIndex].rewardTokenAddress).transfer(affiliates[referenceHash].affiliateAddress, tokenAmountToTransfer);
    emit RewardClaimed(deals[_dealIndex].dealId, referenceHash, tokenAmountToTransfer);
  }

  /**
  * Merchant methods
  */

  /**
  * @dev Approves affiliate address for deal. As a merchant i would like to manually approve selected affiliate in order to provide incentives.
  * @notice The same affiliate address can have different reference hashes because the same affiliate address can participate in multiple deals.
  * @param _dealIndex deal index
  * @param _affiliateAddress affiliate address
  */
  function approveAffiliate(uint _dealIndex, address _affiliateAddress) public validDealIndex(_dealIndex) activeDeal(_dealIndex) {
    if (!deals[_dealIndex].allowAdminToAddAffiliate) {
      require(msg.sender == merchantAddress, "Merchant permission required.");
    } else {
      require((msg.sender == adminAddress) || (msg.sender == merchantAddress), "Admin or merchant permission required.");
    }
    // validation
    require(_affiliateAddress != address(0), "affiliateAddress can not be 0.");
    // check that affiliate is not yet approved for this deal
    require(dealAffiliateReferenceHashCount[_dealIndex][_affiliateAddress] == 0, "Affiliate is already approved for this deal.");
    // create affiliate
    Affiliate memory affiliate;
    affiliate.affiliateAddress = _affiliateAddress;
    // add affiliate to global affiliates property
    affiliatesCount = affiliatesCount.add(1);
    affiliates[affiliatesCount] = affiliate;
    // add affliate to deal
    uint _referenceHash = affiliatesCount;
    deals[_dealIndex].referenceHashes.push(_referenceHash);
    deals[_dealIndex].affiliatesCount = deals[_dealIndex].affiliatesCount.add(1);
    // add deal to affiliate
    affiliateDealIndexes[_affiliateAddress].push(_dealIndex);
    affiliateDealIndexesCount[_affiliateAddress] = affiliateDealIndexesCount[_affiliateAddress].add(1);
    // update globals affiliates count
    dealAffiliateReferenceHash[_dealIndex][_affiliateAddress] = affiliatesCount;
    dealAffiliateReferenceHashCount[_dealIndex][_affiliateAddress] = 1;
    referenceHashDealIndex[affiliatesCount] = _dealIndex;
    // emitting event
    emit ApproveAffiliate(deals[_dealIndex].dealId, msg.sender, _dealIndex, _affiliateAddress, _referenceHash);
  }

  /**
  * @dev Cancels all deals by merchant
  */
  function cancelAllDealsByMerchant() public onlyMerchant {
    for (uint i = 0; i < dealsCount; i++) {
      if (canBeCancelledByMerchant(i)) {
        cancelDealByMerchant(i);
        emit DealCancelled(deals[i].dealId, deals[i].daysOfCancellation, msg.sender);
      }
    }
  }

  /**
  * @dev Marks deal to be cancelled by merchant. As a merchant I would like to request a deal cancelation in order to cancel it after “Cancelation period” is elapsed.
  * @param _dealIndex deal index
  */
  function cancelDealByMerchant(uint _dealIndex) public onlyMerchant validDealIndex(_dealIndex) {
    // validation
    require(canBeCancelledByMerchant(_dealIndex),"Deal can not be cancelled by merchant.");
    // mark deal to be cancelled
    deals[_dealIndex].isCancelRequestedByMerchant = true;
    deals[_dealIndex].cancelRequestedAt = now;
    if (deals[_dealIndex].daysOfCancellation == 0) {
      deals[_dealIndex].isCancelled = true;
    }
    emit DealCancelled(deals[_dealIndex].dealId, deals[_dealIndex].daysOfCancellation, msg.sender);
  }

  /**
  * @dev Creates a new deal by merchant. As a merchant i would like to create new deal in order to add incentives for affiliates.
  * @param _dealId deal dealId
  * @param _rewardTokenAddress ERC20 token address used for affiliates' rewards
  * @param _rewardRatePpm reward rate ppm, 100% == 1000000
  * @param _daysOfCancellation when deal is marked as cancelled it is still live for _daysOfCancellation number of days
  * @param _daysBeforeClose number of days since deal creation when deal is still live, the deal is over and any left over staked tokens can be withdrawn by merchant
  */

  function createDeal(bytes4 _dealId, address _rewardTokenAddress, uint _rewardRatePpm, uint _daysOfCancellation, uint _daysBeforeClose, bool _allowAdminToAddAffiliate) public onlyMerchant {
    // validation
    require(_rewardTokenAddress != address(0), "rewardTokenAddress can not be 0.");
    require(_rewardRatePpm > 0, "rewardRatePpm can not be 0.");
    require(_daysOfCancellation <= 90,"daysOfCancellation can not be >90.");
    require(_daysBeforeClose > 0, "daysBeforeClose should be >0.");
    require(_daysBeforeClose <= 365, "daysBeforeClose can not be >365.");
    // create a new deal
    Deal memory deal;
    deal.dealId = _dealId;
    deal.rewardTokenAddress = _rewardTokenAddress;
    deal.rewardRatePpm = _rewardRatePpm;
    deal.daysOfCancellation = _daysOfCancellation;
    deal.daysBeforeClose = _daysBeforeClose;
    deal.createdAt = now;
    deal.allowAdminToAddAffiliate = _allowAdminToAddAffiliate;
    deals[dealsCount] = deal;

    // update contract properties
    dealsCount = dealsCount.add(1);
    // emitting event

    emit CreateDeal(_dealId, dealsCount - 1, msg.sender, _rewardTokenAddress, _rewardRatePpm, _daysOfCancellation, _daysBeforeClose, dealsCount);
  }

  /**
  * @dev Stakes ERC20 tokens as reward for affiliates by merchant. As a merchant i would like to transfer ERC20 tokens to the selected deal in order to stake them.
  * @notice Merchant should allow _amount of tokens to be withdrawn (use ERC20.approve() method) BEFORE calling this method.
  * Preconditions:
  *  1. The Deal was created by Merchant before
  *  2. isCancelled == false
  *  3. isClosed == false
  *  4. Merchant allowed current MultistageCrowdsale to withdraw correct amount of tokens
  * @param _dealIndex deal index
  * @param _amount amount in wei
  */
  function fillStake(uint _dealIndex, uint _amount) public onlyMerchant validDealIndex(_dealIndex) activeDeal(_dealIndex) {
    // validation
    require(_amount > 0, "amount should be >0.");
    ERC20 rewardToken = ERC20(deals[_dealIndex].rewardTokenAddress);
    require(rewardToken.allowance(msg.sender, address(this)) >= _amount, "Allowance is not enough to send the required amount.");
    // stake tokens for affiliates' rewards
    deals[_dealIndex].leftStakeAmount = deals[_dealIndex].leftStakeAmount.add(_amount);
    rewardToken.transferFrom(msg.sender, address(this), _amount);
    emit StakeFilled(deals[_dealIndex].dealId, _amount, deals[_dealIndex].leftStakeAmount);
  }

  /**
  * @dev Returns tokens at stake back to merchant if deal is cancelled. As a merchant i would like to get my stake back in order to get my tokens back (if deal is cancelled).
  * Preconditions:
  *  1. The Deal was created by Merchant before.
  *  2. The Deal isCancelled==true.
  *  3. The Deal still has some stake left.
  *  4. The Deal has enough tokens to pay to all affiliates.
  * @param _dealIndex deal index
  * Result:
  *    All staked reward tokens are transferred from the current MultistageCrowdsale contract back to merchant.
  *    The “Current reward stake amount” of the selected Deal is decreased.
  */
  function getMyStakeBack(uint _dealIndex) public onlyMerchant validDealIndex(_dealIndex) {
    // validation
    require(isDealCancelled(_dealIndex), "Deal is not cancelled.");
    require(deals[_dealIndex].leftStakeAmount > 0, "There is no stake left.");
    require(deals[_dealIndex].leftStakeAmount >= deals[_dealIndex].lockedTokensAmount, "Stake is lower than lockedTokensAmount.");
    // transfer ERC20 tokens back to merchant
    uint tokenAmountToWithdraw = deals[_dealIndex].leftStakeAmount - deals[_dealIndex].lockedTokensAmount;
    deals[_dealIndex].leftStakeAmount = deals[_dealIndex].lockedTokensAmount;
    ERC20(deals[_dealIndex].rewardTokenAddress).transfer(msg.sender, tokenAmountToWithdraw);
  }

  /**
  * @dev Updates a deal by merchant
  * @param _dealIndex deal index
  * @param _newRewardRatePpm new reward rate ppm, 100% == 1000000
  */
  function updateDeal(uint _dealIndex, uint _newRewardRatePpm) public onlyMerchant validDealIndex(_dealIndex) activeDeal(_dealIndex) {
    require(_newRewardRatePpm > 0, "_newRewardRatePpm should be >0.");
    deals[_dealIndex].rewardRatePpm = _newRewardRatePpm;
    emit DealUpdated(deals[_dealIndex].dealId, _newRewardRatePpm);
  }

  /**
  * Internal methods
  */

  /**
  * @dev Increases affiliate's reward amount
  * @param _referenceHash affiliate's reference hash(index/referenceHash that is passed to invest() function)
  */
  function _rewardAffiliate(uint _referenceHash, uint _purchasedTokenAmount) internal validReferenceHash(_referenceHash) {
    // get deal index by reference hash
    uint dealIndex = getDealIndex(_referenceHash);
    // calculate reward amount for affiliate
    uint rewardAmount = _purchasedTokenAmount.div(1000000).mul(deals[dealIndex].rewardRatePpm);
    // add affiliate reward to affiliate
    AffiliateReward memory affiliateReward;
    affiliateReward.amount = rewardAmount;
    affiliateReward.createdAt = now;
    affiliates[_referenceHash].affiliateRewards[affiliates[_referenceHash].affiliateRewardsCount] = affiliateReward;
    affiliates[_referenceHash].affiliateRewardsCount = affiliates[_referenceHash].affiliateRewardsCount.add(1);
    // update affiliate reward amount
    affiliates[_referenceHash].rewardAmount = affiliates[_referenceHash].rewardAmount.add(rewardAmount);
    // update deal's locked token balance
    deals[dealIndex].lockedTokensAmount = deals[dealIndex].lockedTokensAmount.add(rewardAmount);
    emit RewardCreated(dealIndexToId(dealIndex), _referenceHash, _purchasedTokenAmount, rewardAmount);
  }

}

contract MultistageCrowdsale is DealsSupport, Ownable {
    using SafeMath for uint256;

    /**
     * Event for token purchase logging
     * @param purchaser who paid for the tokens
     * @param affiliate address, if any
     * @param value weis paid for purchase
     * @param amount amount of tokens purchased
     * @param orderID to be used with fiat payments
     */
    event TokenPurchase(address indexed purchaser, address indexed affiliate, uint256 value, uint256 amount, bytes4 indexed orderID);

    struct Stage {
        uint32 time;
        uint64 rate;
        uint256 minInv;
        uint256 maxInv;
    }

    struct Timelock {
        uint256 timestamp;
        uint8 amount;
        uint8 relative;
    }

    Stage[] stages;
    Timelock[] timeLocks;

    mapping(address => uint256) invested;

    address wallet;
    address token;
    address signer;
    uint32 saleEndTime;
    bool tokenIsTILM;

    /**
     * @dev The constructor that takes all parameters
     * @param _timesAndRates An array that defines the stages of the contract. the first entry being the start time of the sale, followed by pairs of rates ond close times of consequitive stages.
     *             Example 1: [10000, 99, 12000]
     *                 A single stage sale that starts at unix time 10000 and ends 2000 seconds later.
     *                 This sale gives 99 tokens for each Gwei invested.
     *             Example 2: [10000, 99, 12000, 88, 14000]
     *                 A 2 stage sale that starts at unix time 10000 and ends 4000 seconds later.
     *                 The sale reduces the rate at mid time
     *                 This sale gives 99 tokens for each Gwei invested in first stage.
     *                 The sale gives 88 tokens for each Gwei invested in second stage.
     * @param _wallet The address of the wallet where invested Ether will be send to
     * @param _token The tokens that the investor will receive
     * @param _signer The address of the key that whitelists investor (operator key)
     */
    constructor(
        uint256[] _timesAndRates,
        address _wallet,
        address _token,
        address _signer,
        address _admin,
        address _merchant
    )
        public
        DealsSupport(_admin, _merchant)
    {
        require(_wallet != address(0), "Wallet address can not be 0.");
        require(_token != address(0), "Token address can not be 0.");

        storeStages(_timesAndRates);

        saleEndTime = uint32(_timesAndRates[_timesAndRates.length - 1]);
        // check sale ends after last stage opening time
        require(saleEndTime > stages[stages.length - 1].time, "Sale end time should be after last stage opening time.");

        wallet = _wallet;
        token = _token;
        signer = _signer;
        tokenIsTILM = false;
    }

    function setTokenIsTilm(bool _isTilm) public onlyOwner {
        require(tokenIsTILM != _isTilm, "That is the current tokenIsTILM status");
        tokenIsTILM = _isTilm;
    }

    function getTokenIsTilm() public view returns (bool isTilm) {
        return (tokenIsTILM);
    }

    function setTimelockLogic(uint256[] _timeLocks) public onlyOwner {
        require(_timeLocks.length % 3 == 0, "Wrong number of parameters in timeLocks.");
        delete timeLocks;
        for (uint256 i = 0; i < _timeLocks.length / 3; i++) {
            require(_timeLocks[(i * 3) + 2]==0 || _timeLocks[(i * 3) + 2]==1, "Only 0 or 1 are valid values for relative flag");
            timeLocks.push(Timelock(uint256(_timeLocks[i * 3]), uint8(_timeLocks[(i * 3) + 1]), uint8(_timeLocks[(i * 3) + 2])));
        }
    }

    function getTimelockLogic() public view returns (uint256[] _timeLocks) {
        _timeLocks = new uint256[](timeLocks.length * 3);
        for (uint256 i = 0; i < timeLocks.length; i++) {
            _timeLocks[i * 3] = uint256(timeLocks[i].timestamp);
            _timeLocks[i * 3 + 1] = uint256(timeLocks[i].amount);
            _timeLocks[i * 3 + 2] = uint256(timeLocks[i].relative);
        }
        return (_timeLocks);
    }

    function setMinInvestmentAtStage(uint32 _stage, uint256 _value) public onlyOwner {
        require(_stage < stages.length, "Stage does not exist");
        require(_value != getMinInvAtStage(_stage),"That is the current minimum investment");
        require(getMaxInvAtStage(_stage) == 0 || _value <= getMaxInvAtStage(_stage),"Minimum should be lower than the maximum investment when it is not 0");
        stages[_stage].minInv = _value;
    }

    function setMaxInvestmentAtStage(uint32 _stage, uint256 _value) public onlyOwner {
        require(_stage < stages.length, "Stage does not exist");
        require(_value != getMaxInvAtStage(_stage),"That is the current minimum investment");
        require(_value == 0 || _value >= getMinInvAtStage(_stage),"Maximum should be either 0, or higher than the minimum investment");
        stages[_stage].maxInv = _value;
    }

    /**
     * @dev called by investors to purchase tokens
     * @param _r part of receipt signature
     * @param _s part of receipt signature
     * @param _a first payload of signed receipt.
     * @param _b second payload of signed receipt.
     *     The receipt commits to the follwing inputs:
     *         56 bits - sale contract address, to prevent replay of receipt
     *         32 bits - orderID for fiat payments
     *         160 bits - beneficiary address - address whitelisted to receive tokens
     *         32 bits - time - when receipt was signed
     *         64 bits - outOfBandPaymentAmount - out of band payment amount, for fiat investments
     *         32 bits - reference hash
     */

    function invest(bytes32 _r, bytes32 _s, bytes32 _a, bytes32 _b) public payable {
        // parse inputs
        uint32 time = uint32(_b >> 224);
        address beneficiary = address(_a);
        uint256 outOfBandPaymentAmount = uint64(_b >> 160);
        uint256 referenceHash = uint256(_b << 96 >> 224);

        // verify inputs
        require(uint56(_a >> 192) == uint56(this), "Destination contract address does not match this contract address.");
        if (outOfBandPaymentAmount == 0) {
            outOfBandPaymentAmount = msg.value;
        } else {
            outOfBandPaymentAmount = outOfBandPaymentAmount.mul(1000000000);    // convert outOfBandPaymentAmount to wei
        }
        bytes4 orderID = bytes4(uint32(_a >> 160));
        /* solium-disable-next-line arg-overflow */
        require(ecrecover(keccak256(abi.encodePacked(uint8(0), uint248(_a), _b)), uint8(_a >> 248), _r, _s) == signer, "Signer address not matching.");
        require(beneficiary != address(0), "Beneficiary can not be 0.");

        // check investment is above current minimum investment
        require(outOfBandPaymentAmount>=getMinInvAt(now),"Investment below minimum required");
        // check investment is under above current maximum investment
        require(outOfBandPaymentAmount+invested[beneficiary]<=getMaxInvAt(now) || getMaxInvAt(now)==0,"Investment over maximum allowed in current stage");
        // calculate token amount to be created
        uint256 rate = getRateAt(now); // solium-disable-line security/no-block-members
        // at the time of signing the receipt the rate should have been the same as now
        require(rate == getRateAt(time), "rate not matching current stage rate.");
        // multiply rate with Gwei of investment
        // uint256 purchasedTokenAmount = rate.mul(outOfBandPaymentAmount).div(1000000000);
        // multiply rate with Gwei of investment and ceil to avoid weird amounts
        uint256 purchasedTokenAmount = ceil(rate.mul(outOfBandPaymentAmount).div(1000000000), 10**3);
        // check that msg.value > 0
        require(purchasedTokenAmount > 0, "purchasedTokenAmount can not be 0.");

        // pocket Ether
        if (msg.value > 0) {
            wallet.transfer(outOfBandPaymentAmount);
        }

        // if user came from affiliate then reward affiliate
        address affiliate = address(0);
        if (referenceHash != 0) {
            affiliate = affiliates[referenceHash].affiliateAddress;
            _rewardAffiliate(referenceHash, purchasedTokenAmount);
        }

        // do token transfer
        invested[beneficiary] += outOfBandPaymentAmount;
        // send tokens and emit event
        sendTokens(beneficiary, purchasedTokenAmount);
        emit TokenPurchase(beneficiary, affiliate, outOfBandPaymentAmount, purchasedTokenAmount, orderID);
    }

    function sendTokens(address _beneficiary, uint256 _amount) internal {
        // if the token is not TILM or the logic is not defined, normal transfer
        if(!tokenIsTILM || timeLocks.length == 0) {
            ERC20(token).transferFrom(wallet, _beneficiary, _amount);
        } else {
            // transfer and lock according to logic defined in variables "amounts" and "locktimes"
            uint256[] memory purchasedLockAmounts = new uint256[](timeLocks.length);
            uint256[] memory lockTimes = new uint256[](timeLocks.length);
            for(uint256 i = 0; i<timeLocks.length; i++){
                purchasedLockAmounts[i] = _amount * timeLocks[i].amount / 100;
                lockTimes[i] = timeLocks[i].relative * now + timeLocks[i].timestamp;
            }
            LockedController(token).transferListOfLockedFundsFrom(wallet, _beneficiary, purchasedLockAmounts, lockTimes);
        }
    }

    function getParams() public view returns (uint256[] _times, uint256[] _rates, uint256[] _minInvs, uint256[] _maxInvs, address _wallet, address _token, address _signer) {
        _times = new uint256[](stages.length + 1);
        _rates = new uint256[](stages.length);
        _minInvs = new uint256[](stages.length);
        _maxInvs = new uint256[](stages.length);
        for (uint256 i = 0; i < stages.length; i++) {
            _times[i] = stages[i].time;
            _rates[i] = stages[i].rate;
            _minInvs[i] = stages[i].minInv;
            _maxInvs[i] = stages[i].maxInv;
        }
        _times[stages.length] = saleEndTime;
        _wallet = wallet;
        _token = token;
        _signer = signer;
    }

    function storeStages(uint256[] _timesAndRates) internal {
        // check odd amount of array elements, groups of time, rate, minInv and maxInv + saleEndTime
        require(_timesAndRates.length % 4 == 1, "Wrong number of parameters in times and rates.");
        // check that at least 1 stage provided
        require(_timesAndRates.length >= 5, "There should be at least 1 complete stage, check number of parameters.");

        for (uint256 i = 0; i < _timesAndRates.length / 4; i++) {
            require(uint64(_timesAndRates[(i * 4) + 3]) == 0 || uint64(_timesAndRates[(i * 4) + 2]) <= uint64(_timesAndRates[(i * 4) + 3]), "Maximum should be higher than minimum, or 0");
            stages.push(Stage(uint32(_timesAndRates[i * 4]), uint64(_timesAndRates[(i * 4) + 1]), uint64(_timesAndRates[(i * 4) + 2]), uint64(_timesAndRates[(i * 4) + 3])));
            if (i > 0) {
                // check that each time higher than previous time
                require(stages[i-1].time < stages[i].time, "Starting time should be higher than previous stage starting time.");
                // check that each rate is lower than previous rate
                require(stages[i-1].rate > stages[i].rate, "rate can not be higher than previous stage rate.");
            }
        }

        // check that opening time in the future
        require(stages[0].time > now, "Sale start time should be in the future."); // solium-disable-line security/no-block-members

        // check final rate > 0
        require(stages[stages.length - 1].rate > 0, "Final rate can not be 0.");
    }

    function getStartTimeAtStage (uint256 _stage) public view returns (uint256 time) {
        // if before first stage, return 0
        require(_stage < stages.length, "Stage does not exist");
        return stages[_stage].time;
    }

    function updateStartTimeAtStage (uint256 _stage, uint256 _newTime) public onlyOwner {
        // if before first stage, return 0
        require(_stage < stages.length, "Stage does not exist");
        require(_newTime != getStartTimeAtStage(_stage),"That is the current time");
        require(_newTime > now,"That newTime is in the past");
        // check that each rate is lower than previous rate
        if (_stage > 0) {
            require(getStartTimeAtStage(_stage-1) > _newTime, "New start time can not be before previous stage start time.");
        }
        stages[_stage].time = uint32(_newTime);
    }

    function getRateAt(uint256 _now) internal view returns (uint256 rate) {
        // if before first stage, return 0
        if (_now < stages[0].time) {
            return 0;
        }
        for (uint i = 1; i < stages.length; i++) {
            if (_now < stages[i].time)
                return stages[i - 1].rate;
        }
        // handle last stage
        if (_now < saleEndTime)
            return stages[stages.length - 1].rate;
        // sale already closed
        return 0;
    }

    function getRateAtStage (uint256 _stage) public view returns (uint256 rate) {
        // if before first stage, return 0
        require(_stage < stages.length, "Stage does not exist");
        return stages[_stage].rate;
    }

    function updateRateAtStage (uint256 _stage, uint256 _newRate) public onlyOwner {
        // if before first stage, return 0
        require(_stage < stages.length, "Stage does not exist");
        require(_newRate != getRateAtStage(_stage),"That is the current rate");
        // check that each rate is lower than previous rate
        if (_stage > 0) {
            require(getRateAtStage(_stage-1) > _newRate, "New rate can not be higher than previous stage rate.");
        }
        stages[_stage].rate = uint64(_newRate);
    }

    function getMinInvAt(uint256 _now) public view returns (uint256 inv) {
        // if before first stage, return 0
        require(_now >= stages[0].time, "Sale not started");
        require(_now < saleEndTime, "Sale finished");

        for (uint i = 1; i < stages.length; i++) {
            if (_now < stages[i].time)
                return stages[i - 1].minInv;
        }

        // handle last stage
        if (_now < saleEndTime)
            return stages[stages.length - 1].minInv;
    }

    function getMinInvAtStage(uint32 _stage) public view returns (uint256 inv) {
        require(_stage < stages.length, "Stage does not exist");
        return stages[_stage].minInv;
    }

    function getMaxInvAt(uint256 _now) public view returns (uint256 inv) {
        // if before first stage, return 0
        require(_now >= stages[0].time, "Sale not started");
        require(_now < saleEndTime, "Sale finished");

        for (uint i = 1; i < stages.length; i++) {
            if (_now < stages[i].time)
                return stages[i - 1].maxInv;
        }

        // handle last stage
        if (_now < saleEndTime)
            return stages[stages.length - 1].maxInv;
    }

    function getMaxInvAtStage(uint32 _stage) public view returns (uint256 inv) {
        require(_stage < stages.length, "Stage does not exist");
        return stages[_stage].maxInv;
    }

    function ceil(uint _value, uint _dec) private pure returns (uint) {
        return((_value + _dec - 1) / _dec) * _dec;
    }
// Deals overrides:
    /*
    function isMerchant(address _a) public view returns(bool){
        // TODO: implement
        // Who is Merchnat in this case? Who deployed current contract or who owns current contract?
        return false;
    }
    */
}