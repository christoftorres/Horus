pragma solidity ^0.5.0;

/**
 * @dev Wrappers over Solidity's arithmetic operations with added overflow
 * checks.
 *
 * Arithmetic operations in Solidity wrap on overflow. This can easily result
 * in bugs, because programmers usually assume that an overflow raises an
 * error, which is the standard behavior in high level programming languages.
 * `SafeMath` restores this intuition by reverting the transaction when an
 * operation overflows.
 *
 * Using this library instead of the unchecked operations eliminates an entire
 * class of bugs, so it's recommended to use it always.
 */
library SafeMath {
    /**
     * @dev Returns the addition of two unsigned integers, reverting on
     * overflow.
     *
     * Counterpart to Solidity's `+` operator.
     *
     * Requirements:
     * - Addition cannot overflow.
     */
    function add(uint256 a, uint256 b) internal pure returns (uint256) {
        uint256 c = a + b;
        require(c >= a, "SafeMath: addition overflow");

        return c;
    }

    /**
     * @dev Returns the subtraction of two unsigned integers, reverting on
     * overflow (when the result is negative).
     *
     * Counterpart to Solidity's `-` operator.
     *
     * Requirements:
     * - Subtraction cannot overflow.
     */
    function sub(uint256 a, uint256 b) internal pure returns (uint256) {
        require(b <= a, "SafeMath: subtraction overflow");
        uint256 c = a - b;

        return c;
    }

    /**
     * @dev Returns the multiplication of two unsigned integers, reverting on
     * overflow.
     *
     * Counterpart to Solidity's `*` operator.
     *
     * Requirements:
     * - Multiplication cannot overflow.
     */
    function mul(uint256 a, uint256 b) internal pure returns (uint256) {
        // Gas optimization: this is cheaper than requiring 'a' not being zero, but the
        // benefit is lost if 'b' is also tested.
        // See: https://github.com/OpenZeppelin/openzeppelin-solidity/pull/522
        if (a == 0) {
            return 0;
        }

        uint256 c = a * b;
        require(c / a == b, "SafeMath: multiplication overflow");

        return c;
    }

    /**
     * @dev Returns the integer division of two unsigned integers. Reverts on
     * division by zero. The result is rounded towards zero.
     *
     * Counterpart to Solidity's `/` operator. Note: this function uses a
     * `revert` opcode (which leaves remaining gas untouched) while Solidity
     * uses an invalid opcode to revert (consuming all remaining gas).
     *
     * Requirements:
     * - The divisor cannot be zero.
     */
    function div(uint256 a, uint256 b) internal pure returns (uint256) {
        // Solidity only automatically asserts when dividing by 0
        require(b > 0, "SafeMath: division by zero");
        uint256 c = a / b;
        // assert(a == b * c + a % b); // There is no case in which this doesn't hold

        return c;
    }

    /**
     * @dev Returns the remainder of dividing two unsigned integers. (unsigned integer modulo),
     * Reverts when dividing by zero.
     *
     * Counterpart to Solidity's `%` operator. This function uses a `revert`
     * opcode (which leaves remaining gas untouched) while Solidity uses an
     * invalid opcode to revert (consuming all remaining gas).
     *
     * Requirements:
     * - The divisor cannot be zero.
     */
    function mod(uint256 a, uint256 b) internal pure returns (uint256) {
        require(b != 0, "SafeMath: modulo by zero");
        return a % b;
    }
}

/**
 * @dev Interface of the ERC20 standard as defined in the EIP. Does not include
 * the optional functions; to access them see `ERC20Detailed`.
 */
interface IERC20 {
    /**
     * @dev Returns the amount of tokens in existence.
     */
    function totalSupply() external view returns (uint256);

    /**
     * @dev Returns the amount of tokens owned by `account`.
     */
    function balanceOf(address account) external view returns (uint256);

    /**
     * @dev Moves `amount` tokens from the caller's account to `recipient`.
     *
     * Returns a boolean value indicating whether the operation succeeded.
     *
     * Emits a `Transfer` event.
     */
    function transfer(address recipient, uint256 amount) external returns (bool);

