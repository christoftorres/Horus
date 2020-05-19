// ----------------------------------------------------------
// TakeOff Payment for MINE Token
// Website: Work MINE Vision 
// https://workmine.vision <info@workmine.vision>
// VisualEarth OÜ <info@visualearth.eu>
// ----------------------------------------------------------
// Supported by TakeOff Technology OÜ <info@takeoff.center>
// Website: https://takeoff.center
// ----------------------------------------------------------
// TakeOff Payment contract is licensed under the MIT License
// Copyright (c) 2019 TakeOff Technology OÜ 
// ----------------------------------------------------------
// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// ----------------------------------------------------------


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\token\ERC20\IERC20.sol

pragma solidity ^0.5.0;

/**
 * @dev Interface of the ERC20 standard as defined in the EIP. Does not include
 * the optional functions; to access them see {ERC20Detailed}.
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
     * Emits a {Transfer} event.
     */
    function transfer(address recipient, uint256 amount) external returns (bool);

    /**
     * @dev Returns the remaining number of tokens that `spender` will be
     * allowed to spend on behalf of `owner` through {transferFrom}. This is
     * zero by default.
     *
     * This value changes when {approve} or {transferFrom} are called.
     */
    function allowance(address owner, address spender) external view returns (uint256);

    /**
     * @dev Sets `amount` as the allowance of `spender` over the caller's tokens.
     *
     * Returns a boolean value indicating whether the operation succeeded.
     *
     * IMPORTANT: Beware that changing an allowance with this method brings the risk
     * that someone may use both the old and the new allowance by unfortunate
     * transaction ordering. One possible solution to mitigate this race
     * condition is to first reduce the spender's allowance to 0 and set the
     * desired value afterwards:
     * https://github.com/ethereum/EIPs/issues/20#issuecomment-263524729
     *
     * Emits an {Approval} event.
     */
    function approve(address spender, uint256 amount) external returns (bool);

    /**
     * @dev Moves `amount` tokens from `sender` to `recipient` using the
     * allowance mechanism. `amount` is then deducted from the caller's
     * allowance.
     *
     * Returns a boolean value indicating whether the operation succeeded.
     *
     * Emits a {Transfer} event.
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
     * a call to {approve}. `value` is the new allowance.
     */
    event Approval(address indexed owner, address indexed spender, uint256 value);
}

// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\math\SafeMath.sol

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
        return sub(a, b, "SafeMath: subtraction overflow");
    }

    /**
     * @dev Returns the subtraction of two unsigned integers, reverting with custom message on
     * overflow (when the result is negative).
     *
     * Counterpart to Solidity's `-` operator.
     *
     * Requirements:
     * - Subtraction cannot overflow.
     *
     * _Available since v2.4.0._
     */
    function sub(uint256 a, uint256 b, string memory errorMessage) internal pure returns (uint256) {
        require(b <= a, errorMessage);
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
        // See: https://github.com/OpenZeppelin/openzeppelin-contracts/pull/522
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
        return div(a, b, "SafeMath: division by zero");
    }

    /**
     * @dev Returns the integer division of two unsigned integers. Reverts with custom message on
     * division by zero. The result is rounded towards zero.
     *
     * Counterpart to Solidity's `/` operator. Note: this function uses a
     * `revert` opcode (which leaves remaining gas untouched) while Solidity
     * uses an invalid opcode to revert (consuming all remaining gas).
     *
     * Requirements:
     * - The divisor cannot be zero.
     *
     * _Available since v2.4.0._
     */
    function div(uint256 a, uint256 b, string memory errorMessage) internal pure returns (uint256) {
        // Solidity only automatically asserts when dividing by 0
        require(b > 0, errorMessage);
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
        return mod(a, b, "SafeMath: modulo by zero");
    }

    /**
     * @dev Returns the remainder of dividing two unsigned integers. (unsigned integer modulo),
     * Reverts with custom message when dividing by zero.
     *
     * Counterpart to Solidity's `%` operator. This function uses a `revert`
     * opcode (which leaves remaining gas untouched) while Solidity uses an
     * invalid opcode to revert (consuming all remaining gas).
     *
     * Requirements:
     * - The divisor cannot be zero.
     *
     * _Available since v2.4.0._
     */
    function mod(uint256 a, uint256 b, string memory errorMessage) internal pure returns (uint256) {
        require(b != 0, errorMessage);
        return a % b;
    }
}


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\utils\Address.sol

