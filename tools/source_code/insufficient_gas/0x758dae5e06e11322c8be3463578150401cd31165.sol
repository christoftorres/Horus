/**
 * Copyright 2017-2019, bZeroX, LLC. All Rights Reserved.
 * Adapted from MultiSigWalletWithTimeLock.sol, Copyright 2017 ZeroEx Intl.
 * Licensed under the Apache License, Version 2.0.
 */

pragma solidity 0.5.3;

/// @title Multisignature wallet - Allows multiple parties to agree on transactions before execution.
/// @author Stefan George - <stefan.george@consensys.net>
contract MultiSigWallet {

    /*
     *  Events
     */
    event Confirmation(address indexed sender, uint256 indexed transactionId);
    event Revocation(address indexed sender, uint256 indexed transactionId);
    event Submission(uint256 indexed transactionId);
    event Execution(uint256 indexed transactionId);
    event ExecutionFailure(uint256 indexed transactionId);
    event Deposit(address indexed sender, uint256 value);
    event OwnerAddition(address indexed owner);
    event OwnerRemoval(address indexed owner);
    event RequirementChange(uint256 required);

    /*
     *  Constants
     */
    uint256 constant public MAX_OWNER_COUNT = 50;

    /*
     *  Storage
     */
    mapping (uint256 => Transaction) public transactions;
    mapping (uint256 => mapping (address => bool)) public confirmations;
    mapping (address => bool) public isOwner;
    address[] public owners;
    uint256 public required;
    uint256 public transactionCount;

    struct Transaction {
        address destination;
        uint256 value;
        bytes data;
        bool executed;
    }

    /*
     *  Modifiers
     */
    modifier onlyWallet() {
        require(msg.sender == address(this));
        _;
    }

    modifier ownerDoesNotExist(address owner) {
        require(!isOwner[owner]);
        _;
    }

    modifier ownerExists(address owner) {
        require(isOwner[owner]);
        _;
    }

    modifier transactionExists(uint256 transactionId) {
        require(transactions[transactionId].destination != address(0));
        _;
    }

    modifier confirmed(uint256 transactionId, address owner) {
        require(confirmations[transactionId][owner]);
        _;
    }

    modifier notConfirmed(uint256 transactionId, address owner) {
        require(!confirmations[transactionId][owner]);
        _;
    }

    modifier notExecuted(uint256 transactionId) {
        require(!transactions[transactionId].executed);
        _;
    }

    modifier notNull(address _address) {
        require(_address != address(0));
        _;
    }

    modifier validRequirement(uint256 ownerCount, uint256 _required) {
        require(ownerCount <= MAX_OWNER_COUNT
            && _required <= ownerCount
            && _required != 0
            && ownerCount != 0);
        _;
    }

    /// @dev Fallback function allows to deposit ether.
    function()
        external
        payable
    {
        if (msg.value != 0)
            emit Deposit(msg.sender, msg.value);
    }

    /*
     * Public functions
     */
    /// @dev Contract constructor sets initial owners and required number of confirmations.
    /// @param _owners List of initial owners.
    /// @param _required Number of required confirmations.
    constructor(address[] memory _owners, uint256 _required)
        public
        validRequirement(_owners.length, _required)
    {
        for (uint256 i=0; i < _owners.length; i++) {
            require(!isOwner[_owners[i]] && _owners[i] != address(0));
            isOwner[_owners[i]] = true;
        }
        owners = _owners;
        required = _required;
    }

    /// @dev Allows to add a new owner. Transaction has to be sent by wallet.
    /// @param owner Address of new owner.
    function addOwner(address owner)
        public
        onlyWallet
        ownerDoesNotExist(owner)
        notNull(owner)
        validRequirement(owners.length + 1, required)
    {
        isOwner[owner] = true;
        owners.push(owner);
        emit OwnerAddition(owner);
    }

    /// @dev Allows to remove an owner. Transaction has to be sent by wallet.
    /// @param owner Address of owner.
    function removeOwner(address owner)
        public
        onlyWallet
        ownerExists(owner)
    {
        isOwner[owner] = false;
        for (uint256 i=0; i<owners.length - 1; i++)
            if (owners[i] == owner) {
                owners[i] = owners[owners.length - 1];
                break;
            }
        owners.length -= 1;
        if (required > owners.length)
            changeRequirement(owners.length);
        emit OwnerRemoval(owner);
    }

    /// @dev Allows to replace an owner with a new owner. Transaction has to be sent by wallet.
    /// @param owner Address of owner to be replaced.
    /// @param newOwner Address of new owner.
    function replaceOwner(address owner, address newOwner)
        public
        onlyWallet
        ownerExists(owner)
        ownerDoesNotExist(newOwner)
    {
        for (uint256 i=0; i<owners.length; i++)
            if (owners[i] == owner) {
                owners[i] = newOwner;
                break;
            }
        isOwner[owner] = false;
        isOwner[newOwner] = true;
        emit OwnerRemoval(owner);
        emit OwnerAddition(newOwner);
    }

    /// @dev Allows to change the number of required confirmations. Transaction has to be sent by wallet.
    /// @param _required Number of required confirmations.
    function changeRequirement(uint256 _required)
        public
        onlyWallet
        validRequirement(owners.length, _required)
    {
        required = _required;
        emit RequirementChange(_required);
    }

    /// @dev Allows an owner to submit and confirm a transaction.
    /// @param destination Transaction target address.
    /// @param value Transaction ether value.
    /// @param data Transaction data payload.
    /// @return Returns transaction ID.
    function submitTransaction(address destination, uint256 value, bytes memory data)
        public
        returns (uint256 transactionId)
    {
        transactionId = addTransaction(destination, value, data);
        confirmTransaction(transactionId);
    }

    /// @dev Allows an owner to confirm a transaction.
    /// @param transactionId Transaction ID.
    function confirmTransaction(uint256 transactionId)
        public
        ownerExists(msg.sender)
        transactionExists(transactionId)
        notConfirmed(transactionId, msg.sender)
    {
        confirmations[transactionId][msg.sender] = true;
        emit Confirmation(msg.sender, transactionId);
        executeTransaction(transactionId);
    }

    /// @dev Allows an owner to revoke a confirmation for a transaction.
    /// @param transactionId Transaction ID.
    function revokeConfirmation(uint256 transactionId)
        public
        ownerExists(msg.sender)
        confirmed(transactionId, msg.sender)
        notExecuted(transactionId)
    {
        confirmations[transactionId][msg.sender] = false;
        emit Revocation(msg.sender, transactionId);
    }

    /// @dev Allows anyone to execute a confirmed transaction.
    /// @param transactionId Transaction ID.
    function executeTransaction(uint256 transactionId)
        public
        ownerExists(msg.sender)
        confirmed(transactionId, msg.sender)
        notExecuted(transactionId)
    {
        if (isConfirmed(transactionId)) {
            Transaction storage txn = transactions[transactionId];
            txn.executed = true;
            if (external_call(txn.destination, txn.value, txn.data.length, txn.data))
                emit Execution(transactionId);
            else {
                emit ExecutionFailure(transactionId);
                txn.executed = false;
            }
        }
    }

    // call has been separated into its own function in order to take advantage
    // of the Solidity's code generator to produce a loop that copies tx.data into memory.
    function external_call(address destination, uint256 value, uint256 dataLength, bytes memory data) internal returns (bool) {
        bool result;
        assembly {
            let x := mload(0x40)   // "Allocate" memory for output (0x40 is where "free memory" pointer is stored by convention)
            let d := add(data, 32) // First 32 bytes are the padded length of data, so exclude that
            result := call(
                sub(gas, 34710),   // 34710 is the value that solidity is currently emitting
                                   // It includes callGas (700) + callVeryLow (3, to pay for SUB) + callValueTransferGas (9000) +
                                   // callNewAccountGas (25000, in case the destination address does not exist and needs creating)
                destination,
                value,
                d,
                dataLength,        // Size of the input (in bytes) - this is what fixes the padding problem
                x,
                0                  // Output is ignored, therefore the output size is zero
            )
        }
        return result;
    }

    /// @dev Returns the confirmation status of a transaction.
    /// @param transactionId Transaction ID.
    /// @return Confirmation status.
    function isConfirmed(uint256 transactionId)
        public
        view
        returns (bool)
    {
        uint256 count = 0;
        for (uint256 i=0; i<owners.length; i++) {
            if (confirmations[transactionId][owners[i]])
                count += 1;
            if (count == required)
                return true;
        }
    }

    /*
     * Internal functions
     */
    /// @dev Adds a new transaction to the transaction mapping, if transaction does not exist yet.
    /// @param destination Transaction target address.
    /// @param value Transaction ether value.
    /// @param data Transaction data payload.
    /// @return Returns transaction ID.
    function addTransaction(address destination, uint256 value, bytes memory data)
        internal
        notNull(destination)
        returns (uint256 transactionId)
    {
        transactionId = transactionCount;
        transactions[transactionId] = Transaction({
            destination: destination,
            value: value,
            data: data,
            executed: false
        });
        transactionCount += 1;
        emit Submission(transactionId);
    }

    /*
     * Web3 call functions
     */
    /// @dev Returns number of confirmations of a transaction.
    /// @param transactionId Transaction ID.
    /// @return Number of confirmations.
    function getConfirmationCount(uint256 transactionId)
        public
        view
        returns (uint256 count)
    {
        for (uint256 i=0; i<owners.length; i++)
            if (confirmations[transactionId][owners[i]])
                count += 1;
    }

    /// @dev Returns total number of transactions after filers are applied.
    /// @param pending Include pending transactions.
    /// @param executed Include executed transactions.
    /// @return Total number of transactions after filters are applied.
    function getTransactionCount(bool pending, bool executed)
        public
        view
        returns (uint256 count)
    {
        for (uint256 i=0; i<transactionCount; i++)
            if (   pending && !transactions[i].executed
                || executed && transactions[i].executed)
                count += 1;
    }

    /// @dev Returns list of owners.
    /// @return List of owner addresses.
    function getOwners()
        public
        view
        returns (address[] memory)
    {
        return owners;
    }

    /// @dev Returns array with owner addresses, which confirmed transaction.
    /// @param transactionId Transaction ID.
    /// @return Returns array of owner addresses.
    function getConfirmations(uint256 transactionId)
        public
        view
        returns (address[] memory _confirmations)
    {
        address[] memory confirmationsTemp = new address[](owners.length);
        uint256 count = 0;
        uint256 i;
        for (i=0; i<owners.length; i++)
            if (confirmations[transactionId][owners[i]]) {
                confirmationsTemp[count] = owners[i];
                count += 1;
            }
        _confirmations = new address[](count);
        for (i=0; i<count; i++)
            _confirmations[i] = confirmationsTemp[i];
    }

    /// @dev Returns list of transaction IDs in defined range.
    /// @param from Index start position of transaction array.
    /// @param to Index end position of transaction array.
    /// @param pending Include pending transactions.
    /// @param executed Include executed transactions.
    /// @return Returns array of transaction IDs.
    function getTransactionIds(uint256 from, uint256 to, bool pending, bool executed)
        public
        view
        returns (uint256[] memory _transactionIds)
    {
        uint256[] memory transactionIdsTemp = new uint256[](transactionCount);
        uint256 count = 0;
        uint256 i;
        for (i=0; i<transactionCount; i++)
            if (   pending && !transactions[i].executed
                || executed && transactions[i].executed)
            {
                transactionIdsTemp[count] = i;
                count += 1;
            }
        _transactionIds = new uint256[](to - from);
        for (i=from; i<to; i++)
            _transactionIds[i - from] = transactionIdsTemp[i];
    }
}