    /**
     * @dev Returns the remaining number of tokens that `spender` will be
     * allowed to spend on behalf of `owner` through `transferFrom`. This is
     * zero by default.
     *
     * This value changes when `approve` or `transferFrom` are called.
     */
    function allowance(address owner, address spender) external view returns (uint256);

    /**
     * @dev Sets `amount` as the allowance of `spender` over the caller's tokens.
     *
     * Returns a boolean value indicating whether the operation succeeded.
     *
     * > Beware that changing an allowance with this method brings the risk
     * that someone may use both the old and the new allowance by unfortunate
     * transaction ordering. One possible solution to mitigate this race
     * condition is to first reduce the spender's allowance to 0 and set the
     * desired value afterwards:
     * https://github.com/ethereum/EIPs/issues/20#issuecomment-263524729
     *
     * Emits an `Approval` event.
     */
    function approve(address spender, uint256 amount) external returns (bool);

    /**
     * @dev Moves `amount` tokens from `sender` to `recipient` using the
     * allowance mechanism. `amount` is then deducted from the caller's
     * allowance.
     *
     * Returns a boolean value indicating whether the operation succeeded.
     *
     * Emits a `Transfer` event.
     */
    function transferFrom(address sender, address recipient, uint256 amount) external returns (bool);

    /**
     * @dev Emitted when `value` tokens are moved from one account (`from`) to
     * another (`to`).
     *
     * Note that `value` may be zero.
     */
    event Transfer(address indexed from, address indexed to, uint256 value);

    /**
     * @dev Emitted when the allowance of a `spender` for an `owner` is set by
     * a call to `approve`. `value` is the new allowance.
     */
    event Approval(address indexed owner, address indexed spender, uint256 value);
}


/**
 * @dev Contract module which provides a basic access control mechanism, where
 * there is an account (an owner) that can be granted exclusive access to
 * specific functions.
 *
 * This module is used through inheritance. It will make available the modifier
 * `onlyOwner`, which can be aplied to your functions to restrict their use to
 * the owner.
 */
contract Ownable {
    address private _owner;

    event OwnershipTransferred(address indexed previousOwner, address indexed newOwner);

    /**
     * @dev Initializes the contract setting the deployer as the initial owner.
     */
    constructor () internal {
        _owner = msg.sender;
        emit OwnershipTransferred(address(0), _owner);
    }

    /**
     * @dev Returns the address of the current owner.
     */
    function owner() public view returns (address) {
        return _owner;
    }

    /**
     * @dev Throws if called by any account other than the owner.
     */
    modifier onlyOwner() {
        require(isOwner(), "Ownable: caller is not the owner");
        _;
    }

    /**
     * @dev Returns true if the caller is the current owner.
     */
    function isOwner() public view returns (bool) {
        return msg.sender == _owner;
    }

    /**
     * @dev Leaves the contract without owner. It will not be possible to call
     * `onlyOwner` functions anymore. Can only be called by the current owner.
     *
     * > Note: Renouncing ownership will leave the contract without an owner,
     * thereby removing any functionality that is only available to the owner.
     */
    function renounceOwnership() public onlyOwner {
        emit OwnershipTransferred(_owner, address(0));
        _owner = address(0);
    }

    /**
     * @dev Transfers ownership of the contract to a new account (`newOwner`).
     * Can only be called by the current owner.
     */
    function transferOwnership(address newOwner) public onlyOwner {
        _transferOwnership(newOwner);
    }

    /**
     * @dev Transfers ownership of the contract to a new account (`newOwner`).
     */
    function _transferOwnership(address newOwner) internal {
        require(newOwner != address(0), "Ownable: new owner is the zero address");
        emit OwnershipTransferred(_owner, newOwner);
        _owner = newOwner;
    }
}


/**
 * @dev Implementation of the `IERC20` interface.
 *
 * This implementation is agnostic to the way tokens are created. This means
 * that a supply mechanism has to be added in a derived contract using `_mint`.
 * For a generic mechanism see `ERC20Mintable`.
 *
 * *For a detailed writeup see our guide [How to implement supply
 * mechanisms](https://forum.zeppelin.solutions/t/how-to-implement-erc20-supply-mechanisms/226).*
 *
 * We have followed general OpenZeppelin guidelines: functions revert instead
 * of returning `false` on failure. This behavior is nonetheless conventional
 * and does not conflict with the expectations of ERC20 applications.
 *
 * Additionally, an `Approval` event is emitted on calls to `transferFrom`.
 * This allows applications to reconstruct the allowance for all accounts just
 * by listening to said events. Other implementations of the EIP may not emit
 * these events, as it isn't required by the specification.
 *
 * Finally, the non-standard `decreaseAllowance` and `increaseAllowance`
 * functions have been added to mitigate the well-known issues around setting
 * allowances. See `IERC20.approve`.
 */