pragma solidity ^0.5.5;

/**
 * @dev Collection of functions related to the address type
 */
library Address {
    /**
     * @dev Returns true if `account` is a contract.
     *
     * This test is non-exhaustive, and there may be false-negatives: during the
     * execution of a contract's constructor, its address will be reported as
     * not containing a contract.
     *
     * IMPORTANT: It is unsafe to assume that an address for which this
     * function returns false is an externally-owned account (EOA) and not a
     * contract.
     */
    function isContract(address account) internal view returns (bool) {
        // This method relies in extcodesize, which returns 0 for contracts in
        // construction, since the code is only stored at the end of the
        // constructor execution.

        // According to EIP-1052, 0x0 is the value returned for not-yet created accounts
        // and 0xc5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470 is returned
        // for accounts without code, i.e. `keccak256('')`
        bytes32 codehash;
        bytes32 accountHash = 0xc5d2460186f7233c927e7db2dcc703c0e500b653ca82273b7bfad8045d85a470;
        // solhint-disable-next-line no-inline-assembly
        assembly { codehash := extcodehash(account) }
        return (codehash != 0x0 && codehash != accountHash);
    }

    /**
     * @dev Converts an `address` into `address payable`. Note that this is
     * simply a type cast: the actual underlying value is not changed.
     *
     * _Available since v2.4.0._
     */
    function toPayable(address account) internal pure returns (address payable) {
        return address(uint160(account));
    }

    /**
     * @dev Replacement for Solidity's `transfer`: sends `amount` wei to
     * `recipient`, forwarding all available gas and reverting on errors.
     *
     * https://eips.ethereum.org/EIPS/eip-1884[EIP1884] increases the gas cost
     * of certain opcodes, possibly making contracts go over the 2300 gas limit
     * imposed by `transfer`, making them unable to receive funds via
     * `transfer`. {sendValue} removes this limitation.
     *
     * https://diligence.consensys.net/posts/2019/09/stop-using-soliditys-transfer-now/[Learn more].
     *
     * IMPORTANT: because control is transferred to `recipient`, care must be
     * taken to not create reentrancy vulnerabilities. Consider using
     * {ReentrancyGuard} or the
     * https://solidity.readthedocs.io/en/v0.5.11/security-considerations.html#use-the-checks-effects-interactions-pattern[checks-effects-interactions pattern].
     *
     * _Available since v2.4.0._
     */
    function sendValue(address payable recipient, uint256 amount) internal {
        require(address(this).balance >= amount, "Address: insufficient balance");

        // solhint-disable-next-line avoid-call-value
        (bool success, ) = recipient.call.value(amount)("");
        require(success, "Address: unable to send value, recipient may have reverted");
    }
}


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\token\ERC20\SafeERC20.sol

pragma solidity ^0.5.0;

/**
 * @title SafeERC20
 * @dev Wrappers around ERC20 operations that throw on failure (when the token
 * contract returns false). Tokens that return no value (and instead revert or
 * throw on failure) are also supported, non-reverting calls are assumed to be
 * successful.
 * To use this library you can add a `using SafeERC20 for ERC20;` statement to your contract,
 * which allows you to call the safe operations as `token.safeTransfer(...)`, etc.
 */
