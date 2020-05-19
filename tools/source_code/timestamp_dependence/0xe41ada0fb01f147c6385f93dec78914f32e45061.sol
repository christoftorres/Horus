// File: openzeppelin-solidity/contracts/token/ERC20/IERC20.sol

pragma solidity ^0.5.0;

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

// File: openzeppelin-solidity/contracts/math/SafeMath.sol

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

// File: openzeppelin-solidity/contracts/ownership/Ownable.sol

pragma solidity ^0.5.0;

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

// File: contracts/interfaces/Cosigner.sol

pragma solidity 0.5.12;


interface Cosigner {

    function cost(
        address engine,
        uint256 index,
        bytes calldata data,
        bytes calldata oracleData
    ) external view returns (uint256);

}

// File: contracts/common/ERC165.sol

pragma solidity ^0.5.12;


interface IERC165 {
    /// @notice Query if a contract implements an interface
    /// @param interfaceID The interface identifier, as specified in ERC-165
    /// @dev Interface identification is specified in ERC-165. This function
    ///  uses less than 30,000 gas.
    /// @return `true` if the contract implements `interfaceID` and
    ///  `interfaceID` is not 0xffffffff, `false` otherwise
    function supportsInterface(bytes4 interfaceID) external view returns (bool);
}

/**
 * @title ERC165
 * @author Matt Condon (@shrugs)
 * @dev Implements ERC165 using a lookup table.
 */
contract ERC165 is IERC165 {
    bytes4 private constant _InterfaceId_ERC165 = 0x01ffc9a7;
    /**
    * 0x01ffc9a7 ===
    *   bytes4(keccak256("supportsInterface(bytes4)"))
    */

    /**
    * @dev a mapping of interface id to whether or not it is supported
    */
    mapping(bytes4 => bool) private _supportedInterfaces;

    /**
    * @dev A contract implementing SupportsInterfaceWithLookup
    * implement ERC165 itself
    */
    constructor()
        internal
    {
        _registerInterface(_InterfaceId_ERC165);
    }

    /**
    * @dev implement supportsInterface(bytes4) using a lookup table
    */
    function supportsInterface(bytes4 interfaceId)
        external
        view
        returns (bool)
    {
        return _supportedInterfaces[interfaceId];
    }

    /**
    * @dev internal method for registering an interface
    */
    function _registerInterface(bytes4 interfaceId)
        internal
    {
        require(interfaceId != 0xffffffff, "Can not register 0xffffffff");
        _supportedInterfaces[interfaceId] = true;
    }
}

// File: contracts/interfaces/diaspore/Model.sol

pragma solidity ^0.5.12;



