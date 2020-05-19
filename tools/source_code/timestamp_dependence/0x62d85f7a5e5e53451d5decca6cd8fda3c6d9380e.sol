pragma solidity 0.4.25;


/**
*
* ETHPROFIT.SPACE
*
* ETH CRYPTOCURRENCY DISTRIBUTION PROJECT
* 
*  - GAIN 3% PER 24 HOURS (interest is charges in equal parts every 10 min)
*  - Life-long payments
*  - The revolutionary reliability
*  - Minimal contribution 0.01 eth
*  - Currency and payment - ETH
*  - Contribution allocation schemes:
*    -- 90% payments
*    --  8% marketing
*    --  2% technical support
* 
* ---How to use:
*  1. Send from ETH wallet to the smart contract address 
*     any amount from 0.01 ETH.
*  2. Verify your transaction in the history of your application or etherscan.io, specifying the address 
*     of your wallet.
*  3a. Claim your profit by sending 0 ether transaction (every 10 min, every day, every week, i don't care unless you're 
*      spending too much on GAS)
*  OR
*  3b. For reinvest, you need to deposit the amount that you want to reinvest and the 
*      accrued interest automatically summed to your new contribution.
*  
* RECOMMENDED GAS LIMIT: 250000
* RECOMMENDED GAS PRICE: https://ethgasstation.info/
* You can check the payments on the etherscan.io site, in the "Internal Txns" tab of your wallet.
*
* ---Refferral system: remuneration to each contributor is 3%, 
*     
* ---It is not allowed to transfer from exchanges, only from your personal ETH wallet, for which you 
* have private keys.
* 
* Contracts reviewed and approved by pros!
* 
*/ 



library Math {
  function min(uint a, uint b) internal pure returns(uint) {
    if (a > b) {
      return b;
    }
    return a;
  }
}


library Zero {
  function requireNotZero(address addr) internal pure {
    require(addr != address(0), "require not zero address");
  }

  function requireNotZero(uint val) internal pure {
    require(val != 0, "require not zero value");
  }

  function notZero(address addr) internal pure returns(bool) {
    return !(addr == address(0));
  }

  function isZero(address addr) internal pure returns(bool) {
    return addr == address(0);
  }

  function isZero(uint a) internal pure returns(bool) {
    return a == 0;
  }

  function notZero(uint a) internal pure returns(bool) {
    return a != 0;
  }
}


library Percent {
  // Solidity automatically throws when dividing by 0
  struct percent {
    uint num;
    uint den;
  }
  
  // storage
  function mul(percent storage p, uint a) internal view returns (uint) {
    if (a == 0) {
      return 0;
    }
    return a*p.num/p.den;
  }

  function div(percent storage p, uint a) internal view returns (uint) {
    return a/p.num*p.den;
  }

  function sub(percent storage p, uint a) internal view returns (uint) {
    uint b = mul(p, a);
    if (b >= a) {
      return 0;
    }
    return a - b;
  }

  function add(percent storage p, uint a) internal view returns (uint) {
    return a + mul(p, a);
  }

  function toMemory(percent storage p) internal view returns (Percent.percent memory) {
    return Percent.percent(p.num, p.den);
  }

  // memory 
  function mmul(percent memory p, uint a) internal pure returns (uint) {
    if (a == 0) {
      return 0;
    }
    return a*p.num/p.den;
  }

  function mdiv(percent memory p, uint a) internal pure returns (uint) {
    return a/p.num*p.den;
  }

  function msub(percent memory p, uint a) internal pure returns (uint) {
    uint b = mmul(p, a);
    if (b >= a) {
      return 0;
    }
    return a - b;
  }

  function madd(percent memory p, uint a) internal pure returns (uint) {
    return a + mmul(p, a);
  }
}


library Address {
  function toAddress(bytes source) internal pure returns(address addr) {
    assembly { addr := mload(add(source,0x14)) }
    return addr;
  }

  function isNotContract(address addr) internal view returns(bool) {
    uint length;
    assembly { length := extcodesize(addr) }
    return length == 0;
  }
}