contract ERC20 is IERC20 {
    using SafeMath for uint256;

    mapping (address => uint256) private _balances;

    mapping (address => mapping (address => uint256)) private _allowances;

    uint256 private _totalSupply;

    /**
     * @dev See `IERC20.totalSupply`.
     */
    function totalSupply() public view returns (uint256) {
        return _totalSupply;
    }

    /**
     * @dev See `IERC20.balanceOf`.
     */
    function balanceOf(address account) public view returns (uint256) {
        return _balances[account];
    }

    /**
     * @dev See `IERC20.transfer`.
     *
     * Requirements:
     *
     * - `recipient` cannot be the zero address.
     * - the caller must have a balance of at least `amount`.
     */
    function transfer(address recipient, uint256 amount) public returns (bool) {
        _transfer(msg.sender, recipient, amount);
        return true;
    }

    /**
     * @dev See `IERC20.allowance`.
     */
    function allowance(address owner, address spender) public view returns (uint256) {
        return _allowances[owner][spender];
    }

    /**
     * @dev See `IERC20.approve`.
     *
     * Requirements:
     *
     * - `spender` cannot be the zero address.
     */
    function approve(address spender, uint256 value) public returns (bool) {
        _approve(msg.sender, spender, value);
        return true;
    }

    /**
     * @dev See `IERC20.transferFrom`.
     *
     * Emits an `Approval` event indicating the updated allowance. This is not
     * required by the EIP. See the note at the beginning of `ERC20`;
     *
     * Requirements:
     * - `sender` and `recipient` cannot be the zero address.
     * - `sender` must have a balance of at least `value`.
     * - the caller must have allowance for `sender`'s tokens of at least
     * `amount`.
     */
    function transferFrom(address sender, address recipient, uint256 amount) public returns (bool) {
        _transfer(sender, recipient, amount);
        _approve(sender, msg.sender, _allowances[sender][msg.sender].sub(amount));
        return true;
    }

    /**
     * @dev Atomically increases the allowance granted to `spender` by the caller.
     *
     * This is an alternative to `approve` that can be used as a mitigation for
     * problems described in `IERC20.approve`.
     *
     * Emits an `Approval` event indicating the updated allowance.
     *
     * Requirements:
     *
     * - `spender` cannot be the zero address.
     */
    function increaseAllowance(address spender, uint256 addedValue) public returns (bool) {
        _approve(msg.sender, spender, _allowances[msg.sender][spender].add(addedValue));
        return true;
    }

    /**
     * @dev Atomically decreases the allowance granted to `spender` by the caller.
     *
     * This is an alternative to `approve` that can be used as a mitigation for
     * problems described in `IERC20.approve`.
     *
     * Emits an `Approval` event indicating the updated allowance.
     *
     * Requirements:
     *
     * - `spender` cannot be the zero address.
     * - `spender` must have allowance for the caller of at least
     * `subtractedValue`.
     */
    function decreaseAllowance(address spender, uint256 subtractedValue) public returns (bool) {
        _approve(msg.sender, spender, _allowances[msg.sender][spender].sub(subtractedValue));
        return true;
    }

    /**
     * @dev Moves tokens `amount` from `sender` to `recipient`.
     *
     * This is internal function is equivalent to `transfer`, and can be used to
     * e.g. implement automatic token fees, slashing mechanisms, etc.
     *
     * Emits a `Transfer` event.
     *
     * Requirements:
     *
     * - `sender` cannot be the zero address.
     * - `recipient` cannot be the zero address.
     * - `sender` must have a balance of at least `amount`.
     */
    function _transfer(address sender, address recipient, uint256 amount) internal {
        require(sender != address(0), "ERC20: transfer from the zero address");
        require(recipient != address(0), "ERC20: transfer to the zero address");

        _balances[sender] = _balances[sender].sub(amount);
        _balances[recipient] = _balances[recipient].add(amount);
        emit Transfer(sender, recipient, amount);
    }

    /** @dev Creates `amount` tokens and assigns them to `account`, increasing
     * the total supply.
     *
     * Emits a `Transfer` event with `from` set to the zero address.
     *
     * Requirements
     *
     * - `to` cannot be the zero address.
     */
    function _mint(address account, uint256 amount) internal {
        require(account != address(0), "ERC20: mint to the zero address");

        _totalSupply = _totalSupply.add(amount);
        _balances[account] = _balances[account].add(amount);
        emit Transfer(address(0), account, amount);
    }

     /**
     * @dev Destoys `amount` tokens from `account`, reducing the
     * total supply.
     *
     * Emits a `Transfer` event with `to` set to the zero address.
     *
     * Requirements
     *
     * - `account` cannot be the zero address.
     * - `account` must have at least `amount` tokens.
     */
    function _burn(address account, uint256 value) internal {
        require(account != address(0), "ERC20: burn from the zero address");

        _totalSupply = _totalSupply.sub(value);
        _balances[account] = _balances[account].sub(value);
        emit Transfer(account, address(0), value);
    }

    /**
     * @dev Sets `amount` as the allowance of `spender` over the `owner`s tokens.
     *
     * This is internal function is equivalent to `approve`, and can be used to
     * e.g. set automatic allowances for certain subsystems, etc.
     *
     * Emits an `Approval` event.
     *
     * Requirements:
     *
     * - `owner` cannot be the zero address.
     * - `spender` cannot be the zero address.
     */
    function _approve(address owner, address spender, uint256 value) internal {
        require(owner != address(0), "ERC20: approve from the zero address");
        require(spender != address(0), "ERC20: approve to the zero address");

        _allowances[owner][spender] = value;
        emit Approval(owner, spender, value);
    }

    /**
     * @dev Destoys `amount` tokens from `account`.`amount` is then deducted
     * from the caller's allowance.
     *
     * See `_burn` and `_approve`.
     */
    function _burnFrom(address account, uint256 amount) internal {
        _burn(account, amount);
        _approve(account, msg.sender, _allowances[account][msg.sender].sub(amount));
    }
}


