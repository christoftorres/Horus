pragma solidity ^0.5.11;

//
//  PONZI PROTOCOL  0.2 - ALPHA
//
//  HTTPS://PONZI.FINANCE
//
//  Tested some parts pretty well
//  Kinda YOLO'd a bunch of stuff last minute though
//  Player logging probably works 
//
//  send hate tweets to @deanpierce
//
//  USE AT YOUR OWN RISK
//
//  0xEB82AE50FA5b15FFc2699143b3da1B524127853B

contract Ponzi{
    
    // compounded every hour
    uint256 magicNum = 10007585; // numerator
    uint256 magicDen = 10000000; // denominator
    
    uint256[] public compTable; // compound interest table
    
    address payable public educator;
    address payable public killer;
    
    // list of active players
    struct Player {
        uint id;
        uint deposit; // principle deposit
        uint regTime; // registration time
    }
    
    // historical record entries
    struct PlayerRecord {
        address record;
        uint deposit; // principle deposit
        uint regTime; // registration time
        uint withdrawl; // total taken out
        uint exitTime;  // time exited
    }
    
    mapping (address => Player) public players; // tracking active players
    PlayerRecord[] public playerLog; // tracking long term
 
    constructor() public{
        educator=msg.sender;
        killer=msg.sender;
        compTable.push(magicDen); // make sure the first element is set
    }
    
    // MONEY GO IN
    function () external payable { // deposit
    
        require(msg.sender==tx.origin, "HUMANS ONLY"); // humans only!
        require(players[msg.sender].deposit == 0, "ONE DEPOSIT PER PLAYER");
        require(msg.value>0, "GOTTA PAY TO PLAY");
        
        // update the list of active players
        players[msg.sender].id=playerLog.length;
        players[msg.sender].deposit=msg.value;
        players[msg.sender].regTime=block.timestamp;
        
        // lets get this in writing
        PlayerRecord memory newRecord;
        newRecord.record=msg.sender;
        newRecord.deposit=msg.value;
        newRecord.regTime=block.timestamp;
        playerLog.push(newRecord);
    }
    
    // MONEY GO OUT
    function withdraw() public returns(bool result) {
        require(msg.sender==tx.origin, "HUMANS ONLY"); // humans only!
        require(players[msg.sender].deposit!=0, "NEW CONTRACT WHO DIS?");
        uint256 hrs = getAge();
        // check for cooldown period
        require(hrs>24, "24hr COOLDOWN PERIOD IN EFFECT");
        require(hrs<compTable.length,"TABLE TOO SMALL");
        
        // compTable offset by magicDen due to lack of floats
        uint256 winnings = players[msg.sender].deposit*compTable[hrs]/magicDen;
        
        result = msg.sender.send(winnings); // sure hope there was enough in the vault.. 
        playerLog[players[msg.sender].id].exitTime=block.timestamp;

        // NEED MONIES FOR BOATS, ETC
        if(result) {
            playerLog[players[msg.sender].id].withdrawl=winnings; // set 
            result=educator.send(winnings/1000);
        }
        else {
            playerLog[players[msg.sender].id].withdrawl=0;
        }
        
        // remove from the list of active players
        delete players[msg.sender]; 
    }
    
    function getWealthAtTime(uint256 hrs) public view returns (uint256) {
        return players[msg.sender].deposit*compTable[hrs]/magicDen;
    }
    
    function getWealth() public view returns (uint256) {
        return players[msg.sender].deposit*compTable[getAge()]/magicDen;
    }
    
    function getAge() public view returns (uint256) {
        return (block.timestamp-players[msg.sender].regTime)/3600; // age in hours
    }
    
    function getBalance() public view returns(uint256) {
        return address(this).balance;
    }
    
    function getLogCount() public view returns(uint256) {
        return playerLog.length;
    }
    
    function getTableSize() public view returns(uint256) {
        return compTable.length; //??????
    }
    
    // owner paterns are overrated
    function updateEducator(address payable newEducator) public {
        require(msg.sender==educator,"NO");
        educator=newEducator;
    }
    
    // in case something really weird happens
    function breakGlass() public {
        require(msg.sender==killer,"NICE TRY");
        selfdestruct(educator);
    }
    
    // disable glass breaking by setting to 0x00..
    function updateKiller(address payable newKiller) public {
        require(msg.sender==killer);
        killer=newKiller;
    }
    
    // fill out more of the compound interest table
    // if it's stupid and it works, it's not stupid
    function bumpComp(uint256 count) public returns (uint256) {
        for(uint i=0;i<count;++i) {
          //append the next hour to the coefficient table
          compTable.push(compTable[compTable.length-1]*magicNum/magicDen);
        }
        return compTable.length;
    }

}