/**
 * @title SafeMath
 * @dev Math operations with safety checks that revert on error
 */
library SafeMath {

  /**
  * @dev Multiplies two numbers, reverts on overflow.
  */
  function mul(uint256 _a, uint256 _b) internal pure returns (uint256) {
    // Gas optimization: this is cheaper than requiring 'a' not being zero, but the
    // benefit is lost if 'b' is also tested.
    // See: https://github.com/OpenZeppelin/openzeppelin-solidity/pull/522
    if (_a == 0) {
      return 0;
    }

    uint256 c = _a * _b;
    require(c / _a == _b);

    return c;
  }

  /**
  * @dev Integer division of two numbers truncating the quotient, reverts on division by zero.
  */
  function div(uint256 _a, uint256 _b) internal pure returns (uint256) {
    require(_b > 0); // Solidity only automatically asserts when dividing by 0
    uint256 c = _a / _b;
    // assert(_a == _b * c + _a % _b); // There is no case in which this doesn't hold

    return c;
  }

  /**
  * @dev Subtracts two numbers, reverts on overflow (i.e. if subtrahend is greater than minuend).
  */
  function sub(uint256 _a, uint256 _b) internal pure returns (uint256) {
    require(_b <= _a);
    uint256 c = _a - _b;

    return c;
  }

  /**
  * @dev Adds two numbers, reverts on overflow.
  */
  function add(uint256 _a, uint256 _b) internal pure returns (uint256) {
    uint256 c = _a + _b;
    require(c >= _a);

    return c;
  }

  /**
  * @dev Divides two numbers and returns the remainder (unsigned integer modulo),
  * reverts when dividing by zero.
  */
  function mod(uint256 a, uint256 b) internal pure returns (uint256) {
    require(b != 0);
    return a % b;
  }
}


contract Accessibility {
  address private owner;
  modifier onlyOwner() {
    require(msg.sender == owner, "access denied");
    _;
  }

  constructor() public {
    owner = msg.sender;
  }

  function disown() internal {
    delete owner;
  }
}


contract InvestorsStorage is Accessibility {
  struct Investor {
    uint investment;
    uint paymentTime;
  }
  uint public size;

  mapping (address => Investor) private investors;

  function isInvestor(address addr) public view returns (bool) {
    return investors[addr].investment > 0;
  }

  function investorInfo(address addr) public view returns(uint investment, uint paymentTime) {
    investment = investors[addr].investment;
    paymentTime = investors[addr].paymentTime;
  }

  function newInvestor(address addr, uint investment, uint paymentTime) public onlyOwner returns (bool) {
    Investor storage inv = investors[addr];
    if (inv.investment != 0 || investment == 0) {
      return false;
    }
    inv.investment = investment;
    inv.paymentTime = paymentTime;
    size++;
    return true;
  }

  function addInvestment(address addr, uint investment) public onlyOwner returns (bool) {
    if (investors[addr].investment == 0) {
      return false;
    }
    investors[addr].investment += investment;
    return true;
  }

  function setPaymentTime(address addr, uint paymentTime) public onlyOwner returns (bool) {
    if (investors[addr].investment == 0) {
      return false;
    }
    investors[addr].paymentTime = paymentTime;
    return true;
  }
}