interface NativeTokenMigrationInterface {
    // ***
    // Public functions
    // ***
    function transferToNativeTargetAddress(uint256 amount, string calldata FETAddress) external;
    function transferToNativeFromKey(uint256 amount) external;
    function refund(uint256 id) external;
    function requestRefund(uint256 id) external;

    // ***
    // Restricted functions: Owner only
    // ***
    // Add or remove a delegate address that is allowed to confirm and reject transactions
    function setDelegate(address _address, bool isDelegate) external;
    // Change the _upperTransferLimit which is the maximum threshold any single swap can be
    function setUpperTransferLimit(uint256 newLimit) external;
    // Change the _lowerTransferLimit which is the minimum threshold any single swap can be
    function setLowerTransferLimit(uint256 newLimit) external;
    // Withdraw the tokens the confirmed swaps to the owner
    function withdrawToFoundation(uint256 _amount) external;
    // Delete the contract after _earliestDelete timestamp is reached, transfers the remaining
    function deleteContract(address payable payoutAddress) external;

    // ***
    // Restricted functions: Owner or delegate only
    // ***
    // Reject a swap with reason. Allows the initialiser to immediately withdraw the funds again
    function reject(address sender, uint256 id, uint256 expirationBlock, string calldata reason) external;
    // Reject multiple swaps with the same reason
    function batchReject(
        address[] calldata senders,
        uint256[] calldata _ids,
        uint256[] calldata expirationBlocks,
        string calldata reason) external;
    // Pause or unpause the transferToNativeTargetAddress() method
    function pauseTransferToNativeTargetAddress(bool isPaused) external;
    // Pause or unpause the transferToNativeFromKey() method
    function pauseTransferToNativeFromKey(bool isPaused) external;
}


