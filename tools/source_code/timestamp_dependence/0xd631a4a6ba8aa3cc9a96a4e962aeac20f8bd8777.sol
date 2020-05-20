// File: @openzeppelin/contracts/utils/address.sol

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

// File: contracts/SpiderPay.sol

pragma solidity ^0.5.0;


contract SpiderPay {
  event Paid(bytes32 hash, bytes32 indexed no, address token, address from, uint256 value);
  using Address for address;

  mapping(bytes32 => bool) public paid;
  address accountant = address(0xf2EBAbAeA9da140416793cbF348F14b650fe7329);
  address signer;
  address owner;

  constructor(address _owner, address _signer) public {
    owner = _owner;
    signer = _signer;
  }

  modifier onlyOwner() {
    require(owner == msg.sender, "The caller is not the Owner role");
    _;
  }

  function setOwner(address _owner) public onlyOwner {
    owner = _owner;
  }

  function setSigner(address _signer) public onlyOwner {
    signer = _signer;
  }

  function() external payable {
    require(false, "DISABLED_METHOD");
  }

  function isValid(
    bytes32 hash,
    address signer,
    bytes memory signature
  )
  public
  pure
  returns (bool)
  {
    require(
      signature.length == 65,
      "LENGTH_65_REQUIRED"
    );

    bytes32 r;
    bytes32 s;
    uint8 v;

    assembly {
    // first 32 bytes, after the length prefix
      r := mload(add(signature, 32))
    // second 32 bytes
      s := mload(add(signature, 64))
    // final byte (first byte of the next 32 bytes)
      v := byte(0, mload(add(signature, 96)))
    }

    address recovered = ecrecover(
      keccak256(abi.encodePacked(
        "\x19Ethereum Signed Message:\n32",
        hash
      )),
      v,
      r,
      s
    );
    return signer == recovered;
  }

  function payETH(bytes32 no, uint256 expiration, bytes memory signature) public payable {
    require(expiration > block.timestamp, "EXPIRED_PAY");
    require(!paid[no], "PAID_NO");

    bytes32 hash = keccak256(abi.encodePacked(no, expiration));
    require(isValid(hash, signer, signature), "INVALID_SIGN");

    accountant.toPayable().transfer(msg.value);

    emit Paid(hash, no, address(0x0000000000000000000000000000000000000001), msg.sender, msg.value);
  }
}