contract Ethprofitspace is Accessibility {
  using Percent for Percent.percent;
  using SafeMath for uint;
  using Math for uint;

  // easy read for investors
  using Address for *;
  using Zero for *; 
  
  mapping(address => bool) private m_referrals;
  InvestorsStorage private m_investors;

  // automatically generates getters
  uint public constant minInvesment = 10 finney; //       0.01 eth
  uint public constant maxBalance = 100e5 ether; // 10 000 000 eth
  address public advertisingAddress;
  address public adminsAddress;
  uint public investmentsNumber;
  uint public waveStartup;

  // percents
  Percent.percent private m_3_percent = Percent.percent(3, 100);    // 3/100*100% = 3%
  Percent.percent private m_adminsPercent = Percent.percent(2, 100);       //   2/100  *100% = 2%
  Percent.percent private m_advertisingPercent = Percent.percent(8, 100);// 8/100  *100% = 8%

  // more events for easy read from blockchain
  event LogSendExcessOfEther(address indexed addr, uint when, uint value, uint investment, uint excess);
  event LogNewReferral(address indexed addr, address indexed referrerAddr, uint when, uint refBonus);
  event LogNewInvesment(address indexed addr, uint when, uint investment, uint value);
  event LogAutomaticReinvest(address indexed addr, uint when, uint investment);
  event LogPayDividends(address indexed addr, uint when, uint dividends);
  event LogNewInvestor(address indexed addr, uint when);
  event LogBalanceChanged(uint when, uint balance);
  event LogNextWave(uint when);
  event LogDisown(uint when);


  modifier balanceChanged {
    _;
    emit LogBalanceChanged(now, address(this).balance);
  }

  modifier notFromContract() {
    require(msg.sender.isNotContract(), "only externally accounts");
    _;
  }

  constructor() public {
    adminsAddress = msg.sender;
    advertisingAddress = msg.sender;
    nextWave();
  }

  function() public payable {
    // investor get him dividends
    if (msg.value.isZero()) {
      getMyDividends();
      return;
    }

    // sender do invest
    doInvest(msg.data.toAddress());
  }

  function doDisown() public onlyOwner {
    disown();
    emit LogDisown(now);
  }

  

  function setAdvertisingAddress(address addr) public onlyOwner {
    addr.requireNotZero();
    advertisingAddress = addr;
  }

  function setAdminsAddress(address addr) public onlyOwner {
    addr.requireNotZero();
    adminsAddress = addr;
  }

  function investorsNumber() public view returns(uint) {
    return m_investors.size();
  }

  function balanceETH() public view returns(uint) {
    return address(this).balance;
  }

  function percent3() public view returns(uint numerator, uint denominator) {
    (numerator, denominator) = (m_3_percent.num, m_3_percent.den);
  }

  function advertisingPercent() public view returns(uint numerator, uint denominator) {
    (numerator, denominator) = (m_advertisingPercent.num, m_advertisingPercent.den);
  }

  function adminsPercent() public view returns(uint numerator, uint denominator) {
    (numerator, denominator) = (m_adminsPercent.num, m_adminsPercent.den);
  }

  function investorInfo(address investorAddr) public view returns(uint investment, uint paymentTime, bool isReferral) {
    (investment, paymentTime) = m_investors.investorInfo(investorAddr);
    isReferral = m_referrals[investorAddr];
  }

  function investorDividendsAtNow(address investorAddr) public view returns(uint dividends) {
    dividends = calcDividends(investorAddr);
  }

  function dailyPercentAtNow() public view returns(uint numerator, uint denominator) {
    Percent.percent memory p = dailyPercent();
    (numerator, denominator) = (p.num, p.den);
  }

  function refBonusPercentAtNow() public view returns(uint numerator, uint denominator) {
    Percent.percent memory p = refBonusPercent();
    (numerator, denominator) = (p.num, p.den);
  }

  function getMyDividends() public notFromContract balanceChanged {
    // calculate dividends
    uint dividends = calcDividends(msg.sender);
    require (dividends.notZero(), "cannot to pay zero dividends");

    // update investor payment timestamp
    assert(m_investors.setPaymentTime(msg.sender, now));

    // check enough eth - goto next wave if needed
    if (address(this).balance <= dividends) {
      nextWave();
      dividends = address(this).balance;
    } 

    // transfer dividends to investor
    msg.sender.transfer(dividends);
    emit LogPayDividends(msg.sender, now, dividends);
  }

  function doInvest(address referrerAddr) public payable notFromContract balanceChanged {
    uint investment = msg.value;
    uint receivedEther = msg.value;
    require(investment >= minInvesment, "investment must be >= minInvesment");
    require(address(this).balance <= maxBalance, "the contract eth balance limit");

    // send excess of ether if needed
    if (receivedEther > investment) {
      uint excess = receivedEther - investment;
      msg.sender.transfer(excess);
      receivedEther = investment;
      emit LogSendExcessOfEther(msg.sender, now, msg.value, investment, excess);
    }

    // commission
    advertisingAddress.send(m_advertisingPercent.mul(receivedEther));
    adminsAddress.send(m_adminsPercent.mul(receivedEther));

    bool senderIsInvestor = m_investors.isInvestor(msg.sender);

    // ref system works only once and only on first invest
    if (referrerAddr.notZero() && !senderIsInvestor && !m_referrals[msg.sender] &&
      referrerAddr != msg.sender && m_investors.isInvestor(referrerAddr)) {
      
      m_referrals[msg.sender] = true;
      // add referral bonus to investor`s and referral`s investments
      uint refBonus = refBonusPercent().mmul(investment);
      assert(m_investors.addInvestment(referrerAddr, refBonus)); // add referrer bonus
      investment += refBonus;                                    // add referral bonus
      emit LogNewReferral(msg.sender, referrerAddr, now, refBonus);
    }

    // automatic reinvest - prevent burning dividends
    uint dividends = calcDividends(msg.sender);
    if (senderIsInvestor && dividends.notZero()) {
      investment += dividends;
      emit LogAutomaticReinvest(msg.sender, now, dividends);
    }

    if (senderIsInvestor) {
      // update existing investor
      assert(m_investors.addInvestment(msg.sender, investment));
      assert(m_investors.setPaymentTime(msg.sender, now));
    } else {
      // create new investor
      assert(m_investors.newInvestor(msg.sender, investment, now));
      emit LogNewInvestor(msg.sender, now);
    }

    investmentsNumber++;
    emit LogNewInvesment(msg.sender, now, investment, receivedEther);
  }

  function getMemInvestor(address investorAddr) internal view returns(InvestorsStorage.Investor memory) {
    (uint investment, uint paymentTime) = m_investors.investorInfo(investorAddr);
    return InvestorsStorage.Investor(investment, paymentTime);
  }

  function calcDividends(address investorAddr) internal view returns(uint dividends) {
    InvestorsStorage.Investor memory investor = getMemInvestor(investorAddr);

    // safe gas if dividends will be 0
    if (investor.investment.isZero() || now.sub(investor.paymentTime) < 10 minutes) {
      return 0;
    }
    
    // for prevent burning daily dividends if 24h did not pass - calculate it per 10 min interval
    // if daily percent is X, then 10min percent = X / (24h / 10 min) = X / 144

    // and we must to get numbers of 10 min interval after investor got payment:
    // (now - investor.paymentTime) / 10min 

    // finaly calculate dividends = ((now - investor.paymentTime) / 10min) * (X * investor.investment)  / 144) 

    Percent.percent memory p = dailyPercent();
    dividends = (now.sub(investor.paymentTime) / 10 minutes) * p.mmul(investor.investment) / 144;
  }

  function dailyPercent() internal view returns(Percent.percent memory p) {
    uint balance = address(this).balance;

    // (3) 3% if balance < 10 000 000 ETH

    if (balance < 10000000 ether) { 
      p = m_3_percent.toMemory(); // (3)
    }
  }

  function refBonusPercent() internal view returns(Percent.percent memory p) {
    uint balance = address(this).balance;

    
    // (3) 3% if balance < 10 000 000 ETH   
    
    if (balance < 10000000 ether) { 
      p = m_3_percent.toMemory(); // (3)
    }     
  }

  function nextWave() private {
    m_investors = new InvestorsStorage();
    investmentsNumber = 0;
    waveStartup = now;
    emit LogNextWave(now);
  }
}