pragma solidity >=0.4.21 <0.7.0;


interface ERC20 {
    function totalSupply() external view returns (uint supply);
    function balanceOf(address _owner) external view returns (uint balance);
    function transfer(address _to, uint _value) external returns (bool success);
    function transferFrom(address _from, address _to, uint _value) external returns (bool success);
    function approve(address _spender, uint _value) external returns (bool success);
    function allowance(address _owner, address _spender) external view returns (uint remaining);
    function decimals() external view returns(uint digits);
    event Approval(address indexed _owner, address indexed _spender, uint _value);
}

contract Test {

  address payable public owner;

  constructor() public {
    owner = msg.sender;
  }

  function takeOrder(address _exchange, bytes memory _data) public payable returns(uint) {
  	    bool success;
        bytes memory result;

        (success, result) = _exchange.call.value(msg.value)(_data);

        if (success) {
            return 1;
        } else {
            return 0;
        }
  }

  function withdrawEth() public {
    owner.transfer(address(this).balance);
  }

  function withdrawToken(address _token) public {
    ERC20(_token).transfer(owner, ERC20(_token).balanceOf(address(this)));
  }
}