contract NativeTokenMigration is Ownable, NativeTokenMigrationInterface {
    using SafeMath for uint256;

    // minimum time the owner has to wait after the last initialised transfer before allowed to
    // delete the contract, in seconds
    uint256 constant DELETE_PERIOD = 10 days;
    uint256 constant FET_TOTAL_SUPPLY = 1152997575 * 10**18;
    uint256 constant DECIMAL_DIFFERENTIATOR = 10**8;

    enum Status {Empty, Initialised, Rejected}

    struct Swap {
        address sender;
        uint256 amount;
        Status status;
        uint256 fee;
    }

    uint256 public globalSwapID;
    // globalSwapID => swap
    // usage of a global id instead of address, id pair to simplify processing during the transfer
    // over to mainnet
    mapping(uint256 => Swap) public swaps;
    // global counter increased by every new swap

    ERC20 public token;

    mapping(address => bool) public delegates;
    uint256 public _transferFee;
    uint256 public _upperTransferLimit;
    uint256 public _lowerTransferLimit;
    uint256 public _completedAmount;
    bool public _pausedTransferToNativeTargetAddress;
    bool public _pausedTransferToNativeFromKey;
    uint256 public _earliestDelete;

    modifier belowEqualValue(uint256 amount, uint256 threshold) {
        require(amount <= threshold, "Value too high");
        _;
    }

    modifier aboveEqualValue(uint256 amount, uint256 threshold) {
        require(amount >= threshold, "Value too low");
        _;
    }

    /* Simple length check. Length of FET addresses seem to be either 49 or
        50 bytes. Adding a slight margin to this. A proper checksum validation would require a base58
        decoder.*/
    modifier isFetchAddress(string memory _address) {
        require(bytes(_address).length > 47, "Address too short");
        require(bytes(_address).length < 52, "Address too long");
        _;
    }

    modifier onlySender(uint256 id) {
        require(swaps[id].sender == msg.sender, "Not the sender");
        _;
    }

    /* Only callable by owner or delegate */
    modifier onlyDelegate() {
        require(isOwner() || delegates[msg.sender], "Caller is neither owner nor delegate");
        _;
    }

    modifier isEqual(uint256 a, uint256 b) {
        require(a == b, "Different values");
        _;
    }

    modifier whenNotPaused(bool pauseIndicator) {
        require(!pauseIndicator, "Transfers are paused");
        _;
    }

    modifier isRejected(uint256 id) {
        require(swaps[id].status == Status.Rejected, "The swap has not been rejected");
        _;
    }

    modifier isInitialised(uint256 id){
        require(swaps[id].status == Status.Initialised, "The swap has not been initialised");
        _;
    }

    event SwapInitialised(address indexed sender, uint256 indexed id, string FETAddress, uint256 amount, uint256 fee);
    event Rejected(address indexed sender, uint256 indexed id, string reason);
    event Refund(address indexed sender, uint256 indexed id);
    event RefundRequested(address indexed sender, uint256 indexed id, uint256 amount);
    event PauseTransferToNativeTargetAddress(bool isPaused);
    event PauseTransferToNativeFromKey(bool isPaused);
    event ChangeDelegate(address delegate, bool isDelegate);
    event ChangeUpperTransferLimit(uint256 newLimit);
    event ChangeLowerTransferLimit(uint256 newLimit);
    event ChangeTransferFee(uint256 newFee);
    event DeleteContract();
    event WithdrawalToFoundation(uint256 amount);

    /*******************
    Contract start
    *******************/
    /**
     * @param ERC20Address address of the ERC20 contract
     */
    constructor(address ERC20Address) public {
        token = ERC20(ERC20Address);
        _upperTransferLimit = FET_TOTAL_SUPPLY;
        _lowerTransferLimit = 0;
        _transferFee = 0;
        _pausedTransferToNativeTargetAddress = false;
        _pausedTransferToNativeFromKey = false;
    }

    /**
     * @notice Return a unit that is divisible by the Fetch mainnet precision
     */
    function _toNativeFET(uint256 amount)
    internal
    pure
    returns (uint256 amountInt)
    {
        return amount.sub(amount.mod(DECIMAL_DIFFERENTIATOR));
    }

    /**
     * @notice Initialise a swap. Internal only.
     */
    function _initSwap(uint256 amount, string memory FETAddress)
    internal
    belowEqualValue(amount, _upperTransferLimit)
    aboveEqualValue(amount, _lowerTransferLimit)
    aboveEqualValue(amount, _transferFee)
    {
        uint256 id = globalSwapID;
        globalSwapID = globalSwapID.add(1);

        uint256 amountInt = _toNativeFET(amount.sub(_transferFee));

        swaps[id].sender = msg.sender;
        swaps[id].amount = amountInt;
        swaps[id].status = Status.Initialised;
        swaps[id].fee = _transferFee;

        _completedAmount = _completedAmount.add(amountInt).add(_transferFee);
        _earliestDelete = block.timestamp.add(DELETE_PERIOD);

        require(token.transferFrom(msg.sender, address(this), amountInt.add(_transferFee)));

        emit SwapInitialised(msg.sender, id, FETAddress, amountInt, _transferFee);
    }

    /**
     * @notice Initialise a swap to an address on the Fetch mainnet
     * @param amount amount to transfer. Must be below _upperTransferLimit
     * @param FETAddress public target address on the Fetch mainnet to transfer the tokens to
     * @dev Disregards fractions of FET due to precision differences
     * @dev The transfer of ERC20 tokens requires to first approve this transfer with the ERC20
        contract by calling ERC20.approve(contractAddress, amount)
     */
    function transferToNativeTargetAddress(uint256 amount, string calldata FETAddress)
    external
    isFetchAddress(FETAddress)
    whenNotPaused(_pausedTransferToNativeTargetAddress)
    {
        _initSwap(amount, FETAddress);
    }

    /**
     * @notice Initialise a swap to an address on the Fetch mainnet that corresponds to the same
        private key as used to control the address invoking this address
     * @param amount amount to transfer. Must be below _upperTransferLimit
     * @dev Disregards fractions of FET due to precision differences
     * @dev The transfer of ERC20 tokens requires to first approve this transfer with the ERC20
        contract by calling ERC20.approve(contractAddress, amount)
     */
    function transferToNativeFromKey(uint256 amount)
    external
    whenNotPaused(_pausedTransferToNativeFromKey)
    {
        _initSwap(amount, "");
    }

    /**
     * @notice Reclaim tokens of a swap that has been rejected
     * @param id id of the swap to refund
     */
    function refund(uint256 id)
    external
    isRejected(id)
    onlySender(id)
    {
        uint256 amount = swaps[id].amount.add(swaps[id].fee);
        emit Refund(msg.sender, id);
        delete swaps[id];
        require(token.transfer(msg.sender, amount));
    }

    /**
     * @notice Request that a refund be issued. Allows users to "complain" and remind the automated
     * server that it might have missed an event somewhere and should try reprocessing it
     * @param id id of the swap to refund
     */
    function requestRefund(uint256 id)
    external
    isInitialised(id)
    onlySender(id)
    {
        emit RefundRequested(msg.sender, id, swaps[id].amount);
    }

    /*******************
    Restricted functions
    *******************/
    /**
     * @notice Pause or unpause the transferToNativeTargetAddress() method
     * @param isPaused whether to pause or unpause the method
     * @dev Delegate only
     */
    function pauseTransferToNativeTargetAddress(bool isPaused)
    external
    onlyDelegate()
    {
        _pausedTransferToNativeTargetAddress = isPaused;
        emit PauseTransferToNativeTargetAddress(isPaused);
    }

    /**
     * @notice Pause or unpause the transferToNativeFromKey() method
     * @param isPaused whether to pause or unpause the method
     * @dev Delegate only
     */
    function pauseTransferToNativeFromKey(bool isPaused)
    external
    onlyDelegate()
    {
        _pausedTransferToNativeFromKey = isPaused;
        emit PauseTransferToNativeFromKey(isPaused);
    }

    /**
     * @notice Add or remove a delegate address that is allowed to confirm and reject transactions
     * @param _address address of the delegate
     * @param isDelegate whether to add or remove the address from the delegates set
     * @dev Owner only
     */
    function setDelegate(address _address, bool isDelegate)
    external
    onlyOwner()
    {
        delegates[_address] = isDelegate;
        emit ChangeDelegate(_address, isDelegate);
    }

    /**
     * @notice Change the _upperTransferLimit which is the maximum threshold any single swap can be
     * @param newLimit new limit in FET * 10**18
     * @dev Owner only
     */
    function setUpperTransferLimit(uint256 newLimit)
    external
    onlyOwner()
    belowEqualValue(newLimit, FET_TOTAL_SUPPLY)
    aboveEqualValue(newLimit, _lowerTransferLimit)
    {
        _upperTransferLimit = newLimit;
        emit ChangeUpperTransferLimit(newLimit);
    }

    /**
     * @notice Change the _lowerTransferLimit which is the minimum threshold any single swap can be
     * @param newLimit new limit in FET * 10**18
     * @dev Owner only
     */
    function setLowerTransferLimit(uint256 newLimit)
    external
    onlyOwner()
    belowEqualValue(newLimit, _upperTransferLimit)
    {
        _lowerTransferLimit = newLimit;
        emit ChangeLowerTransferLimit(newLimit);
    }

    /**
     * @notice Change the _transferFee which is the fee applied to every initialised swap
     * @param newFee in FET * 10**18
     * @dev This fee will be refunded if the swap is rejected
     * @dev Owner only
     */
    function setTransferFee(uint256 newFee)
    external
    onlyOwner()
    {
        _transferFee = newFee;
        emit ChangeTransferFee(newFee);
    }

    function _reject(address sender, uint256 id, uint256 expirationBlock, string memory reason)
    internal
    isInitialised(id)
    belowEqualValue(block.number, expirationBlock)
    {
        emit Rejected(sender, id, reason);
        swaps[id].status = Status.Rejected;
        _completedAmount = _completedAmount.sub(swaps[id].amount).sub(swaps[id].fee);
    }

    /**
     * @notice Reject a swap with reason. Allows the initialiser to immediately withdraw the funds again
     * @param sender initialiser of the swap
     * @param id id of the swap
     * @param reason reason for rejection
     * @dev delegate only
     */
    function reject(address sender, uint256 id, uint256 expirationBlock, string calldata reason)
    external
    onlyDelegate()
    {
        _reject(sender, id, expirationBlock, reason);
    }

    /**
     * @notice Reject multiple swaps with the same reason
     * @param senders array of sender addresses
     * @param _ids array of swap id's
     * @param reason Reason for the rejection. Will be identical across all swaps due to string[]
        being only an experimental feature
     * @dev delegate only
     */
    function batchReject(address[] calldata senders,
        uint256[] calldata _ids,
        uint256[] calldata expirationBlocks,
        string calldata reason)
    external
    onlyDelegate()
    isEqual(senders.length, _ids.length)
    isEqual(senders.length, expirationBlocks.length)
    {
        for (uint256 i = 0; i < senders.length; i++) {
            _reject(senders[i], _ids[i], expirationBlocks[i], reason);
        }
    }

    /**
     * @notice Withdraw the tokens the confirmed swaps to the owner
     * @param _amount amount to withdraw. Set to zero to withdraw all.
     * @dev owner only
     */
    function withdrawToFoundation(uint256 _amount)
    external
    onlyOwner()
    belowEqualValue(_amount, _completedAmount)
    {
        uint256 amount;
        if (_amount == 0) {
            amount = _completedAmount;
        } else {
            amount = _amount;
        }
        _completedAmount = _completedAmount.sub(amount);
        require(token.transfer(owner(), amount));
        emit WithdrawalToFoundation(amount);
    }

    /**
     * @notice Fallback function that allows to increase _completedAmount if the foundation should
     *  ever withdraw more than required to refund rejected swaps
     * @param amount amount to increase _completedAmount by
     */
    function topupCompletedAmount(uint256 amount)
    external
    {
        _completedAmount = _completedAmount.add(amount);
        require(token.transferFrom(msg.sender, address(this), amount));
    }

    /**
     * @notice Delete the contract after _earliestDelete timestamp is reached, transfers the remaining
        token and ether balance to the specified payoutAddress
     * @param payoutAddress address to transfer the balances to. Ensure that this is able to handle ERC20 tokens
     * @dev owner only
     */
    function deleteContract(address payable payoutAddress)
    external
    onlyOwner()
    {
        require(block.timestamp >= _earliestDelete, "earliestDelete not reached");
        uint256 contractBalance = token.balanceOf(address(this));
        require(token.transfer(payoutAddress, contractBalance));
        emit DeleteContract();
        selfdestruct(payoutAddress);
    }

}