library SafeERC20 {
    using SafeMath for uint256;
    using Address for address;

    function safeTransfer(IERC20 token, address to, uint256 value) internal {
        callOptionalReturn(token, abi.encodeWithSelector(token.transfer.selector, to, value));
    }

    function safeTransferFrom(IERC20 token, address from, address to, uint256 value) internal {
        callOptionalReturn(token, abi.encodeWithSelector(token.transferFrom.selector, from, to, value));
    }

    function safeApprove(IERC20 token, address spender, uint256 value) internal {
        // safeApprove should only be called when setting an initial allowance,
        // or when resetting it to zero. To increase and decrease it, use
        // 'safeIncreaseAllowance' and 'safeDecreaseAllowance'
        // solhint-disable-next-line max-line-length
        require((value == 0) || (token.allowance(address(this), spender) == 0),
            "SafeERC20: approve from non-zero to non-zero allowance"
        );
        callOptionalReturn(token, abi.encodeWithSelector(token.approve.selector, spender, value));
    }

    function safeIncreaseAllowance(IERC20 token, address spender, uint256 value) internal {
        uint256 newAllowance = token.allowance(address(this), spender).add(value);
        callOptionalReturn(token, abi.encodeWithSelector(token.approve.selector, spender, newAllowance));
    }

    function safeDecreaseAllowance(IERC20 token, address spender, uint256 value) internal {
        uint256 newAllowance = token.allowance(address(this), spender).sub(value, "SafeERC20: decreased allowance below zero");
        callOptionalReturn(token, abi.encodeWithSelector(token.approve.selector, spender, newAllowance));
    }

    /**
     * @dev Imitates a Solidity high-level call (i.e. a regular function call to a contract), relaxing the requirement
     * on the return value: the return value is optional (but if data is returned, it must not be false).
     * @param token The token targeted by the call.
     * @param data The call data (encoded using abi.encode or one of its variants).
     */
    function callOptionalReturn(IERC20 token, bytes memory data) private {
        // We need to perform a low level call here, to bypass Solidity's return data size checking mechanism, since
        // we're implementing it ourselves.

        // A Solidity high level call has three parts:
        //  1. The target address is checked to verify it contains contract code
        //  2. The call itself is made, and success asserted
        //  3. The return value is decoded, which in turn checks the size of the returned data.
        // solhint-disable-next-line max-line-length
        require(address(token).isContract(), "SafeERC20: call to non-contract");

        // solhint-disable-next-line avoid-low-level-calls
        (bool success, bytes memory returndata) = address(token).call(data);
        require(success, "SafeERC20: low-level call failed");

        if (returndata.length > 0) { // Return data is optional
            // solhint-disable-next-line max-line-length
            require(abi.decode(returndata, (bool)), "SafeERC20: ERC20 operation did not succeed");
        }
    }
}


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\GSN\Context.sol

pragma solidity ^0.5.0;

/*
 * @dev Provides information about the current execution context, including the
 * sender of the transaction and its data. While these are generally available
 * via msg.sender and msg.data, they should not be accessed in such a direct
 * manner, since when dealing with GSN meta-transactions the account sending and
 * paying for execution may not be the actual sender (as far as an application
 * is concerned).
 *
 * This contract is only required for intermediate, library-like contracts.
 */
contract Context {
    // Empty internal constructor, to prevent people from mistakenly deploying
    // an instance of this contract, which should be used via inheritance.
    constructor () internal { }
    // solhint-disable-previous-line no-empty-blocks

    function _msgSender() internal view returns (address payable) {
        return msg.sender;
    }

    function _msgData() internal view returns (bytes memory) {
        this; // silence state mutability warning without generating bytecode - see https://github.com/ethereum/solidity/issues/2691
        return msg.data;
    }
}


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\access\Roles.sol

pragma solidity ^0.5.0;

/**
 * @title Roles
 * @dev Library for managing addresses assigned to a Role.
 */
library Roles {
    struct Role {
        mapping (address => bool) bearer;
    }

    /**
     * @dev Give an account access to this role.
     */
    function add(Role storage role, address account) internal {
        require(!has(role, account), "Roles: account already has role");
        role.bearer[account] = true;
    }

    /**
     * @dev Remove an account's access to this role.
     */
    function remove(Role storage role, address account) internal {
        require(has(role, account), "Roles: account does not have role");
        role.bearer[account] = false;
    }

    /**
     * @dev Check if an account has this role.
     * @return bool
     */
    function has(Role storage role, address account) internal view returns (bool) {
        require(account != address(0), "Roles: account is the zero address");
        return role.bearer[account];
    }
}


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\access\roles\PauserRole.sol

pragma solidity ^0.5.0;



