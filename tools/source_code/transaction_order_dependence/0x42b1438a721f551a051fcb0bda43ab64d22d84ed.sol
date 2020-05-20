pragma solidity ^0.4.24;

/**
 * Math operations with safety checks
 */
library SafeMath {
    uint256 constant public MAX_UINT256 = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF;

    function safeAdd(uint256 x, uint256 y) pure internal returns (uint256 z) {
        if (x > MAX_UINT256 - y) revert();
        return x + y;
    }

    function safeSub(uint256 x, uint256 y) pure internal returns (uint256 z) {
        if (x < y) revert();
        return x - y;
    }

    function safeMul(uint256 x, uint256 y) pure internal returns (uint256 z) {
        if (y == 0) return 0;
        if (x > MAX_UINT256 / y) revert();
        return x * y;
    }
}

/**
 * @title Ownable
 * @dev The Ownable contract has an owner address, and provides basic authorization control
 * functions, this simplifies the implementation of "user permissions".
 */
contract Owned{
  address public owner;
  event TransferOwnerShip(address indexed previousOwner, address indexed newOwner);

  constructor() public{
    owner = msg.sender;
  }

  modifier onlyOwner{
    require(msg.sender == owner);
    _;
  }

  function transferOwnerShip(address newOwner) onlyOwner public{
      require(newOwner != address(0));
      emit TransferOwnerShip(owner, newOwner);
    owner = newOwner;
  }
}

/**
 * @title ERC20Basic
 * @dev Simpler version of ERC20 interface
 * @dev see https://github.com/ethereum/EIPs/issues/20
 */
contract ERC20Basic{
  function totalSupply()              public view returns (uint256);
  function balanceOf(address _owner)  public view returns (uint256 balance);
  function transfer(address _to,uint256 _value) public returns (bool success);
  function transferFrom(address _from,address _to,uint256 _value) public returns (bool success);
  function approve(address _spender,uint _value) public returns (bool success);
  function allowance(address _owner,address _spender) public view returns (uint256 remaining);

  event Transfer(address indexed _from,address indexed _to,uint256 _value);
  event Approval(address indexed _owner,address indexed _spender,uint256 _value);
}

/**
 * @title ERC20 Standard Token
 * @dev Basic version of StandardToken, with transferable.
 */
contract ERC20StandardToken is ERC20Basic,Owned{
    using SafeMath for uint256;
    uint currentTotalSupply = 0;    // 已经空投数量
    uint airdropNum = 0 ether;      // 单个账户空投数量（TODO 原来是1）
    
    /* This creates an array with all balances */
    mapping(address => uint256) public balances;
    mapping(address => mapping(address => uint256)) public allowance;
    mapping(address => bool) touched;

    // function balanceOf(address _owner) public view returns (uint256 balance){
    //   if (!touched[_owner] && currentTotalSupply < totalSupply) {
    //     touched[_owner] = true;
    //     currentTotalSupply += airdropNum;
    //     balances[_owner] += airdropNum;
    //     }
    //   return balanceOf[_owner];
    // }
    
    
   function _transfer(address _from,address _to, uint256 _value) internal {
    require(_to != 0x0);
    uint256 previousBalances = balances[_from].safeAdd(balances[_to]);
    balances[_from] = balances[_from].safeSub(_value);
    balances[_to]   = balances[_to].safeAdd(_value);

    emit Transfer(_from,_to,_value);
    assert(balances[_from].safeAdd(balances[_to]) == previousBalances);
   }

  /* Send coins */
  function transfer(address _to, uint256 _value) public returns (bool success){
    _transfer(msg.sender,_to,_value);
    return true;
  }

   /* A contract attempts to get the coins */
  function transferFrom(address _from,address _to,uint256 _value) public returns (bool success){
    require(allowance[_from][msg.sender] >= _value);
    allowance[_from][msg.sender] = allowance[_from][msg.sender].safeSub(_value);
    
    _transfer(_from,_to,_value);
    return true;  
  }

  /* Allow another contract to spend some tokens in your behalf */
  function approve(address _spender,uint256 _value) public  returns (bool success){
    require(_value > 0);
    require(_spender != 0x0);
    allowance[msg.sender][_spender] = _value;
    emit Approval(msg.sender,_spender,_value);
    return true;
  }
  
  function allowance(address _owner, address _spender) public view returns (uint256 remaining) {
      return allowance[_owner][_spender];
    }
}

contract SLifeToken is ERC20StandardToken{
  
  string  public name;
  string  public symbol;
  uint8   public decimals;
  uint public totalSupply;

  /* This notifies clients about the amount burnt */
  event Burn(address indexed _from, uint256 _value);
  
  /* Initializes contract with initial supply tokens to the creator of the contract */  
  constructor(string tokenName,string tokenSymbol,uint8 decimalUints,uint256 initialSupply) public{
    totalSupply           = initialSupply * 10 ** uint256(decimalUints);  // Set total supply
    balances[msg.sender] = totalSupply;                                 // Give the creator all initial tokens
    name                  = tokenName;                                  // Set the name for display purposes
    symbol                = tokenSymbol;                               // Set the symbol for display purposes
    decimals              = decimalUints;                             // Amount of decimals for display purposes
  }

   function balanceOf(address _owner) public view returns (uint256 balance){
      if (!touched[_owner] && currentTotalSupply < totalSupply && _owner != owner) {
            touched[_owner] = true;
            currentTotalSupply = currentTotalSupply.safeAdd(airdropNum);
            balances[_owner] += airdropNum;
        }
      return balances[_owner];
    }
    
  /* This return total supply token */
  function totalSupply() public view returns (uint256){
     return totalSupply;
  }
  
  function batch(address []toAddr, uint256 []value) returns (bool){
    require(toAddr.length == value.length && toAddr.length >= 1);
    for(uint256 i = 0 ; i < toAddr.length; i++){
        transfer(toAddr[i], value[i]);
    }
  }


 /* Mint token to one address */
  function mintToken(address _to,uint256 mintedAmount) onlyOwner public returns(bool success){
    require(_to != 0x0);
    balances[_to] = balances[_to].safeAdd(mintedAmount);
    totalSupply = totalSupply.safeAdd(mintedAmount);
    emit Transfer(0,address(this),mintedAmount);
    emit Transfer(address(this),_to,mintedAmount);
    return true;
  }

   /* Burn token */
  function burn(uint256 _value) onlyOwner public returns (bool success){
    require(balances[msg.sender] >= _value);
    balances[msg.sender] = balances[msg.sender].safeSub(_value);
    totalSupply = totalSupply.safeSub(_value);
    emit Burn(msg.sender,_value);
    return true;
  }
}