/**
    The abstract contract Model defines the whole lifecycle of a debt on the DebtEngine.

    Models can be used without previous approbation, this is meant
    to avoid centralization on the development of RCN; this implies that not all models are secure.
    Models can have back-doors, bugs and they have not guarantee of being autonomous.

    The DebtEngine is meant to be the User of this model,
    so all the methods with the ability to perform state changes should only be callable by the DebtEngine.

    All models should implement the 0xaf498c35 interface.

    @author Agustin Aguilar
*/
contract Model is IERC165 {
    // ///
    // Events
    // ///

    /**
        @dev This emits when create a new debt.
    */
    event Created(bytes32 indexed _id);

    /**
        @dev This emits when the status of debt change.

        @param _timestamp Timestamp of the registry
        @param _status New status of the registry
    */
    event ChangedStatus(bytes32 indexed _id, uint256 _timestamp, uint256 _status);

    /**
        @dev This emits when the obligation of debt change.

        @param _timestamp Timestamp of the registry
        @param _debt New debt of the registry
    */
    event ChangedObligation(bytes32 indexed _id, uint256 _timestamp, uint256 _debt);

    /**
        @dev This emits when the frequency of debt change.

        @param _timestamp Timestamp of the registry
        @param _frequency New frequency of each installment
    */
    event ChangedFrequency(bytes32 indexed _id, uint256 _timestamp, uint256 _frequency);

    /**
        @param _timestamp Timestamp of the registry
    */
    event ChangedDueTime(bytes32 indexed _id, uint256 _timestamp, uint256 _status);

    /**
        @param _timestamp Timestamp of the registry
        @param _dueTime New dueTime of each installment
    */
    event ChangedFinalTime(bytes32 indexed _id, uint256 _timestamp, uint64 _dueTime);

    /**
        @dev This emits when the call addDebt function.

        @param _amount New amount of the debt, old amount plus added
    */
    event AddedDebt(bytes32 indexed _id, uint256 _amount);

    /**
        @dev This emits when the call addPaid function.

        If the registry is fully paid on the call and the amount parameter exceeds the required
            payment amount, the event emits the real amount paid on the payment.

        @param _paid Real amount paid
    */
    event AddedPaid(bytes32 indexed _id, uint256 _paid);

    // Model interface selector
    bytes4 internal constant MODEL_INTERFACE = 0xaf498c35;

    uint256 public constant STATUS_ONGOING = 1;
    uint256 public constant STATUS_PAID = 2;
    uint256 public constant STATUS_ERROR = 4;

    // ///
    // Meta
    // ///

    /**
        @return Identifier of the model
    */
    function modelId() external view returns (bytes32);

    /**
        Returns the address of the contract used as Descriptor of the model

        @dev The descriptor contract should follow the ModelDescriptor.sol scheme

        @return Address of the descriptor
    */
    function descriptor() external view returns (address);

    /**
        If called for any address with the ability to modify the state of the model registries,
            this method should return True.

        @dev Some contracts may check if the DebtEngine is
            an operator to know if the model is operative or not.

        @param operator Address of the target request operator

        @return True if operator is able to modify the state of the model
    */
    function isOperator(address operator) external view returns (bool canOperate);

    /**
        Validates the data for the creation of a new registry, if returns True the
            same data should be compatible with the create method.

        @dev This method can revert the call or return false, and both meant an invalid data.

        @param data Data to validate

        @return True if the data can be used to create a new registry
    */
    function validate(bytes calldata data) external view returns (bool isValid);

    // ///
    // Getters
    // ///

    /**
        Exposes the current status of the registry. The possible values are:

        1: Ongoing - The debt is still ongoing and waiting to be paid
        2: Paid - The debt is already paid and
        4: Error - There was an Error with the registry

        @dev This method should always be called by the DebtEngine

        @param id Id of the registry

        @return The current status value
    */
    function getStatus(bytes32 id) external view returns (uint256 status);

    /**
        Returns the total paid amount on the registry.

        @dev it should equal to the sum of all real addPaid

        @param id Id of the registry

        @return Total paid amount
    */
    function getPaid(bytes32 id) external view returns (uint256 paid);

    /**
        If the returned amount does not depend on any interactions and only on the model logic,
            the defined flag will be True; if the amount is an estimation of the future debt,
            the flag will be set to False.

        If timestamp equals the current moment, the defined flag should always be True.

        @dev This can be a gas-intensive method to call, consider calling the run method before.

        @param id Id of the registry
        @param timestamp Timestamp of the obligation query

        @return amount Amount pending to pay on the given timestamp
        @return defined True If the amount returned is fixed and can't change
    */
    function getObligation(bytes32 id, uint64 timestamp) external view returns (uint256 amount, bool defined);

    /**
        The amount required to fully paid a registry.

        All registries should be payable in a single time, even when it has multiple installments.

        If the registry discounts interest for early payment, those discounts should be
            taken into account in the returned amount.

        @dev This can be a gas-intensive method to call, consider calling the run method before.

        @param id Id of the registry

        @return amount Amount required to fully paid the loan on the current timestamp
    */
    function getClosingObligation(bytes32 id) external view returns (uint256 amount);

    /**
        The timestamp of the next required payment.

        After this moment, if the payment goal is not met the debt will be considered overdue.

            The getObligation method can be used to know the required payment on the future timestamp.

        @param id Id of the registry

        @return timestamp The timestamp of the next due time
    */
    function getDueTime(bytes32 id) external view returns (uint256 timestamp);

    // ///
    // Metadata
    // ///

    /**
        If the loan has multiple installments returns the duration of each installment in seconds,
            if the loan has not installments it should return 1.

        @param id Id of the registry

        @return frequency Frequency of each installment
    */
    function getFrequency(bytes32 id) external view returns (uint256 frequency);

    /**
        If the loan has multiple installments returns the total of installments,
            if the loan has not installments it should return 1.

        @param id Id of the registry

        @return installments Total of installments
    */
    function getInstallments(bytes32 id) external view returns (uint256 installments);

    /**
        The registry could be paid before or after the date, but the debt will always be
            considered overdue if paid after this timestamp.

        This is the estimated final payment date of the debt if it is always paid on each exact dueTime.

        @param id Id of the registry

        @return timestamp Timestamp of the final due time
    */
    function getFinalTime(bytes32 id) external view returns (uint256 timestamp);

    /**
        Similar to getFinalTime returns the expected payment remaining if paid always on the exact dueTime.

        If the model has no interest discounts for early payments,
            this method should return the same value as getClosingObligation.

        @param id Id of the registry

        @return amount Expected payment amount
    */
    function getEstimateObligation(bytes32 id) external view returns (uint256 amount);

    // ///
    // State interface
    // ///

    /**
        Creates a new registry using the provided data and id, it should fail if the id already exists
            or if calling validate(data) returns false or throws.

        @dev This method should only be callable by an operator

        @param id Id of the registry to create
        @param data Data to construct the new registry

        @return success True if the registry was created
    */
    function create(bytes32 id, bytes calldata data) external returns (bool success);

    /**
        If the registry is fully paid on the call and the amount parameter exceeds the required
            payment amount, the method returns the real amount used on the payment.

        The payment taken should always be the same as the requested unless the registry
            is fully paid on the process.

        @dev This method should only be callable by an operator

        @param id If of the registry
        @param amount Amount to pay

        @return real Real amount paid
    */
    function addPaid(bytes32 id, uint256 amount) external returns (uint256 real);

    /**
        Adds a new amount to be paid on the debt model,
            each model can handle the addition of more debt freely.

        @dev This method should only be callable by an operator

        @param id Id of the registry
        @param amount Debt amount to add to the registry

        @return added True if the debt was added
    */
    function addDebt(bytes32 id, uint256 amount) external returns (bool added);

    // ///
    // Utils
    // ///

    /**
        Runs the internal clock of a registry, this is used to compute the last changes on the state.
            It can make transactions cheaper by avoiding multiple calculations when calling views.

        Not all models have internal clocks, a model without an internal clock should always return false.

        Calls to this method should be possible from any address,
            multiple calls to run shouldn"t affect the internal calculations of the model.

        @dev If the call had no effect the method would return False,
            that is no sign of things going wrong, and the call shouldn"t be wrapped on a require

        @param id If of the registry

        @return effect True if the run performed a change on the state
    */
    function run(bytes32 id) external returns (bool effect);
}