contract PauserRole is Context {
    using Roles for Roles.Role;

    event PauserAdded(address indexed account);
    event PauserRemoved(address indexed account);

    Roles.Role private _pausers;

    constructor () internal {
        _addPauser(_msgSender());
    }

    modifier onlyPauser() {
        require(isPauser(_msgSender()), "PauserRole: caller does not have the Pauser role");
        _;
    }

    function isPauser(address account) public view returns (bool) {
        return _pausers.has(account);
    }

    function addPauser(address account) public onlyPauser {
        _addPauser(account);
    }

    function renouncePauser() public {
        _removePauser(_msgSender());
    }

    function _addPauser(address account) internal {
        _pausers.add(account);
        emit PauserAdded(account);
    }

    function _removePauser(address account) internal {
        _pausers.remove(account);
        emit PauserRemoved(account);
    }
}


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\lifecycle\Pausable.sol

pragma solidity ^0.5.0;



/**
 * @dev Contract module which allows children to implement an emergency stop
 * mechanism that can be triggered by an authorized account.
 *
 * This module is used through inheritance. It will make available the
 * modifiers `whenNotPaused` and `whenPaused`, which can be applied to
 * the functions of your contract. Note that they will not be pausable by
 * simply including this module, only once the modifiers are put in place.
 */
contract Pausable is Context, PauserRole {
    /**
     * @dev Emitted when the pause is triggered by a pauser (`account`).
     */
    event Paused(address account);

    /**
     * @dev Emitted when the pause is lifted by a pauser (`account`).
     */
    event Unpaused(address account);

    bool private _paused;

    /**
     * @dev Initializes the contract in unpaused state. Assigns the Pauser role
     * to the deployer.
     */
    constructor () internal {
        _paused = false;
    }

    /**
     * @dev Returns true if the contract is paused, and false otherwise.
     */
    function paused() public view returns (bool) {
        return _paused;
    }

    /**
     * @dev Modifier to make a function callable only when the contract is not paused.
     */
    modifier whenNotPaused() {
        require(!_paused, "Pausable: paused");
        _;
    }

    /**
     * @dev Modifier to make a function callable only when the contract is paused.
     */
    modifier whenPaused() {
        require(_paused, "Pausable: not paused");
        _;
    }

    /**
     * @dev Called by a pauser to pause, triggers stopped state.
     */
    function pause() public onlyPauser whenNotPaused {
        _paused = true;
        emit Paused(_msgSender());
    }

    /**
     * @dev Called by a pauser to unpause, returns to normal state.
     */
    function unpause() public onlyPauser whenPaused {
        _paused = false;
        emit Unpaused(_msgSender());
    }
}


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\ownership\Ownable.sol

pragma solidity ^0.5.0;

/**
 * @dev Contract module which provides a basic access control mechanism, where
 * there is an account (an owner) that can be granted exclusive access to
 * specific functions.
 *
 * This module is used through inheritance. It will make available the modifier
 * `onlyOwner`, which can be applied to your functions to restrict their use to
 * the owner.
 */
