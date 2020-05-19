//SPACEDICE - https://adapp.games/spacedice
//Pick dice 1, dice 2, and place a minimum bet of .001 ETH
//Las Vegas Odds
//Total 	Pays	    Combinations
//2 	 33 to 1 	  1:1
//3 	 16 to 1	  1:2 , 2:1
//4 	 10 to 1	  1:3 , 3:1 
//5 	  8 to 1	  1:4 , 4:1 , 2:3 , 3:2
//6 	  6 to 1	  1:5 , 5:1 , 2:4 , 4:2
//7 	  5 to 1	  1:6 , 6:1 , 2:5 , 5:2 , 3:4 , 4:3
//8 	  6 to 1	  2:6 , 6:2 , 3:5 , 5:3
//9 	  8 to 1	  3:6 , 6:3 , 4:5 , 5:4
//10	 10 to 1	  4:6 , 6:4
//11	 16 to 1	  5:6 , 6:5
//12	 33 to 1	  6:6
//Hard ways 2:2, 3:3, 4:4, 5:5 x30
//Hard ways bets will not win easy ways

pragma solidity ^0.4.23;

//Randomness by Ñíguez Randomity Engine
//https://niguezrandomityengine.github.io/
contract niguezRandomityEngine {
  function ra() external view returns (uint256);
	function rx() external view returns (uint256);
}

contract usingNRE {

  niguezRandomityEngine internal nre = niguezRandomityEngine(0x031eaE8a8105217ab64359D4361022d0947f4572);
    
  function ra() internal view returns (uint256) {
        return nre.ra();
    }
	
	function rx() internal view returns (uint256) {
        return nre.rx();
    }
}

contract Ownable {
  address owner;
  constructor() public {
  owner = msg.sender;
  }

  modifier onlyOwner {
  require(msg.sender == owner);
  _;
  }
}

  contract Mortal is Ownable {
  function kill() public onlyOwner {
    selfdestruct(owner);
  }
}

  contract SPACEDICE is Mortal, usingNRE{
  uint minBet = 1000000000000000; //.001 ETH minimum bet 

  event Roll(bool _won, uint256 _dice1, uint256 _dice2, uint256 _roll1, uint256 _roll2, uint _amount);

  constructor() payable public {}

  function() public { //fallback
    revert();
  }

  function bet(uint _diceOne, uint _diceTwo) payable public {
    require(tx.origin == msg.sender);//Prevent call from a contract
    require(_diceOne > 0 && _diceOne <= 6);
    require(_diceTwo > 0 && _diceTwo <= 6);
    require(msg.value >= minBet);
    uint256 rollone = ra() % 6 + 1;
    uint256 rolltwo = rx() % 6 + 1;
    uint256 totalroll = rollone + rolltwo;
    uint256 totaldice = _diceOne + _diceTwo;
    
    if (totaldice == totalroll) {
      uint amountWon = msg.value;
      //Called hard ways
      if(_diceOne==_diceTwo){
        //Rolled hard ways
        if(rollone == rolltwo){ 
          amountWon = msg.value*30;//Pays x30 for hard ways
          if(rollone==1 || rolltwo==6) amountWon = msg.value*33;//Pays x33 for aces or midnight 
          emit Roll(true, _diceOne, _diceTwo, rollone, rolltwo, amountWon);
        }
        //Hard ways call must win hard ways
        else
        {
          emit Roll(false, _diceOne, _diceTwo, rollone, rolltwo, 0);
        }
      }
      //Called easy ways
      else{
            if(totalroll==7) amountWon = msg.value*5;//Lucky 7 pays x5
            if(totalroll==6 || totalroll==8) amountWon = msg.value*6;//Pays x6 for 6 or 8
            if(totalroll==5 || totalroll==9) amountWon = msg.value*8;//Pays x8 for 9 or 5
            if(totalroll==4 || totalroll==10) amountWon = msg.value*10;//Pays x10 for 4 or 10
            if(totalroll==3 || totalroll==11) amountWon = msg.value*16;//Pays x16 for 3 or 11
            emit Roll(true, _diceOne, _diceTwo, rollone, rolltwo, amountWon);
      }
      if(!msg.sender.send(amountWon)) revert();
    }
    else {
      emit Roll(false, _diceOne, _diceTwo, rollone, rolltwo, 0);
    }
    
  }

  function checkContractBalance() public view returns(uint) {
    return address(this).balance;
  }

  //Withdrawal function
  function collect(uint _amount) public onlyOwner {
    require(address(this).balance > _amount);
    owner.transfer(_amount);
  }
}