// File: contracts/interfaces/RateOracle.sol

pragma solidity 0.5.12;



/// @dev Defines the interface of a standard Diaspore RCN Oracle,
/// The contract should also implement it is ERC165 interface: 0xa265d8e0
/// @notice Each oracle can only support one currency
/// @author Agustin Aguilar
interface RateOracle {
    function readSample(bytes calldata _data) external returns (uint256 _tokens, uint256 _equivalent);
}

// File: contracts/interfaces/diaspore/DebtEngine.sol

pragma solidity ^0.5.12;




interface DebtEngine {
    function debts(
        bytes32 _id
    ) external view returns(
        bool error,
        uint128 balance,
        Model model,
        address creator,
        RateOracle oracle
    );

    function create(
        Model _model,
        address _owner,
        address _oracle,
        bytes calldata _data
    ) external returns (bytes32 id);

    function create2(
        Model _model,
        address _owner,
        address _oracle,
        uint256 _salt,
        bytes calldata _data
    ) external returns (bytes32 id);

    function create3(
        Model _model,
        address _owner,
        address _oracle,
        uint256 _salt,
        bytes calldata _data
    ) external returns (bytes32 id);

    function buildId(
        address _creator,
        uint256 _nonce
    ) external view returns (bytes32);

    function buildId2(
        address _creator,
        address _model,
        address _oracle,
        uint256 _salt,
        bytes calldata _data
    ) external view returns (bytes32);

