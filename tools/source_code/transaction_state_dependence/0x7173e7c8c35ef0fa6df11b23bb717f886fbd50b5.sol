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

// File: contracts/interfaces/uniswap/UniswapExchange.sol

pragma solidity 0.5.12;

/// https:///docs.uniswap.io/smart-contract-integration/interface
contract UniswapExchange {
    /// Address of ERC20 token sold on this exchange
    function tokenAddress() external view returns (address token);
    /// Address of Uniswap Factory
    function factoryAddress() external view returns (address factory);
    /// Provide Liquidity
    function addLiquidity(uint256 minLiquidity, uint256 maxTokens, uint256 deadline) external payable returns (uint256);
    function removeLiquidity(uint256 amount, uint256 minEth, uint256 minTokens, uint256 deadline) external returns (uint256, uint256);
    /// Get Prices
    function getEthToTokenInputPrice(uint256 ethSold) external view returns (uint256 tokensBought);
    function getEthToTokenOutputPrice(uint256 tokensBought) external view returns (uint256 ethSold);
    function getTokenToEthInputPrice(uint256 tokensSold) external view returns (uint256 ethBought);
    function getTokenToEthOutputPrice(uint256 ethBought) external view returns (uint256 tokensSold);
    /// Trade ETH to ERC20
    function ethToTokenSwapInput(uint256 minTokens, uint256 deadline) external payable returns (uint256  tokensBought);
    function ethToTokenTransferInput(uint256 minTokens, uint256 deadline, address recipient) external payable returns (uint256  tokensBought);
    function ethToTokenSwapOutput(uint256 tokensBought, uint256 deadline) external payable returns (uint256  ethSold);
    function ethToTokenTransferOutput(uint256 tokensBought, uint256 deadline, address recipient) external payable returns (uint256  ethSold);
    /// Trade ERC20 to ETH
    function tokenToEthSwapInput(uint256 tokensSold, uint256 minEth, uint256 deadline) external returns (uint256  ethBought);
    function tokenToEthTransferInput(uint256 tokensSold, uint256 minTokens, uint256 deadline, address recipient) external returns (uint256  ethBought);
    function tokenToEthSwapOutput(uint256 ethBought, uint256 maxTokens, uint256 deadline) external returns (uint256  tokensSold);
    function tokenToEthTransferOutput(uint256 ethBought, uint256 maxTokens, uint256 deadline, address recipient) external returns (uint256  tokensSold);
    /// Trade ERC20 to ERC20
    function tokenToTokenSwapInput(uint256 tokensSold, uint256 minTokensBought, uint256 minEthBought, uint256 deadline, address tokenAddr) external returns (uint256  tokensBought);
    function tokenToTokenTransferInput(uint256 tokensSold, uint256 minTokensBought, uint256 minEthBought, uint256 deadline, address recipient, address tokenAddr) external returns (uint256  tokensBought);
    function tokenToTokenSwapOutput(uint256 tokensBought, uint256 maxTokensSold, uint256 maxEthSold, uint256 deadline, address tokenAddr) external returns (uint256  tokensSold);
    function tokenToTokenTransferOutput(uint256 tokensBought, uint256 maxTokensSold, uint256 maxEthSold, uint256 deadline, address recipient, address tokenAddr) external returns (uint256  tokensSold);
    /// Trade ERC20 to Custom Pool
    function tokenToExchangeSwapInput(uint256 tokensSold, uint256 minTokensBought, uint256 minEthBought, uint256 deadline, address exchangeAddr) external returns (uint256  tokensBought);
    function tokenToExchangeTransferInput(uint256 tokensSold, uint256 minTokensBought, uint256 minEthBought, uint256 deadline, address recipient, address exchangeAddr) external returns (uint256  tokensBought);
    function tokenToExchangeSwapOutput(uint256 tokensBought, uint256 maxTokensSold, uint256 maxEthSold, uint256 deadline, address exchangeAddr) external returns (uint256  tokensSold);
    function tokenToExchangeTransferOutput(uint256 tokensBought, uint256 maxTokensSold, uint256 maxEthSold, uint256 deadline, address recipient, address exchangeAddr) external returns (uint256  tokensSold);
    /// ERC20 comaptibility for liquidity tokens
    bytes32 public name;
    bytes32 public symbol;
    uint256 public decimals;
    function transfer(address _to, uint256 _value) external returns (bool);
    function transferFrom(address _from, address _to, uint256 value) external returns (bool);
    function approve(address _spender, uint256 _value) external returns (bool);
    function allowance(address _owner, address _spender) external view returns (uint256);
    function balanceOf(address _owner) external view returns (uint256);
    /// Never use
    function setup(address tokenAddr) external;
}