contract MultiSigWalletWithCustomTimeLocks is MultiSigWallet {

    event ConfirmationTimeSet(uint256 indexed transactionId, uint256 confirmationTime);
    event TimeLockDefaultChange(uint256 secondsTimeLockedDefault);
    event TimeLockCustomChange(string funcHeader, uint256 secondsTimeLockedCustom);
    event TimeLockCustomRemove(string funcHeader);

    struct CustomTimeLock {
        uint256 secondsTimeLocked;
        bool isSet;
    }

    uint256 public secondsTimeLockedDefault; // default timelock for functions without a custom setting
    mapping (bytes4 => CustomTimeLock) public customTimeLocks; // mapping of function headers to CustomTimeLock structs
    string[] public customTimeLockFunctions; // array of functions with custom values

    mapping (uint256 => uint256) public confirmationTimes;

    modifier notFullyConfirmed(uint256 transactionId) {
        require(!isConfirmed(transactionId), "is confirmed");
        _;
    }

    modifier fullyConfirmed(uint256 transactionId) {
        require(isConfirmed(transactionId), "not confirmed");
        _;
    }

    modifier passedTimeLock(uint256 transactionId) {
        uint256 timelock = getSecondsTimeLockedByTx(transactionId);
        require(timelock == 0 || block.timestamp >= confirmationTimes[transactionId] + timelock, "not passed timelock");
        _;
    }

    /*
     * Public functions
     */

    /// @dev Contract constructor sets initial owners, required number of confirmations, and time lock.
    /// @param _owners List of initial owners.
    /// @param _required Number of required confirmations.
    /// @param _secondsTimeLockedDefault Default duration needed after a transaction is confirmed and before it becomes executable, in seconds.
    constructor(address[] memory _owners, uint256 _required, uint256 _secondsTimeLockedDefault)
        public
        MultiSigWallet(_owners, _required)
    {
        secondsTimeLockedDefault = _secondsTimeLockedDefault;

        customTimeLockFunctions.push("transferOwnership(address)");
        customTimeLocks[bytes4(keccak256("transferOwnership(address)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("transferOwnership(address)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("transferBZxOwnership(address)");
        customTimeLocks[bytes4(keccak256("transferBZxOwnership(address)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("transferBZxOwnership(address)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("setBZxAddresses(address,address,address,address,address,address,address)");
        customTimeLocks[bytes4(keccak256("setBZxAddresses(address,address,address,address,address,address,address)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("setBZxAddresses(address,address,address,address,address,address,address)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("setVault(address)");
        customTimeLocks[bytes4(keccak256("setVault(address)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("setVault(address)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("addOwner(address)");
        customTimeLocks[bytes4(keccak256("addOwner(address)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("addOwner(address)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("removeOwner(address)");
        customTimeLocks[bytes4(keccak256("removeOwner(address)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("removeOwner(address)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("replaceOwner(address,address)");
        customTimeLocks[bytes4(keccak256("replaceOwner(address,address)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("replaceOwner(address,address)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("changeRequirement(uint256)");
        customTimeLocks[bytes4(keccak256("changeRequirement(uint256)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("changeRequirement(uint256)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("changeDefaultTimeLock(uint256)");
        customTimeLocks[bytes4(keccak256("changeDefaultTimeLock(uint256)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("changeDefaultTimeLock(uint256)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("changeCustomTimeLock(string,uint256)");
        customTimeLocks[bytes4(keccak256("changeCustomTimeLock(string,uint256)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("changeCustomTimeLock(string,uint256)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("removeCustomTimeLock(string)");
        customTimeLocks[bytes4(keccak256("removeCustomTimeLock(string)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("removeCustomTimeLock(string)"))].secondsTimeLocked = 172800;

        customTimeLockFunctions.push("toggleTargetPause(string,bool)");
        customTimeLocks[bytes4(keccak256("toggleTargetPause(string,bool)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("toggleTargetPause(string,bool)"))].secondsTimeLocked = 0;

        customTimeLockFunctions.push("toggleMintingPause(string,bool)");
        customTimeLocks[bytes4(keccak256("toggleMintingPause(string,bool)"))].isSet = true;
        customTimeLocks[bytes4(keccak256("toggleMintingPause(string,bool)"))].secondsTimeLocked = 0;
    }

    /// @dev Changes the default duration of the time lock for transactions.
    /// @param _secondsTimeLockedDefault Default duration needed after a transaction is confirmed and before it becomes executable, in seconds.
    function changeDefaultTimeLock(uint256 _secondsTimeLockedDefault)
        public
        onlyWallet
    {
        secondsTimeLockedDefault = _secondsTimeLockedDefault;
        emit TimeLockDefaultChange(_secondsTimeLockedDefault);
    }

    /// @dev Changes the custom duration of the time lock for transactions to a specific function.
    /// @param _funcId example: "functionName(address[8],uint256[11],bytes,address,uint256,bytes)"
    /// @param _secondsTimeLockedCustom Custom duration needed after a transaction is confirmed and before it becomes executable, in seconds.
    function changeCustomTimeLock(string memory _funcId, uint256 _secondsTimeLockedCustom)
        public
        onlyWallet
    {
        bytes4 f = bytes4(keccak256(abi.encodePacked(_funcId)));
        if (!customTimeLocks[f].isSet) {
            customTimeLocks[f].isSet = true;
            customTimeLockFunctions.push(_funcId);
        }
        customTimeLocks[f].secondsTimeLocked = _secondsTimeLockedCustom;
        emit TimeLockCustomChange(_funcId, _secondsTimeLockedCustom);
    }

    /// @dev Removes the custom duration of the time lock for transactions to a specific function.
    /// @param _funcId example: "functionName(address[8],uint256[11],bytes,address,uint256,bytes)"
    function removeCustomTimeLock(string memory _funcId)
        public
        onlyWallet
    {
        bytes4 f = bytes4(keccak256(abi.encodePacked(_funcId)));
        if (!customTimeLocks[f].isSet)
            revert("not set");

        for (uint256 i=0; i < customTimeLockFunctions.length; i++) {
            if (keccak256(bytes(customTimeLockFunctions[i])) == keccak256(bytes(_funcId))) {
                if (i < customTimeLockFunctions.length - 1)
                    customTimeLockFunctions[i] = customTimeLockFunctions[customTimeLockFunctions.length - 1];
                customTimeLockFunctions.length--;

                customTimeLocks[f].secondsTimeLocked = 0;
                customTimeLocks[f].isSet = false;

                emit TimeLockCustomRemove(_funcId);

                break;
            }
        }
    }

    /// @dev Allows an owner to confirm a transaction.
    /// @param transactionId Transaction ID.
    function confirmTransaction(uint256 transactionId)
        public
        ownerExists(msg.sender)
        transactionExists(transactionId)
        notConfirmed(transactionId, msg.sender)
        notFullyConfirmed(transactionId)
    {
        confirmations[transactionId][msg.sender] = true;
        emit Confirmation(msg.sender, transactionId);
        if (getSecondsTimeLockedByTx(transactionId) > 0 && isConfirmed(transactionId)) {
            setConfirmationTime(transactionId, block.timestamp);
        }
    }

    /// @dev Allows an owner to revoke a confirmation for a transaction.
    /// @param transactionId Transaction ID.
    function revokeConfirmation(uint256 transactionId)
        public
        ownerExists(msg.sender)
        confirmed(transactionId, msg.sender)
        notExecuted(transactionId)
        notFullyConfirmed(transactionId)
    {
        confirmations[transactionId][msg.sender] = false;
        emit Revocation(msg.sender, transactionId);
    }

    /// @dev Allows anyone to execute a confirmed transaction.
    /// @param transactionId Transaction ID.
    function executeTransaction(uint256 transactionId)
        public
        notExecuted(transactionId)
        fullyConfirmed(transactionId)
        passedTimeLock(transactionId)
    {
        Transaction storage txn = transactions[transactionId];
        txn.executed = true;
        if (external_call(txn.destination, txn.value, txn.data.length, txn.data))
            emit Execution(transactionId);
        else {
            emit ExecutionFailure(transactionId);
            txn.executed = false;
        }
    }

    /// @dev Returns the custom timelock for a function, or the default timelock if a custom value isn't set
    /// @param _funcId Function signature (encoded bytes)
    /// @return Timelock value
    function getSecondsTimeLocked(bytes4 _funcId)
        public
        view
        returns (uint256)
    {
        if (customTimeLocks[_funcId].isSet)
            return customTimeLocks[_funcId].secondsTimeLocked;
        else
            return secondsTimeLockedDefault;
    }

    /// @dev Returns the custom timelock for a function, or the default timelock if a custom value isn't set
    /// @param _funcId Function signature (complete string)
    /// @return Timelock value
    function getSecondsTimeLockedByString(string memory _funcId)
        public
        view
        returns (uint256)
    {
        return (getSecondsTimeLocked(bytes4(keccak256(abi.encodePacked(_funcId)))));
    }

    /// @dev Returns the custom timelock for a transaction, or the default timelock if a custom value isn't set
    /// @param transactionId Transaction ID.
    /// @return Timelock value
    function getSecondsTimeLockedByTx(uint256 transactionId)
        public
        view
        returns (uint256)
    {
        Transaction memory txn = transactions[transactionId];
        bytes memory data = txn.data;
        bytes4 funcId;
        assembly {
            funcId := mload(add(data, 32))
        }
        return (getSecondsTimeLocked(funcId));
    }

    /// @dev Returns the number of seconds until a fully confirmed transaction can be executed
    /// @param transactionId Transaction ID.
    /// @return Seconds in the timelock remaining
    function getTimeLockSecondsRemaining(uint256 transactionId)
        public
        view
        returns (uint256)
    {
        uint256 timelock = getSecondsTimeLockedByTx(transactionId);
        if (timelock > 0 && confirmationTimes[transactionId] > 0) {
            uint256 timelockEnding = confirmationTimes[transactionId] + timelock;
            if (timelockEnding > block.timestamp)
                return timelockEnding - block.timestamp;
        }
        return 0;
    }

    /*
     * Internal functions
     */

    /// @dev Sets the time of when a submission first passed.
    function setConfirmationTime(uint256 transactionId, uint256 confirmationTime)
        internal
    {
        confirmationTimes[transactionId] = confirmationTime;
        emit ConfirmationTimeSet(transactionId, confirmationTime);
    }
}