    function buildId3(
        address _creator,
        uint256 _salt
    ) external view returns (bytes32);

    function pay(
        bytes32 _id,
        uint256 _amount,
        address _origin,
        bytes calldata _oracleData
    ) external returns (uint256 paid, uint256 paidToken);

    function payToken(
        bytes32 id,
        uint256 amount,
        address origin,
        bytes calldata oracleData
    ) external returns (uint256 paid, uint256 paidToken);

    function payBatch(
        bytes32[] calldata _ids,
        uint256[] calldata _amounts,
        address _origin,
        address _oracle,
        bytes calldata _oracleData
    ) external returns (uint256[] memory paid, uint256[] memory paidTokens);

    function payTokenBatch(
        bytes32[] calldata _ids,
        uint256[] calldata _tokenAmounts,
        address _origin,
        address _oracle,
        bytes calldata _oracleData
    ) external returns (uint256[] memory paid, uint256[] memory paidTokens);

    function withdraw(
        bytes32 _id,
        address _to
    ) external returns (uint256 amount);

    function withdrawPartial(
        bytes32 _id,
        address _to,
        uint256 _amount
    ) external returns (bool success);

    function withdrawBatch(
        bytes32[] calldata _ids,
        address _to
    ) external returns (uint256 total);

    function transferFrom(address _from, address _to, uint256 _assetId) external;

    function getStatus(bytes32 _id) external view returns (uint256);
}

// File: contracts/interfaces/diaspore/LoanManager.sol

pragma solidity 0.5.12;



contract LoanManager {
    IERC20 public token;

    function debtEngine() external view returns (DebtEngine);
    function getCurrency(uint256 _id) external view returns (bytes32);
    function getAmount(uint256 _id) external view returns (uint256);
    function getAmount(bytes32 _id) external view returns (uint256);
    function getOracle(uint256 _id) external view returns (address);

    function settleLend(
        bytes memory _requestData,
        bytes memory _loanData,
        address _cosigner,
        uint256 _maxCosignerCost,
        bytes memory _cosignerData,
        bytes memory _oracleData,
        bytes memory _creatorSig,
        bytes memory _borrowerSig
    ) public returns (bytes32 id);

    function lend(
        bytes32 _id,
        bytes memory _oracleData,
        address _cosigner,
        uint256 _cosignerLimit,
        bytes memory _cosignerData,
        bytes memory _callbackData
    ) public returns (bool);

}

// File: contracts/interfaces/TokenConverter.sol

pragma solidity 0.5.12;



interface TokenConverter {
    function convertFrom(
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _fromAmount,
        uint256 _minReceive
    ) external payable returns (uint256 _received);

    function convertTo(
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _toAmount,
        uint256 _maxSpend
    ) external payable returns (uint256 _spend);

    function getPriceConvertFrom(
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _fromAmount
    ) external view returns (uint256 _receive);

    function getPriceConvertTo(
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _toAmount
    ) external view returns (uint256 _spend);
}

// File: contracts/utils/SafeERC20.sol

pragma solidity ^0.5.12;