contract Ownable is Context {
    address private _owner;

    event OwnershipTransferred(address indexed previousOwner, address indexed newOwner);

    /**
     * @dev Initializes the contract setting the deployer as the initial owner.
     */
    constructor () internal {
        _owner = _msgSender();
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
        return _msgSender() == _owner;
    }

    /**
     * @dev Leaves the contract without owner. It will not be possible to call
     * `onlyOwner` functions anymore. Can only be called by the current owner.
     *
     * NOTE: Renouncing ownership will leave the contract without an owner,
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


// OpenZeppelin/openzeppelin-contracts is licensed under the MIT License
// Copyright (c) 2016-2019 zOS Global Limited
// File: contracts\lib\openzeppelin\cryptography\ECDSA.sol

pragma solidity ^0.5.0;

/**
 * @dev Elliptic Curve Digital Signature Algorithm (ECDSA) operations.
 *
 * These functions can be used to verify that a message was signed by the holder
 * of the private keys of a given address.
 */
library ECDSA {
    /**
     * @dev Returns the address that signed a hashed message (`hash`) with
     * `signature`. This address can then be used for verification purposes.
     *
     * The `ecrecover` EVM opcode allows for malleable (non-unique) signatures:
     * this function rejects them by requiring the `s` value to be in the lower
     * half order, and the `v` value to be either 27 or 28.
     *
     * NOTE: This call _does not revert_ if the signature is invalid, or
     * if the signer is otherwise unable to be retrieved. In those scenarios,
     * the zero address is returned.
     *
     * IMPORTANT: `hash` _must_ be the result of a hash operation for the
     * verification to be secure: it is possible to craft signatures that
     * recover to arbitrary addresses for non-hashed data. A safe way to ensure
     * this is by receiving a hash of the original message (which may otherwise
     * be too long), and then calling {toEthSignedMessageHash} on it.
     */
    function recover(bytes32 hash, bytes memory signature) internal pure returns (address) {
        // Check the signature length
        if (signature.length != 65) {
            return (address(0));
        }

        // Divide the signature in r, s and v variables
        bytes32 r;
        bytes32 s;
        uint8 v;

        // ecrecover takes the signature parameters, and the only way to get them
        // currently is to use assembly.
        // solhint-disable-next-line no-inline-assembly
        assembly {
            r := mload(add(signature, 0x20))
            s := mload(add(signature, 0x40))
            v := byte(0, mload(add(signature, 0x60)))
        }

        // EIP-2 still allows signature malleability for ecrecover(). Remove this possibility and make the signature
        // unique. Appendix F in the Ethereum Yellow paper (https://ethereum.github.io/yellowpaper/paper.pdf), defines
        // the valid range for s in (281): 0 < s < secp256k1n ﾃｷ 2 + 1, and for v in (282): v 竏・{27, 28}. Most
        // signatures from current libraries generate a unique signature with an s-value in the lower half order.
        //
        // If your library generates malleable signatures, such as s-values in the upper range, calculate a new s-value
        // with 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141 - s1 and flip v from 27 to 28 or
        // vice versa. If your library also generates signatures with 0/1 for v instead 27/28, add 27 to v to accept
        // these malleable signatures as well.
        if (uint256(s) > 0x7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF5D576E7357A4501DDFE92F46681B20A0) {
            return address(0);
        }

        if (v != 27 && v != 28) {
            return address(0);
        }

        // If the signature is valid (and not malleable), return the signer address
        return ecrecover(hash, v, r, s);
    }

    /**
     * @dev Returns an Ethereum Signed Message, created from a `hash`. This
     * replicates the behavior of the
     * https://github.com/ethereum/wiki/wiki/JSON-RPC#eth_sign[`eth_sign`]
     * JSON-RPC method.
     *
     * See {recover}.
     */
    function toEthSignedMessageHash(bytes32 hash) internal pure returns (bytes32) {
        // 32 is the length in bytes of hash,
        // enforced by the type signature above
        return keccak256(abi.encodePacked("\x19Ethereum Signed Message:\n32", hash));
    }
}


// TakeOff Payment contract is licensed under the MIT License
// Copyright (c) 2019 TakeOff Technology OÜ 
// File: contracts\Payment.sol

pragma solidity ^0.5.0;

contract Payment is Pausable, Ownable
{
    using SafeMath for uint256;
    using SafeERC20 for IERC20;

    // INVOICE SCHEMA HASH
    bytes32 constant private INVOICE_SCHEMA_HASH = 0x9b5fecc7f7fca49a5a75b168891cd29e66acc9e7e59c8e35e08e0c078a5aebf2;

    // ETH dummy address
    address constant private  ETH_TOKEN_ADDRESS = 0xEeeeeEeeeEeEeeEeEeEeeEEEeeeeEeeeeeeeEEeE;

    // Signer Address
    address private _signer;

    // Seller Address / Token Address
    address payable private _sellerAddress;
    address private _tokenAddress;

    // Event
    event SignerChanged(address indexed signer);
    event SellerAddressChanged(address indexed sellerAddress);
    event TokenAddressChanged(address indexed tokenAddress);
    event TokenPurchased(address indexed buyerAddress, address tokenAddress, uint256 tokenAmount, bytes32 hash);

    // Invoice structure
    struct Invoice{
        address buyerAddress;
        address sellerAddress;
        address tokenAddress;
        uint256 tokenUnitPrice;
        uint256 tokenAmount;
        address paymentTokenAddress;
        uint256 paymentTokenRate;
        uint256 paymentTokenAmount;
        uint256 expirationTimeSeconds;
        uint256 salt;
    }

    /// @dev Contract constructor sets initial seller and token address
    constructor (address payable sellerAddress, address tokenAddress)
        public
    {
        _signer = msg.sender;
        emit SignerChanged(_signer);

        _sellerAddress = sellerAddress;
        emit SellerAddressChanged(_sellerAddress);

        _tokenAddress = tokenAddress;
        emit TokenAddressChanged(_tokenAddress);
    }

    /**
     * @dev fallback function is not payable 
     */
    function () external {
    }

    /// @dev Check out the invoice with paying ETH.    
    function checkoutWithETH(
            address buyerAddress,
            address payable sellerAddress,
            address tokenAddress,
            uint256 tokenUnitPrice,
            uint256 tokenAmount,
            address paymentTokenAddress,
            uint256 paymentTokenRate,
            uint256 paymentTokenAmount,
            uint256 expirationTimeSeconds,
            uint256 salt,
            bytes32 hash,
            bytes memory signature
        )
        public
        payable
        whenNotPaused
    {

        Invoice memory invoice = Invoice({
                                buyerAddress: buyerAddress,
                                sellerAddress: sellerAddress,
                                tokenAddress: tokenAddress,
                                tokenUnitPrice: tokenUnitPrice,
                                tokenAmount: tokenAmount,
                                paymentTokenAddress: paymentTokenAddress,
                                paymentTokenRate: paymentTokenRate,
                                paymentTokenAmount: paymentTokenAmount,
                                expirationTimeSeconds: expirationTimeSeconds,
                                salt: salt
                            });

        // check the hash
        bytes32 invoiceHash = _getStructHash(invoice);
        require(invoiceHash == hash, "invoice hash does not match");

        // check signature
        require(_isValidSignature(hash, signature) == true, "invoice signature is invalid");
        
        // check invoice
        require(_isValidInvoice(invoice) == true, "invoice is invalid");

        // prepare token && allowance check
        IERC20 token = IERC20(_tokenAddress);
        require(token.allowance(_sellerAddress, address(this)) >= invoice.tokenAmount, "insufficient token allowance");

        // payment amount check
        require(ETH_TOKEN_ADDRESS == invoice.paymentTokenAddress, "_ETH_ payment token address is invalid");
        require(msg.value == invoice.paymentTokenAmount, "insufficient ETH payment");

        // ETH/Token swap execute 
        token.safeTransferFrom(_sellerAddress, invoice.buyerAddress, invoice.tokenAmount);
        _sellerAddress.transfer(invoice.paymentTokenAmount);

        emit TokenPurchased(invoice.buyerAddress, invoice.tokenAddress, invoice.tokenAmount, invoiceHash);
    }

    /// @dev Check out the invoice with paying ETH.   
    function checkoutWithToken(
            address buyerAddress,
            address sellerAddress,
            address tokenAddress,
            uint256 tokenUnitPrice,
            uint256 tokenAmount,
            address paymentTokenAddress,
            uint256 paymentTokenRate,
            uint256 paymentTokenAmount,
            uint256 expirationTimeSeconds,
            uint256 salt,
            bytes32 hash,
            bytes memory signature
        ) 
        public
        whenNotPaused
    {

        Invoice memory invoice = Invoice({
                                buyerAddress: buyerAddress,
                                sellerAddress: sellerAddress,
                                tokenAddress: tokenAddress,
                                tokenUnitPrice: tokenUnitPrice,
                                tokenAmount: tokenAmount,
                                paymentTokenAddress: paymentTokenAddress,
                                paymentTokenRate: paymentTokenRate,
                                paymentTokenAmount: paymentTokenAmount,
                                expirationTimeSeconds: expirationTimeSeconds,
                                salt: salt
                            });

        // check the hash
        bytes32 invoiceHash = _getStructHash(invoice);
        require(invoiceHash == hash, "invoice hash does not match");

        // check signature
        require(_isValidSignature(hash, signature) == true, "invoice signature is invalid");
        
        // check invoice
        require(_isValidInvoice(invoice) == true, "invoice is invalid");

        // prepare token && allowance check
        IERC20 token = IERC20(_tokenAddress);
        require(token.allowance(_sellerAddress, address(this)) >= invoice.tokenAmount, "insufficient token allowance");

        // prepare payment token && allowance check
        IERC20 paymentToken = IERC20(invoice.paymentTokenAddress);
        require(paymentToken.allowance(invoice.buyerAddress, address(this)) >= invoice.paymentTokenAmount, "insufficient payment token allowance. please approval for the contract before checkout");

        // ETH/Token swap execute 
        token.safeTransferFrom(_sellerAddress, invoice.buyerAddress, invoice.tokenAmount);
        paymentToken.safeTransferFrom(invoice.buyerAddress, _sellerAddress, invoice.paymentTokenAmount);

        emit TokenPurchased(invoice.buyerAddress, invoice.tokenAddress, invoice.tokenAmount, invoiceHash);
    }

    /// @dev Validate the invoice
    /// @param invoice the invoice to check
    /// @return Whether the invoice is valid
    function _isValidInvoice(Invoice memory invoice)
        internal
        view
        returns (bool){

        // check fixed seller address
        require(invoice.sellerAddress != address(0), "seller address is the zero address");
        require(invoice.sellerAddress == _sellerAddress, "seller address is not the seller address of the contract");

        // check fixed token address
        require(invoice.tokenAddress != address(0), "token address is the zero address");
        require(invoice.tokenAddress == _tokenAddress, "token address is not the token address of the contract");

        // check buyer address
        require(invoice.buyerAddress != address(0), "buyer address is the zero address");
        require(invoice.buyerAddress == msg.sender, "buyer address is not msg.sender");

        // check payment token address
        require(invoice.paymentTokenAddress != address(0), "payment token address is the zero address");
        
        // expired check
        require(now < invoice.expirationTimeSeconds, "the invoice is expired. please refresh invoice and try again");

        return true;

    }

    /// @dev Get the signer address.
    /// @return Invoice signer adddress    
    function getSigner() 
        public
        view
        returns (address)
    {
        return _signer;
    }

    /// @dev Set the signer address.
    /// @param newSigner Invoice signer adddress
    function setSigner(address newSigner) 
        public
        onlyOwner
    {
        require(newSigner != address(0), "signer address is the zero address");

        _signer = newSigner;
        emit SignerChanged(_signer);
    }

    /// @dev Get the seller address.
    /// @return Token seller adddress
    function getSellerAddress() 
        public
        view
        returns (address)
    {
        return _sellerAddress;
    }

    /// @dev Set the seller address.
    /// @param newSellerAddress Token seller adddress
    function setSellerAddress(address payable newSellerAddress) 
        public
        onlyOwner
    {
        require(newSellerAddress != address(0), "seller address is the zero address");

        _sellerAddress = newSellerAddress;

        emit SellerAddressChanged(_sellerAddress);
    }

    /// @dev Get the token address.
    /// @return Token token adddress
    function getTokenAddress() 
        public
        view
        returns (address)
    {
        return _tokenAddress;
    }

    /// @dev Set the token address.
    /// @param newTokenAddress Token adddress
    function setTokenAddress(address newTokenAddress) 
        public
        onlyOwner
    {
        require(newTokenAddress != address(0), "token address is the zero address");

        _tokenAddress = newTokenAddress;

        emit TokenAddressChanged(_tokenAddress);
    }

    /// @dev Create hash of invoice struct
    /// @param invoice Invoice to be hashed
    /// @return hash of the invoice
    function _getStructHash(Invoice memory invoice)
        internal
        pure
        returns (bytes32)
    {
        return keccak256(abi.encode(
                INVOICE_SCHEMA_HASH,
                invoice.buyerAddress,
                invoice.sellerAddress,
                invoice.tokenAddress,
                invoice.tokenUnitPrice,
                invoice.tokenAmount,
                invoice.paymentTokenAddress,
                invoice.paymentTokenRate,
                invoice.paymentTokenAmount,
                invoice.expirationTimeSeconds,
                invoice.salt            
            ));
    }
    
    /// @dev Validate with hash and signature
    /// @param hash Message hash that is signed.
    /// @param signature Proof of signing.
    /// @return Whether the signature is by the signer
    function _isValidSignature(
        bytes32 hash,
        bytes memory signature
    )
        internal
        view
        returns (bool)
    {
        address signerAddress = ECDSA.recover(ECDSA.toEthSignedMessageHash(hash), signature);

        if(signerAddress != address(0) && signerAddress == _signer){
            return true;
        }else{
            return false;
        }
    }
}