pragma solidity ^0.4.24;

contract ERC20 {
    function totalSupply() public constant returns (uint _totalSupply);
    function balanceOf(address _owner) public constant returns (uint balance);
    function transfer(address _to, uint _value) public returns (bool success);
    function transferFrom(address _from, address _to, uint _value) public returns (bool success);
    function approve(address _spender, uint _value) public returns (bool success);
    function allowance(address _owner, address _spender) public constant returns (uint remaining);
    event Transfer(address indexed _from, address indexed _to, uint _value);
    event Approval(address indexed _owner, address indexed _spender, uint _value);
}

contract StibcoMultiSigWallet {

    address public newownerinsteadofoldowner;
    address public oldownertoreplace;
    address public sendto;
    address public d;
    address public contractaddress;
    address public tokensaddress;
    uint public votestoreplace;
    uint public votestosend;
    uint public initiatereplacevote;
    uint public initiatesendtoevote;
    uint public amounttosend;
    uint public areownerscreated;
    uint public totalowners;
    uint public isethsent;
    uint public istokensent;
    uint public sendwithhex;
    uint public theFunction;
    uint public depositype;
    uint public a;
    uint public b;
    uint public c;
    uint public e;
    uint public f;
    uint public g;



    mapping (address => uint) public ownerbyvotetoreplace;
    mapping (address => uint) public ownerbyvotetosend;
    mapping (address =>  address) public ownerbyaddress;
    mapping (uint => address) public ownerbyid;



     modifier ownersrestricted() {
        require(ownerbyaddress[msg.sender] == msg.sender);
        _;
     }

    //allows other contracts to send to this contract
    function () payable public {
    }

    function CreateOwners(address zinititalowner,address zownertwo, address zownerthree,address zownerfour,address zownerfive) public payable {
       require(areownerscreated == 0);
       areownerscreated = 1;
       totalowners = 5;


       ownerbyaddress[zinititalowner] = zinititalowner;
       ownerbyaddress[zownertwo] = zownertwo;
       ownerbyaddress[zownerthree] = zownerthree;
       ownerbyaddress[zownerfour] = zownerfour;
       ownerbyaddress[zownerfive] = zownerfive;

       ownerbyid[1] = zinititalowner;
       ownerbyid[2] = zownertwo;
       ownerbyid[3] = zownerthree;
       ownerbyid[4] = zownerfour;
       ownerbyid[5] = zownerfive;

       contractaddress = address(this);
    }

     function initiateReplaceOwner(address theNewOwner,address theOldOwner) ownersrestricted public payable {
         require(theOldOwner != msg.sender && theNewOwner != msg.sender && totalowners == 5 && initiatereplacevote == 0 && initiatesendtoevote == 0);
         newownerinsteadofoldowner = theNewOwner;
         oldownertoreplace = theOldOwner;
         initiatereplacevote = 1;
         ownerbyvotetoreplace[msg.sender] = 1;
         votestoreplace = votestoreplace + 1;
     }

     function VoteToReplaceOwner() ownersrestricted public payable {
         require(initiatereplacevote == 1 && totalowners == 5 && oldownertoreplace != msg.sender && ownerbyvotetoreplace[msg.sender] == 0 && initiatesendtoevote == 0);
         ownerbyvotetoreplace[msg.sender] = 1;
         votestoreplace = votestoreplace + 1;

           if(votestoreplace == 3){

              delete ownerbyvotetoreplace[oldownertoreplace];
              delete ownerbyvotetosend[oldownertoreplace];
              delete ownerbyaddress[oldownertoreplace];


              ownerbyvotetosend[newownerinsteadofoldowner] = 0;
              ownerbyvotetoreplace[newownerinsteadofoldowner] = 0;

             if(ownerbyid[1] == oldownertoreplace) {
                ownerbyid[1] = newownerinsteadofoldowner;
             } else if (ownerbyid[2] == oldownertoreplace) {
                ownerbyid[2] = newownerinsteadofoldowner;
             } else if (ownerbyid[3] == oldownertoreplace) {
                ownerbyid[3] = newownerinsteadofoldowner;
             } else if (ownerbyid[4] == oldownertoreplace) {
                ownerbyid[4] = newownerinsteadofoldowner;
             } else if (ownerbyid[5] == oldownertoreplace) {
                ownerbyid[5] = newownerinsteadofoldowner;
             }

              ownerbyvotetoreplace[ownerbyid[1]] = 0;
              ownerbyvotetoreplace[ownerbyid[2]] = 0;
              ownerbyvotetoreplace[ownerbyid[3]] = 0;
              ownerbyvotetoreplace[ownerbyid[4]] = 0;
              ownerbyvotetoreplace[ownerbyid[5]] = 0;
              votestoreplace = 0;
              initiatereplacevote = 0;


           }


     }
            function initiateSendTransaction(address SendTo,uint ztheFunction,uint amount ,uint zsendwithhex,address tokensaddr,uint dtype) ownersrestricted public payable {
                require(totalowners == 5 && initiatereplacevote == 0 && initiatesendtoevote == 0 && address(this).balance >= amount );

                if(zsendwithhex == 1){
                  theFunction = ztheFunction;
                  sendwithhex = zsendwithhex;
                }

                
                sendto = SendTo;
                amounttosend = amount;
                tokensaddress = tokensaddr;
                depositype = dtype;
                votestosend = 1;
                initiatesendtoevote = 1;
                ownerbyvotetosend[msg.sender] = 1;


            }



            function setCallContractValues(uint thea,uint theb,uint thec,address thed,uint thee,uint thef,uint theg) ownersrestricted public payable{
                a = thea;
                b = theb;
                c = thec;
                d = thed;
                e = thee;
                f = thef;
                g = theg;
            }









            function VoteToSend() ownersrestricted public payable {
                require(initiatereplacevote == 0 && totalowners == 5 && initiatesendtoevote == 1 && ownerbyvotetosend[msg.sender] == 0);
                  votestosend = votestosend + 1;
                  ownerbyvotetosend[msg.sender] = 1;

                  if(votestosend == 3){

                     //here send eth with hex test (dangerous don't use on contract unknown or not verified)
                      if(sendwithhex == 1){



                          sendto.transfer(amounttosend);

                          if(theFunction == 1) {
                           //create stibco on trade contract ok
                            if(!sendto.call(abi.encodeWithSignature("CreateStibco()"))){
                                revert();
                            }

                          } else if (theFunction == 2) {
                           //set settings trade contract ok
                            if(!sendto.call(abi.encodeWithSignature("StibcoFee(uint256,uint256,uint256,address,uint256,uint256,uint256)",a,b,c,d,e,f,g))){
                                revert();
                            }

                          } else if (theFunction == 3) {
                           //set settings loans contract ok
                            if(!sendto.call(abi.encodeWithSignature("StibcoFee(uint256,uint256,uint256,address,uint256,uint256)",a,b,c,d,e,f))){
                                revert();
                            }


                          } else if (theFunction == 4) {
                           //collect fees contract
                            if(!sendto.call(abi.encodeWithSignature("StiboCollectFee()"))){
                                revert();
                            }

                          } else if (theFunction == 5) {
                           //trade dispute select seller as winner
                            if(!sendto.call(abi.encodeWithSignature("DisputeSellerWins(uint256)",a))){
                                revert();
                            }

                          } else if (theFunction == 6) {
                           //trade dispute select buyer as winner
                            if(!sendto.call(abi.encodeWithSignature("DisputeBuyerWins(uint256)",a))){
                                revert();
                            }

                          } else if (theFunction == 7) {
                           //loans dispute select lender as winner
                            if(!sendto.call(abi.encodeWithSignature("DisputeLenderWins(uint256)",a))){
                                revert();
                            }

                          } else if (theFunction == 8) {
                           //loans dispute select borrower as winner
                             if(!sendto.call(abi.encodeWithSignature("DisputeBorrowerWins(uint256)",a))){
                                revert();
                             }

                          } else if (theFunction == 9) {
                             //tokens trade set settings
                            if(!sendto.call(abi.encodeWithSignature("StibcoFee(uint256,address,uint256,uint256,uint256)",a,d,c,b,e))){
                                revert();
                            }

                          } else if (theFunction == 10) {
                            //tokens loans set settings
                            if(!sendto.call(abi.encodeWithSignature("StibcoFee(uint256,address,uint256,uint256)",a,d,c,b))){
                                revert();
                            }

                          } else if (theFunction == 11) {
                            //trade tokens dispute select seller as winner
                            if(!sendto.call(abi.encodeWithSignature("DisputeSellerWins(uint256,address)",a,d))){
                                revert();
                            }

                          } else if (theFunction == 12) {
                            //trade tokens dispute select buyer as winner
                            if(!sendto.call(abi.encodeWithSignature("DisputeBuyerWins(uint256,address)",a,d))){
                                revert();
                            }

                          } else if (theFunction == 13) {
                            //loans tokens dispute select lender as winner
                            if(!sendto.call(abi.encodeWithSignature("DisputeLenderWins(address,uint256)",d,a))){
                                revert();
                            }

                          } else if (theFunction == 14) {
                            //loans tokens dispute select borrower as winner
                            if(!sendto.call(abi.encodeWithSignature("DisputeBorrowerWins(address,uint256)",d,a))){
                               revert();
                            }

                          } else if (theFunction == 15) {
                            //add tokens,remove tokens , here will have to delegate
                            if(!sendto.call(abi.encodeWithSignature("Delegate(address)",d))){
                               revert();
                            }

                          } else if (theFunction == 16) {
                            //set fee for instant swaps
                            if(!sendto.call(abi.encodeWithSignature("StibcoFee(uint,uint,uint,address)",a,b,c,d))){
                               revert();
                            }

                          }



                      }else{

                         if(depositype == 1){

                         sendto.transfer(amounttosend);
                          isethsent = 1;

                         }else{
                          //here we send tokens out
                           ERC20(tokensaddress).transfer(sendto,amounttosend);
                           istokensent = 1;
                         }



                      }

                    ownerbyvotetosend[ownerbyid[1]] = 0;
                    ownerbyvotetosend[ownerbyid[2]] = 0;
                    ownerbyvotetosend[ownerbyid[3]] = 0;
                    ownerbyvotetosend[ownerbyid[4]] = 0;
                    ownerbyvotetosend[ownerbyid[5]] = 0;
                    votestosend = 0;
                    initiatesendtoevote = 0;

                  }


            }


    function GetFunctionData() public view returns (uint,uint,uint,address,uint,uint,uint) {
        return (
            a,
            b,
            c,
            d,
            e,
            f,
            g
          );
    }



    function GetWalletData() public view returns (address,address,address,address,address,address,uint,uint,uint,address,address,address,uint,uint) {
        return (
            contractaddress,
            ownerbyid[1],
            ownerbyid[2],
            ownerbyid[3],
            ownerbyid[4],
            ownerbyid[5],
            amounttosend,
            votestosend,
            votestoreplace,
            sendto,
            newownerinsteadofoldowner,
            oldownertoreplace,
            sendwithhex,
            theFunction

          );
    }
    
    function GetWalletDataTwo() public view returns (address,uint,uint) {
    
        return (
            tokensaddress,
            depositype,
            istokensent
          );
        
    }

    function GetBalance() public view returns (uint){
        return address(this).balance;
    }




    //gets contract tokens balance
    function getTokenBalance(address tokensadd) public  view returns (uint) {
       return ERC20(tokensadd).balanceOf(address(this));
    }


//deposit token or eth
    function Deposit(address tokensadd,uint amount,uint deposittype) public payable {
        if(deposittype == 1){
            ERC20(tokensadd).transferFrom(msg.sender,contractaddress,amount);
        }else{
            require(amount == msg.value);
        }


    }









}