/**
* @dev Library to perform safe calls to standard method for ERC20 tokens.
*
* Why Transfers: transfer methods could have a return value (bool), throw or revert for insufficient funds or
* unathorized value.
*
* Why Approve: approve method could has a return value (bool) or does not accept 0 as a valid value (BNB token).
* The common strategy used to clean approvals.
*
* We use the Solidity call instead of interface methods because in the case of transfer, it will fail
* for tokens with an implementation without returning a value.
* Since versions of Solidity 0.4.22 the EVM has a new opcode, called RETURNDATASIZE.
* This opcode stores the size of the returned data of an external call. The code checks the size of the return value
* after an external call and reverts the transaction in case the return data is shorter than expected
* https://github.com/nachomazzara/SafeERC20/blob/master/contracts/libs/SafeERC20.sol
*/
library SafeERC20 {
    /**
    * @dev Transfer token for a specified address
    * @param _token erc20 The address of the ERC20 contract
    * @param _to address The address which you want to transfer to
    * @param _value uint256 the _value of tokens to be transferred
    * @return bool whether the transfer was successful or not
    */
    function safeTransfer(IERC20 _token, address _to, uint256 _value) internal returns (bool) {
        uint256 prevBalance = _token.balanceOf(address(this));

        if (prevBalance < _value) {
            // Insufficient funds
            return false;
        }

        (bool success,) = address(_token).call(
            abi.encodeWithSignature("transfer(address,uint256)", _to, _value)
        );

        if (!success || prevBalance - _value != _token.balanceOf(address(this))) {
            // Transfer failed
            return false;
        }

        return true;
    }

    /**
    * @dev Transfer tokens from one address to another
    * @param _token erc20 The address of the ERC20 contract
    * @param _from address The address which you want to send tokens from
    * @param _to address The address which you want to transfer to
    * @param _value uint256 the _value of tokens to be transferred
    * @return bool whether the transfer was successful or not
    */
    function safeTransferFrom(
        IERC20 _token,
        address _from,
        address _to,
        uint256 _value
    ) internal returns (bool)
    {
        uint256 prevBalance = _token.balanceOf(_from);

        if (prevBalance < _value) {
            // Insufficient funds
            return false;
        }

        if (_token.allowance(_from, address(this)) < _value) {
            // Insufficient allowance
            return false;
        }

        (bool success,) = address(_token).call(
            abi.encodeWithSignature("transferFrom(address,address,uint256)", _from, _to, _value)
        );

        if (!success || prevBalance - _value != _token.balanceOf(_from)) {
            // Transfer failed
            return false;
        }

        return true;
    }

   /**
   * @dev Approve the passed address to spend the specified amount of tokens on behalf of msg.sender.
   *
   * Beware that changing an allowance with this method brings the risk that someone may use both the old
   * and the new allowance by unfortunate transaction ordering. One possible solution to mitigate this
   * race condition is to first reduce the spender"s allowance to 0 and set the desired value afterwards:
   * https://github.com/ethereum/EIPs/issues/20#issuecomment-263524729
   *
   * @param _token erc20 The address of the ERC20 contract
   * @param _spender The address which will spend the funds.
   * @param _value The amount of tokens to be spent.
   * @return bool whether the approve was successful or not
   */
    function safeApprove(IERC20 _token, address _spender, uint256 _value) internal returns (bool) {
        (bool success,) = address(_token).call(
            abi.encodeWithSignature("approve(address,uint256)",_spender, _value)
        );

        if (!success && _token.allowance(address(this), _spender) != _value) {
            // Approve failed
            return false;
        }

        return true;
    }

   /**
   * @dev Clear approval
   * Note that if 0 is not a valid value it will be set to 1.
   * @param _token erc20 The address of the ERC20 contract
   * @param _spender The address which will spend the funds.
   */
    function clearApprove(IERC20 _token, address _spender) internal returns (bool) {
        bool success = safeApprove(_token, _spender, 0);

        if (!success) {
            success = safeApprove(_token, _spender, 1);
        }

        return success;
    }
}