// File: contracts/interfaces/uniswap/UniswapFactory.sol

pragma solidity 0.5.12;




/// https://docs.uniswap.io/smart-contract-integration/interface
contract UniswapFactory {
    /// Public Variables
    address public exchangeTemplate;
    uint256 public tokenCount;
    /// Create Exchange
    function createExchange(IERC20 token) external returns (UniswapExchange exchange);
    /// Get Exchange and Token Info
    function getExchange(IERC20 token) external view returns (UniswapExchange exchange);
    function getToken(address exchange) external view returns (IERC20 token);
    function getTokenWithId(uint256 tokenId) external view returns (IERC20 token);
    /// Never use
    function initializeFactory(address template) external;
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

// File: contracts/utils/SafeExchange.sol

pragma solidity ^0.5.12;





library SafeExchange {
    using SafeMath for uint256;

    modifier swaps(uint256 _value, IERC20 _token) {
        uint256 nextBalance = _token.balanceOf(address(this)).add(_value);
        _;
        require(
            _token.balanceOf(address(this)) >= nextBalance,
            "Balance validation failed after swap."
        );
    }

    function swapTokens(
        UniswapExchange _exchange,
        uint256 _outValue,
        uint256 _inValue,
        uint256 _ethValue,
        uint256 _deadline,
        IERC20 _outToken
    ) internal swaps(_outValue, _outToken) {
        _exchange.tokenToTokenSwapOutput(
            _outValue,
            _inValue,
            _ethValue,
            _deadline,
            address(_outToken)
        );
    }

    function swapEther(
        UniswapExchange _exchange,
        uint256 _outValue,
        uint256 _ethValue,
        uint256 _deadline,
        IERC20 _outToken
    ) internal swaps(_outValue, _outToken) {
        _exchange.ethToTokenSwapOutput.value(_ethValue)(_outValue, _deadline);
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

// File: contracts/converter/UniswapConverter.sol

pragma solidity 0.5.12;










/// @notice proxy between ConverterRamp and Uniswap
///         accepts tokens and ether, converts these to the desired token,
///         and makes approve calls to allow the recipient to transfer those
///         tokens from the contract.
/// @author Joaquin Pablo Gonzalez (jpgonzalezra@gmail.com) & Agustin Aguilar (agusxrun@gmail.com)
contract UniswapConverter is TokenConverter, Ownable {
    using SafeMath for uint256;
    using SafeExchange for UniswapExchange;
    using SafeERC20 for IERC20;

    /// @notice address to identify operations with ETH
    IERC20 constant internal ETH_TOKEN_ADDRESS = IERC20(0x00eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee);

    /// @notice registry of ERC20 tokens that have been added to the system
    ///         and the exchange to which they are associated.
    UniswapFactory public factory;

    constructor (address _uniswapFactory) public {
        factory = UniswapFactory(_uniswapFactory);
    }

    function convertFrom(
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _fromAmount,
        uint256 _minReceive
    ) external payable returns (uint256 _received) {
        _pull(_fromToken, _fromAmount);

        UniswapFactory _factory = factory;

        if (_fromToken == ETH_TOKEN_ADDRESS) {
            // Convert ETH to TOKEN
            // and send directly to msg.sender
            _received = _factory.getExchange(_toToken).ethToTokenTransferInput.value(
                _fromAmount
            )(
                1,
                uint(-1),
                msg.sender
            );
        } else if (_toToken == ETH_TOKEN_ADDRESS) {
            // Load Uniswap exchange
            UniswapExchange exchange = _factory.getExchange(_fromToken);
            // Convert TOKEN to ETH
            // and send directly to msg.sender
            _approveOnlyOnce(_fromToken, address(exchange), _fromAmount);
            _received = exchange.tokenToEthTransferInput(
                _fromAmount,
                1,
                uint(-1),
                msg.sender
            );
        } else {
            // Load Uniswap exchange
            UniswapExchange exchange = _factory.getExchange(_fromToken);
            // Convert TOKENA to ETH
            // and send it to this contract
            _approveOnlyOnce(_fromToken, address(exchange), _fromAmount);
            _received = exchange.tokenToTokenTransferInput(
                _fromAmount,
                1,
                1,
                uint(-1),
                msg.sender,
                address(_toToken)
            );
        }

        require(_received >= _minReceive, "_received is not enought");
    }

    function convertTo(
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _toAmount,
        uint256 _maxSpend
    ) external payable returns (uint256 _spent) {
        _pull(_fromToken, _maxSpend);

        UniswapFactory _factory = factory;

        if (_fromToken == ETH_TOKEN_ADDRESS) {
            // Convert ETH to TOKEN
            // and send directly to msg.sender
            _spent = _factory.getExchange(_toToken).ethToTokenTransferOutput.value(
                _maxSpend
            )(
                _toAmount,
                uint(-1),
                msg.sender
            );
        } else if (_toToken == ETH_TOKEN_ADDRESS) {
            // Load Uniswap exchange
            UniswapExchange exchange = _factory.getExchange(_fromToken);
            // Convert TOKEN to ETH
            // and send directly to msg.sender
            _approveOnlyOnce(_fromToken, address(exchange), _maxSpend);
            _spent = exchange.tokenToEthTransferOutput(
                _toAmount,
                _maxSpend,
                uint(-1),
                msg.sender
            );
        } else {
            // Load Uniswap exchange
            UniswapExchange exchange = _factory.getExchange(_fromToken);
            // Convert TOKEN to ETH
            // and send directly to msg.sender
            _approveOnlyOnce(_fromToken, address(exchange), _maxSpend);
            _spent = exchange.tokenToTokenTransferOutput(
                _toAmount,
                _maxSpend,
                uint(-1),
                uint(-1),
                msg.sender,
                address(_toToken)
            );
        }

        require(_spent <= _maxSpend, "_maxSpend exceed");
        if (_spent < _maxSpend) {
            _transfer(_fromToken, msg.sender, _maxSpend - _spent);
        }
    }

    function getPriceConvertFrom(
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _fromAmount
    ) external view returns (uint256 _receive) {
        UniswapFactory _factory = factory;

        if (_fromToken == ETH_TOKEN_ADDRESS) {
            // ETH -> TOKEN convertion
            _receive = _factory.getExchange(_toToken).getEthToTokenInputPrice(_fromAmount);
        } else if (_toToken == ETH_TOKEN_ADDRESS) {
            // TOKEN -> ETH convertion
            _receive = _factory.getExchange(_fromToken).getTokenToEthInputPrice(_fromAmount);
        } else {
            // TOKENA -> TOKENB convertion
            //   equals to: TOKENA -> ETH -> TOKENB
            uint256 ethBought = _factory.getExchange(_fromToken).getTokenToEthInputPrice(_fromAmount);
            _receive = _factory.getExchange(_toToken).getEthToTokenInputPrice(ethBought);
        }
    }

    function getPriceConvertTo(
        IERC20 _fromToken,
        IERC20 _toToken,
        uint256 _toAmount
    ) external view returns (uint256 _spend) {
        UniswapFactory _factory = factory;

        if (_fromToken == ETH_TOKEN_ADDRESS) {
            // ETH -> TOKEN convertion
            _spend = _factory.getExchange(_toToken).getEthToTokenOutputPrice(_toAmount);
        } else if (_toToken == ETH_TOKEN_ADDRESS) {
            // TOKEN -> ETH convertion
            _spend = _factory.getExchange(_fromToken).getTokenToEthOutputPrice(_toAmount);
        } else {
            // TOKENA -> TOKENB convertion
            //   equals to: TOKENA -> ETH -> TOKENB
            uint256 ethSpend = _factory.getExchange(_toToken).getEthToTokenOutputPrice(_toAmount);
            _spend = _factory.getExchange(_fromToken).getTokenToEthOutputPrice(ethSpend);
        }
    }

    function _pull(
        IERC20 _token,
        uint256 _amount
    ) private {
        if (_token == ETH_TOKEN_ADDRESS) {
            require(msg.value == _amount, "sent eth is not enought");
        } else {
            require(msg.value == 0, "method is not payable");
            require(_token.transferFrom(msg.sender, address(this), _amount), "error pulling tokens");
        }
    }

    function _transfer(
        IERC20 _token,
        address payable _to,
        uint256 _amount
    ) private {
        if (_token == ETH_TOKEN_ADDRESS) {
            _to.transfer(_amount);
        } else {
            require(_token.transfer(_to, _amount), "error sending tokens");
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
        require(tx.origin != msg.sender, "uniswap-converter: send eth rejected");
    }
}