// File: contracts/utils/SafeTokenConverter.sol

pragma solidity 0.5.12;






library SafeTokenConverter {
    IERC20 constant private ETH_TOKEN_ADDRESS = IERC20(0x00eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee);
    using SafeERC20 for IERC20;
    using SafeMath for uint256;

    function safeConvertFrom(
        TokenConverter _converter,
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _fromAmount,
        uint256 _minReceive
    ) internal returns (uint256 _received) {
        uint256 prevBalance = _selfBalance(_toToken);

        if (_fromToken == ETH_TOKEN_ADDRESS) {
            _converter.convertFrom.value(
                _fromAmount
            )(
                _fromToken,
                _toToken,
                _fromAmount,
                _minReceive
            );
        } else {
            require(_fromToken.safeApprove(address(_converter), _fromAmount), "error approving converter");
            _converter.convertFrom(
                _fromToken,
                _toToken,
                _fromAmount,
                _minReceive
            );

            require(_fromToken.clearApprove(address(_converter)), "error clearing approve");
        }

        _received = _selfBalance(_toToken).sub(prevBalance);
        require(_received >= _minReceive, "_minReceived not reached");
    }

    function safeConvertTo(
        TokenConverter _converter,
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _toAmount,
        uint256 _maxSpend
    ) internal returns (uint256 _spend) {
        uint256 prevFromBalance = _selfBalance(_fromToken);
        uint256 prevToBalance = _selfBalance(_toToken);

        if (_fromToken == ETH_TOKEN_ADDRESS) {
            _converter.convertTo.value(
                _maxSpend
            )(
                _fromToken,
                _toToken,
                _toAmount,
                _maxSpend
            );
        } else {
            require(_fromToken.safeApprove(address(_converter), _maxSpend), "error approving converter");
            _converter.convertTo(
                _fromToken,
                _toToken,
                _toAmount,
                _maxSpend
            );

            require(_fromToken.clearApprove(address(_converter)), "error clearing approve");
        }

        _spend = prevFromBalance.sub(_selfBalance(_fromToken));
        require(_spend <= _maxSpend, "_maxSpend exceeded");
        require(_selfBalance(_toToken).sub(prevToBalance) >= _toAmount, "_toAmount not received");
    }

    function _selfBalance(IERC20 _token) private view returns (uint256) {
        if (_token == ETH_TOKEN_ADDRESS) {
            return address(this).balance;
        } else {
            return _token.balanceOf(address(this));
        }
    }
}

// File: contracts/utils/Math.sol

pragma solidity 0.5.12;


library Math {
    function min(uint256 _a, uint256 _b) internal pure returns (uint256) {
        if (_a < _b) {
            return _a;
        } else {
            return _b;
        }
    }

    function divCeil(uint256 _a, uint256 _b) internal pure returns (uint256 c) {
        require(_b != 0, "div by zero");
        c = _a / _b;
        if (_a % _b != 0) {
            c = c + 1;
        }
    }
}

// File: contracts/ConverterRamp.sol

pragma solidity 0.5.12;













/// @title  Converter Ramp
/// @notice for conversion between different assets, use TokenConverter
///         contract as abstract layer for convert different assets.
/// @dev All function calls are currently implemented without side effects
contract ConverterRamp is Ownable {
    using SafeTokenConverter for TokenConverter;
    using SafeMath for uint256;
    using SafeERC20 for IERC20;
    using Math for uint256;

    /// @notice address to identify operations with ETH
    address public constant ETH_ADDRESS = address(0x00eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee);

    event Return(address _token, address _to, uint256 _amount);
    event ReadedOracle(address _oracle, uint256 _tokens, uint256 _equivalent);

    DebtEngine public debtEngine;
    LoanManager public loanManager;
    IERC20 public token;

    constructor(LoanManager _loanManager) public {
        loanManager = _loanManager;
        token = _loanManager.token();
        debtEngine = _loanManager.debtEngine();
    }

    function pay(
        TokenConverter _converter,
        IERC20 _fromToken,
        uint256 _payAmount,
        uint256 _maxSpend,
        bytes32 _requestId,
        bytes calldata _oracleData
    ) external payable {
        /// load RCN IERC20, we need it to pay
        DebtEngine _debtEngine = debtEngine;

        /// get amount required, in RCN, for payment
        uint256 amount = getRequiredRcnPay(
            _debtEngine,
            _requestId,
            _payAmount,
            _oracleData
        );

        // Pull funds from sender
        IERC20 _token = token;
        _pullConvertAndReturnExtra(
            _converter,
            _fromToken,
            _token,
            amount,
            _maxSpend
        );

        // Pay the loan
        // the debtEngine is trusted
        // so we can approve it only once
        _approveOnlyOnce(_token, address(_debtEngine), amount);

        // execute the payment
        (, uint256 paidToken) = debtEngine.payToken(_requestId, amount, msg.sender, _oracleData);

        // Convert any extra RCN
        // and send it back
        // it should not be reachable
        if (paidToken < amount) {
            _convertAndReturn(
                _converter,
                _token,
                _fromToken,
                amount - paidToken
            );
        }
    }

    function lend(
        TokenConverter _converter,
        IERC20 _fromToken,
        uint256 _maxSpend,
        address _cosigner,
        bytes32 _requestId,
        bytes memory _oracleData,
        bytes memory _cosignerData,
        bytes memory _callbackData
    ) public payable {
        /// load RCN IERC20
        LoanManager _loanManager = loanManager;

        /// get required RCN for lending the loan
        uint256 amount = getRequiredRcnLend(
            _loanManager,
            _cosigner,
            _requestId,
            _oracleData,
            _cosignerData
        );

        IERC20 _token = token;
        _pullConvertAndReturnExtra(
            _converter,
            _fromToken,
            _token,
            amount,
            _maxSpend
        );

        // approve token to loan manager only once
        // the loan manager is trusted
        _approveOnlyOnce(_token, address(_loanManager), amount);

        _loanManager.lend(
            _requestId,
            _oracleData,
            _cosigner,
            0,
            _cosignerData,
            _callbackData
        );

        // /// transfer loan to msg.sender
        debtEngine.transferFrom(address(this), msg.sender, uint256(_requestId));
    }

    function getLendCost(
        TokenConverter _converter,
        IERC20 _fromToken,
        address _cosigner,
        bytes32 _requestId,
        bytes calldata _oracleData,
        bytes calldata _cosignerData
    ) external returns (uint256) {
        uint256 amountRcn = getRequiredRcnLend(
            loanManager,
            _cosigner,
            _requestId,
            _oracleData,
            _cosignerData
        );

        return _converter.getPriceConvertTo(
            _fromToken,
            token,
            amountRcn
        );
    }

    /// @notice returns how much RCN is required for a given pay
    function getPayCost(
        TokenConverter _converter,
        IERC20 _fromToken,
        bytes32 _requestId,
        uint256 _amount,
        bytes calldata _oracleData
    ) external returns (uint256) {
        uint256 amountRcn = getRequiredRcnPay(
            debtEngine,
            _requestId,
            _amount,
            _oracleData
        );

        return _converter.getPriceConvertTo(
            _fromToken,
            token,
            amountRcn
        );
    }

    /// @notice returns how much RCN is required for a given lend
    function getRequiredRcnLend(
        LoanManager _loanManager,
        address _lenderCosignerAddress,
        bytes32 _requestId,
        bytes memory _oracleData,
        bytes memory _cosignerData
    ) internal returns (uint256) {

        /// load loan manager and id
        uint256 amount = loanManager.getAmount(_requestId);

        /// load cosigner of loan
        Cosigner cosigner = Cosigner(_lenderCosignerAddress);

        /// if loan has a cosigner, sum the cost
        if (_lenderCosignerAddress != address(0)) {
            amount = amount.add(cosigner.cost(address(_loanManager), uint256(_requestId), _cosignerData, _oracleData));
        }

        /// load the  Oracle rate and convert required
        address oracle = loanManager.getOracle(uint256(_requestId));
        return getCurrencyToToken(oracle, amount, _oracleData);
    }

    /// @notice returns how much RCN is required for a given pay
    function getRequiredRcnPay(
        DebtEngine _debtEngine,
        bytes32 _requestId,
        uint256 _amount,
        bytes memory _oracleData
    ) internal returns (uint256 _result) {
        (,,Model model,, RateOracle oracle) = _debtEngine.debts(_requestId);

        // Load amount to pay
        uint256 amount = Math.min(
            model.getClosingObligation(_requestId),
            _amount
        );

        /// Read loan oracle
        return getCurrencyToToken(address(oracle), amount, _oracleData);
    }

    /// @notice returns how much tokens for _amount currency
    /// @dev tokens and equivalents get oracle data
    function getCurrencyToToken(
        address _oracle,
        uint256 _amount,
        bytes memory _oracleData
    ) internal returns (uint256) {
        if (_oracle == address(0)) {
            return _amount;
        }

        (uint256 tokens, uint256 equivalent) = RateOracle(_oracle).readSample(_oracleData);

        emit ReadedOracle(_oracle, tokens, equivalent);
        return tokens.mul(_amount).divCeil(equivalent);
    }

    function getPriceConvertTo(
        TokenConverter _converter,
        IERC20 _fromToken,
        uint256 _amount
    ) external view returns (uint256) {
        return _converter.getPriceConvertTo(
            _fromToken,
            token,
            _amount
        );
    }

    function _convertAndReturn(
        TokenConverter _converter,
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _amount
    ) private {
        uint256 buyBack = _converter.safeConvertFrom(
            _fromToken,
            _toToken,
            _amount,
            1
        );

        require(_toToken.safeTransfer(msg.sender, buyBack), "error sending extra");
    }

    function _pullConvertAndReturnExtra(
        TokenConverter _converter,
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _amount,
        uint256 _maxSpend
    ) private {
        // Pull limit amount from sender
        _pull(_fromToken, _maxSpend);

        uint256 spent = _converter.safeConvertTo(_fromToken, _toToken, _amount, _maxSpend);

        if (spent < _maxSpend) {
            _transfer(_fromToken, msg.sender, _maxSpend - spent);
        }
    }

    function _pull(
        IERC20 _token,
        uint256 _amount
    ) private {
        if (address(_token) == ETH_ADDRESS) {
            require(msg.value == _amount, "sent eth is not enought");
        } else {
            require(msg.value == 0, "method is not payable");
            require(_token.safeTransferFrom(msg.sender, address(this), _amount), "error pulling tokens");
        }
    }

    function _transfer(
        IERC20 _token,
        address payable _to,
        uint256 _amount
    ) private {
        if (address(_token) == ETH_ADDRESS) {
            _to.transfer(_amount);
        } else {
            require(_token.safeTransfer(_to, _amount), "error sending tokens");
        }
    }

    function _approveOnlyOnce(
        IERC20 _token,
        address _spender,
        uint256 _amount
    ) private {
        uint256 allowance = _token.allowance(address(this), _spender);
        if (allowance < _amount) {
            if (allowance != 0) {
                _token.clearApprove(_spender);
            }

            _token.approve(_spender, uint(-1));
        }
    }

    function emergencyWithdraw(
        IERC20 _token,
        address _to,
        uint256 _amount
    ) external onlyOwner {
        _token.transfer(_to, _amount);
    }

    function() external payable {
        // solhint-disable-next-line
        require(tx.origin != msg.sender, "ramp: send eth rejected");
    }
}