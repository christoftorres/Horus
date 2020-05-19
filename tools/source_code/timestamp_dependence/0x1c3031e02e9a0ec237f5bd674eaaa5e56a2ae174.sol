pragma solidity ^0.4.26;

contract UniswapFactoryInterface {
    // Public Variables
    address public exchangeTemplate;
    uint256 public tokenCount;
    // Create Exchange
    function createExchange(address token) external returns (address exchange);
    // Get Exchange and Token Info
    function getExchange(address token) external view returns (address exchange);
    function getToken(address exchange) external view returns (address token);
    function getTokenWithId(uint256 tokenId) external view returns (address token);
    // Never use
    function initializeFactory(address template) external;
}

contract UniswapExchangeInterface {
    // Address of ERC20 token sold on this exchange
    function tokenAddress() external view returns (address token);
    // Address of Uniswap Factory
    function factoryAddress() external view returns (address factory);
    // Provide Liquidity
    function addLiquidity(uint256 min_liquidity, uint256 max_tokens, uint256 deadline) external payable returns (uint256);
    function removeLiquidity(uint256 amount, uint256 min_eth, uint256 min_tokens, uint256 deadline) external returns (uint256, uint256);
    // Get Prices
    function getEthToTokenInputPrice(uint256 eth_sold) external view returns (uint256 tokens_bought);
    function getEthToTokenOutputPrice(uint256 tokens_bought) external view returns (uint256 eth_sold);
    function getTokenToEthInputPrice(uint256 tokens_sold) external view returns (uint256 eth_bought);
    function getTokenToEthOutputPrice(uint256 eth_bought) external view returns (uint256 tokens_sold);
    // Trade ETH to ERC20
    function ethToTokenSwapInput(uint256 min_tokens, uint256 deadline) external payable returns (uint256  tokens_bought);
    function ethToTokenTransferInput(uint256 min_tokens, uint256 deadline, address recipient) external payable returns (uint256  tokens_bought);
    function ethToTokenSwapOutput(uint256 tokens_bought, uint256 deadline) external payable returns (uint256  eth_sold);
    function ethToTokenTransferOutput(uint256 tokens_bought, uint256 deadline, address recipient) external payable returns (uint256  eth_sold);
    // Trade ERC20 to ETH
    function tokenToEthSwapInput(uint256 tokens_sold, uint256 min_eth, uint256 deadline) external returns (uint256  eth_bought);
    function tokenToEthTransferInput(uint256 tokens_sold, uint256 min_eth, uint256 deadline, address recipient) external returns (uint256  eth_bought);
    function tokenToEthSwapOutput(uint256 eth_bought, uint256 max_tokens, uint256 deadline) external returns (uint256  tokens_sold);
    function tokenToEthTransferOutput(uint256 eth_bought, uint256 max_tokens, uint256 deadline, address recipient) external returns (uint256  tokens_sold);
    // Trade ERC20 to ERC20
    function tokenToTokenSwapInput(uint256 tokens_sold, uint256 min_tokens_bought, uint256 min_eth_bought, uint256 deadline, address token_addr) external returns (uint256  tokens_bought);
    function tokenToTokenTransferInput(uint256 tokens_sold, uint256 min_tokens_bought, uint256 min_eth_bought, uint256 deadline, address recipient, address token_addr) external returns (uint256  tokens_bought);
    function tokenToTokenSwapOutput(uint256 tokens_bought, uint256 max_tokens_sold, uint256 max_eth_sold, uint256 deadline, address token_addr) external returns (uint256  tokens_sold);
    function tokenToTokenTransferOutput(uint256 tokens_bought, uint256 max_tokens_sold, uint256 max_eth_sold, uint256 deadline, address recipient, address token_addr) external returns (uint256  tokens_sold);
    // Trade ERC20 to Custom Pool
    function tokenToExchangeSwapInput(uint256 tokens_sold, uint256 min_tokens_bought, uint256 min_eth_bought, uint256 deadline, address exchange_addr) external returns (uint256  tokens_bought);
    function tokenToExchangeTransferInput(uint256 tokens_sold, uint256 min_tokens_bought, uint256 min_eth_bought, uint256 deadline, address recipient, address exchange_addr) external returns (uint256  tokens_bought);
    function tokenToExchangeSwapOutput(uint256 tokens_bought, uint256 max_tokens_sold, uint256 max_eth_sold, uint256 deadline, address exchange_addr) external returns (uint256  tokens_sold);
    function tokenToExchangeTransferOutput(uint256 tokens_bought, uint256 max_tokens_sold, uint256 max_eth_sold, uint256 deadline, address recipient, address exchange_addr) external returns (uint256  tokens_sold);
    // ERC20 comaptibility for liquidity tokens
    bytes32 public name;
    bytes32 public symbol;
    uint256 public decimals;
    function transfer(address _to, uint256 _value) external returns (bool);
    function transferFrom(address _from, address _to, uint256 value) external returns (bool);
    function approve(address _spender, uint256 _value) external returns (bool);
    function allowance(address _owner, address _spender) external view returns (uint256);
    function balanceOf(address _owner) external view returns (uint256);
    function totalSupply() external view returns (uint256);
    // Never use
    function setup(address token_addr) external;
}

contract ERC20Interface {
    function totalSupply() public view returns (uint);
    function balanceOf(address tokenOwner) public view returns (uint balance);
    function allowance(address tokenOwner, address spender) public view returns (uint remaining);
    function transfer(address to, uint tokens) public returns (bool success);
    function approve(address spender, uint tokens) public returns (bool success);
    function transferFrom(address from, address to, uint tokens) public returns (bool success);
    // optional
    function name() external view returns (string);
    function symbol() external view returns (string);
    function decimals() external view returns (string);

    event Transfer(address indexed from, address indexed to, uint tokens);
    event Approval(address indexed tokenOwner, address indexed spender, uint tokens);
}

/**
 * @dev Contract module which provides a basic access control mechanism, where
 * there is an account (an owner) that can be granted exclusive access to
 * specific functions.
 *
 * This module is used through inheritance. It will make available the modifier
 * `onlyOwner`, which can be applied to your functions to restrict their use to
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

contract Rebalance is Ownable {
    // 1 approve this contract with dai manually
    
    uint256 UINT256_MAX = 2**256 - 1;

    function approveThisContract(address tokenAddress, address exchangeAddress) public onlyOwner {
        ERC20Interface token = ERC20Interface(tokenAddress);
        token.approve(exchangeAddress, UINT256_MAX);
    }
    
    constructor() public {
        ERC20Interface token;
        
        token = ERC20Interface(0x960b236A07cf122663c4303350609A66A7B288C0); // ANT
        token.approve(0x077d52b047735976dfda76fef74d4d988ac25196, UINT256_MAX);
        token = ERC20Interface(0x0D8775F648430679A709E98d2b0Cb6250d2887EF); // BAT
        token.approve(0x2e642b8d59b45a1d8c5aef716a84ff44ea665914, UINT256_MAX);
        token = ERC20Interface(0x107c4504cd79C5d2696Ea0030a8dD4e92601B82e); // BLT
        token.approve(0x0e6a53b13688018a3df8c69f99afb19a3068d04f, UINT256_MAX);
        token = ERC20Interface(0x1F573D6Fb3F13d689FF844B4cE37794d79a7FF1C); // BNT
        token.approve(0x87d80dbd37e551f58680b4217b23af6a752da83f, UINT256_MAX);
        token = ERC20Interface(0x26E75307Fc0C021472fEb8F727839531F112f317); // C20
        token.approve(0xf7b5a4b934658025390ff69db302bc7f2ac4a542, UINT256_MAX);
        token = ERC20Interface(0xF5DCe57282A584D2746FaF1593d3121Fcac444dC); // cDAI
        token.approve(0x45a2fdfed7f7a2c791fb1bdf6075b83fad821dde, UINT256_MAX);
        token = ERC20Interface(0x41e5560054824eA6B0732E656E3Ad64E20e94E45); // CVC
        token.approve(0x1c6c712b1f4a7c263b1dbd8f97fb447c945d3b9a, UINT256_MAX);
        token = ERC20Interface(0x89d24A6b4CcB1B6fAA2625fE562bDD9a23260359); // DAI
        token.approve(0x09cabec1ead1c0ba254b09efb3ee13841712be14, UINT256_MAX);
        token = ERC20Interface(0xE0B7927c4aF23765Cb51314A0E0521A9645F0E2A); // DGD
        token.approve(0xd55c1ca9f5992a2e5e379dce49abf24294abe055, UINT256_MAX);
        token = ERC20Interface(0x4f3AfEC4E5a3F2A6a1A411DEF7D7dFe50eE057bF); // DGX
        token.approve(0xb92de8b30584392af27726d5ce04ef3c4e5c9924, UINT256_MAX);
        token = ERC20Interface(0x4946Fcea7C692606e8908002e55A582af44AC121); // FOAM
        token.approve(0xf79cb3bea83bd502737586a6e8b133c378fd1ff2, UINT256_MAX);
        token = ERC20Interface(0x419D0d8BdD9aF5e606Ae2232ed285Aff190E711b); // FUN
        token.approve(0x60a87cc7fca7e53867facb79da73181b1bb4238b, UINT256_MAX);
        token = ERC20Interface(0x543Ff227F64Aa17eA132Bf9886cAb5DB55DCAddf); // GEN
        token.approve(0x26cc0eab6cb650b0db4d0d0da8cb5bf69f4ad692, UINT256_MAX);
        token = ERC20Interface(0x6810e776880C02933D47DB1b9fc05908e5386b96); // GNO
        token.approve(0xe8e45431b93215566ba923a7e611b7342ea954df, UINT256_MAX);
        token = ERC20Interface(0x12B19D3e2ccc14Da04FAe33e63652ce469b3F2FD); // GRID
        token.approve(0x4b17685b330307c751b47f33890c8398df4fe407, UINT256_MAX);
        token = ERC20Interface(0x6c6EE5e31d828De241282B9606C8e98Ea48526E2); // HOT
        token.approve(0xd4777e164c6c683e10593e08760b803d58529a8e, UINT256_MAX);
        token = ERC20Interface(0x818Fc6C2Ec5986bc6E2CBf00939d90556aB12ce5); // KIN
        token.approve(0xb7520a5f8c832c573d6bd0df955fc5c9b72400f7, UINT256_MAX);
        token = ERC20Interface(0xdd974D5C2e2928deA5F71b9825b8b646686BD200); // KNC
        token.approve(0x49c4f9bc14884f6210f28342ced592a633801a8b, UINT256_MAX);
        token = ERC20Interface(0x514910771AF9Ca656af840dff83E8264EcF986CA); // LINK
        token.approve(0xf173214c720f58e03e194085b1db28b50acdeead, UINT256_MAX);
        token = ERC20Interface(0xA4e8C3Ec456107eA67d3075bF9e3DF3A75823DB0); // LOOM
        token.approve(0x417cb32bc991fbbdcae230c7c4771cc0d69daa6b, UINT256_MAX);
        token = ERC20Interface(0x58b6A8A3302369DAEc383334672404Ee733aB239); // LPT
        token.approve(0xc4a1c45d5546029fd57128483ae65b56124bfa6a, UINT256_MAX);
        token = ERC20Interface(0xD29F0b5b3F50b07Fe9a9511F7d86F4f4bAc3f8c4); // LQD
        token.approve(0xe3406e7d0155e0a83236ec25d34cd3d903036669, UINT256_MAX);
        token = ERC20Interface(0xBBbbCA6A901c926F240b89EacB641d8Aec7AEafD); // LRC
        token.approve(0xa539baaa3aca455c986bb1e25301cef936ce1b65, UINT256_MAX);
        token = ERC20Interface(0x0F5D2fB29fb7d3CFeE444a200298f468908cC942); // MANA
        token.approve(0xc6581ce3a005e2801c1e0903281bbd318ec5b5c2, UINT256_MAX);
        token = ERC20Interface(0x7D1AfA7B718fb893dB30A3aBc0Cfc608AaCfeBB0); // MATIC
        token.approve(0x9a7a75e66b325a3bd46973b2b57c9b8d9d26a621, UINT256_MAX);
        token = ERC20Interface(0x80f222a749a2e18Eb7f676D371F19ad7EFEEe3b7); // MGN
        token.approve(0xdd80ca8062c7ef90fca2547e6a2a126c596e611f, UINT256_MAX);
        token = ERC20Interface(0x9f8F72aA9304c8B593d555F12eF6589cC3A579A2); // MKR
        token.approve(0x2c4bd064b998838076fa341a83d007fc2fa50957, UINT256_MAX);
        token = ERC20Interface(0xec67005c4E498Ec7f55E092bd1d35cbC47C91892); // MLN
        token.approve(0xa931f4eb165ac307fd7431b5ec6eadde53e14b0c, UINT256_MAX);
        token = ERC20Interface(0x957c30aB0426e0C93CD8241E2c60392d08c6aC8e); // MOD
        token.approve(0xccb98654cd486216fff273dd025246588e77cfc1, UINT256_MAX);
        token = ERC20Interface(0xB62132e35a6c13ee1EE0f84dC5d40bad8d815206); // NEXO
        token.approve(0x069c97dba948175d10af4b2414969e0b88d44669, UINT256_MAX);
        token = ERC20Interface(0x1776e1F26f98b1A5dF9cD347953a26dd3Cb46671); // NMR
        token.approve(0x2bf5a5ba29e60682fc56b2fcf9ce07bef4f6196f, UINT256_MAX);
        token = ERC20Interface(0x8E870D67F660D95d5be530380D0eC0bd388289E1); // PAX
        token.approve(0xc040d51b07aea5d94a89bc21e8078b77366fc6c7, UINT256_MAX);
        token = ERC20Interface(0x93ED3FBe21207Ec2E8f2d3c3de6e058Cb73Bc04d); // PNK
        token.approve(0xf506828b166de88ca2edb2a98d960abba0d2402a, UINT256_MAX);
        token = ERC20Interface(0x6758B7d441a9739b98552B373703d8d3d14f9e62); // POA20
        token.approve(0xa2e6b3ef205feaee475937c4883b24e6eb717eef, UINT256_MAX);
        token = ERC20Interface(0x687BfC3E73f6af55F0CccA8450114D107E781a0e); // QCH
        token.approve(0x755899f0540c3548b99e68c59adb0f15d2695188, UINT256_MAX);
        token = ERC20Interface(0x255Aa6DF07540Cb5d3d297f0D0D4D84cb52bc8e6); // RDN
        token.approve(0x7d03cecb36820b4666f45e1b4ca2538724db271c, UINT256_MAX);
        token = ERC20Interface(0x408e41876cCCDC0F92210600ef50372656052a38); // REN
        token.approve(0x43892992b0b102459e895b88601bb2c76736942c, UINT256_MAX);
        token = ERC20Interface(0x1985365e9f78359a9B6AD760e32412f4a445E862); // REP
        token.approve(0x43892992b0b102459e895b88601bb2c76736942c, UINT256_MAX);
        token = ERC20Interface(0x168296bb09e24A88805CB9c33356536B980D3fC5); // RHOC
        token.approve(0x394e524b47a3ab3d3327f7ff6629dc378c1494a3, UINT256_MAX);
        token = ERC20Interface(0x607F4C5BB672230e8672085532f7e901544a7375); // RLC
        token.approve(0xa825cae02b310e9901b4776806ce25db520c8642, UINT256_MAX);
        token = ERC20Interface(0xB4EFd85c19999D84251304bDA99E90B92300Bd93); // RPL
        token.approve(0x3fb2f18065926ddb33e7571475c509541d15da0e, UINT256_MAX);
        token = ERC20Interface(0x4156D3342D5c385a87D264F90653733592000581); // SALT
        token.approve(0x4156D3342D5c385a87D264F90653733592000581, UINT256_MAX);
        token = ERC20Interface(0x42456D7084eacF4083f1140d3229471bbA2949A8); // sETH
        token.approve(0x4740c758859d4651061cc9cdefdba92bdc3a845d, UINT256_MAX);
        token = ERC20Interface(0x744d70FDBE2Ba4CF95131626614a1763DF805B9E); // SNT
        token.approve(0x1aec8f11a7e78dc22477e91ed924fab46e3a88fd, UINT256_MAX);
        token = ERC20Interface(0x2Dea20405c52Fb477ecCa8Fe622661d316Ac5400); // SNX
        token.approve(0x2Dea20405c52Fb477ecCa8Fe622661d316Ac5400, UINT256_MAX);
        token = ERC20Interface(0x42d6622deCe394b54999Fbd73D108123806f6a18); // SPANK
        token.approve(0x4e395304655f0796bc3bc63709db72173b9ddf98, UINT256_MAX);
        token = ERC20Interface(0xB64ef51C888972c908CFacf59B47C1AfBC0Ab8aC); // STORJ
        token.approve(0xa7298541e52f96d42382ecbe4f242cbcbc534d02, UINT256_MAX);
        token = ERC20Interface(0x0cbe2df57ca9191b64a7af3baa3f946fa7df2f25); // sUSD
        token.approve(0xa1ecdcca26150cf69090280ee2ee32347c238c7b, UINT256_MAX);
        token = ERC20Interface(0xaAAf91D9b90dF800Df4F55c205fd6989c977E73a); // TKN
        token.approve(0xb6cfbf322db47d39331e306005dc7e5e6549942b, UINT256_MAX);
        token = ERC20Interface(0x8dd5fbCe2F6a956C3022bA3663759011Dd51e73E); // TUSD
        token.approve(0x4f30e682d0541eac91748bd38a648d759261b8f3, UINT256_MAX);
        token = ERC20Interface(0x09cabEC1eAd1c0Ba254B09efb3EE13841712bE14); // UNI-V1:DAI
        token.approve(0x601c32e0580d3aef9437db52d09f5a5d7e60ec22, UINT256_MAX);
        token = ERC20Interface(0xA0b86991c6218b36c1d19D4a2e9Eb0cE3606eB48); // USDC
        token.approve(0x97dec872013f6b5fb443861090ad931542878126, UINT256_MAX);
        token = ERC20Interface(0x8f3470A7388c05eE4e7AF3d01D8C722b0FF52374); // VERI
        token.approve(0x17e5bf07d696eaf0d14caa4b44ff8a1e17b34de3, UINT256_MAX);
        token = ERC20Interface(0x2260FAC5E5542a773Aa44fBCfeDf7C193bc2C599); // WBTC
        token.approve(0x4d2f5cfba55ae412221182d8475bc85799a5644b, UINT256_MAX);
        token = ERC20Interface(0x09fE5f0236F0Ea5D930197DCE254d77B04128075); // WCK
        token.approve(0x4ff7fa493559c40abd6d157a0bfc35df68d8d0ac, UINT256_MAX);
        token = ERC20Interface(0xC02aaA39b223FE8D0A0e5C4F27eAD9083C756Cc2); // WETH
        token.approve(0xa2881a90bf33f03e7a3f803765cd2ed5c8928dfb, UINT256_MAX);
        token = ERC20Interface(0xB4272071eCAdd69d933AdcD19cA99fe80664fc08); // XCHF
        token.approve(0x8de0d002dc83478f479dc31f76cb0a8aa7ccea17, UINT256_MAX);
        token = ERC20Interface(0xE41d2489571d322189246DaFA5ebDe1F4699F498); // ZRX
        token.approve(0xae76c84c9262cdb9abc0c2c8888e62db8e22a0bf, UINT256_MAX);
        
        /*
        // RINKEBY
        token = ERC20Interface(0x2448eE2641d78CC42D7AD76498917359D961A783); //DAI
        token.approve(0x77dB9C915809e7BE439D2AB21032B1b8B58F6891, UINT256_MAX);
        token = ERC20Interface(0xDA5B056Cfb861282B4b59d29c9B395bcC238D29B); // BAT
        token.approve(0x9B913956036a3462330B0642B20D3879ce68b450, UINT256_MAX);
        token = ERC20Interface(0xF9bA5210F91D0474bd1e1DcDAeC4C58E359AaD85); // MKR
        token.approve(0x93bB63aFe1E0180d0eF100D774B473034fd60C36, UINT256_MAX); 
        token = ERC20Interface(0x879884c3C46A24f56089f3bBbe4d5e38dB5788C0); //OMG
        token.approve(0x26C226EBb6104676E593F8A070aD6f25cDa60F8D, UINT256_MAX);
        token = ERC20Interface(0xF22e3F33768354c9805d046af3C0926f27741B43); // ZRX
        token.approve(0xaBD44a1D1b9Fb0F39fE1D1ee6b1e2a14916D067D, UINT256_MAX);*/
    }
    
    /*function testSwap() public payable {
        // e2t
        address[] memory e2tTo = new address[](1);
        e2tTo[0] = 0x77dB9C915809e7BE439D2AB21032B1b8B58F6891; // DAI Exchange address
        uint[] memory e2tAmount = new uint[](1);
        e2tAmount[0] = 100000000000000000; // 0,1 eth worth
        
        // t2t
        address[] memory t2tFromToken = new address[](1);
        t2tFromToken[0] = 0x2448eE2641d78CC42D7AD76498917359D961A783; // DAI Token address
        address[] memory t2tFromExchange = new address[](1);
        t2tFromExchange[0] = 0x77dB9C915809e7BE439D2AB21032B1b8B58F6891; // DAI Exchange address
        uint[] memory t2tAmount = new uint[](1);
        t2tAmount[0] = 1000000000000000000; // 1 dai to BAT
        address[] memory t2tToToken = new address[](1);
        t2tToToken[0] = 0xDA5B056Cfb861282B4b59d29c9B395bcC238D29B;
        
        // t2e
        address[] memory t2eFromToken = new address[](1);
        t2eFromToken[0] = 0x2448eE2641d78CC42D7AD76498917359D961A783; // DAI Token address
        address[] memory t2eFromTokenExchange = new address[](1);
        t2eFromTokenExchange[0] = 0x77dB9C915809e7BE439D2AB21032B1b8B58F6891; // DAI Exchange address
        uint[] memory t2eAmount = new uint[](1);
        t2eAmount[0] = 1000000000000000000; // 1 DAI to eth
        
        swap(
            e2tTo, e2tAmount, 1,
            t2tFromToken, t2tFromExchange, t2tAmount, t2tToToken, 1,
            t2eFromToken, t2eFromTokenExchange, t2eAmount, 1
        );
    }*/
    
 
    function swap(
        address[] e2tTo, uint[] memory e2tAmount, uint e2tLen,
        address[] t2tFromToken, address[] t2tFromExchange, uint[] memory t2tAmount, address[] t2tToToken, uint t2tLen,
        address[] t2eFromToken, address[] t2eFromExchange, uint[] memory t2eAmount, uint t2eLen
    ) public payable {
        UniswapExchangeInterface fx;
        ERC20Interface token;
        // ethToToken
        for (uint i=0; i<e2tLen; i++) {
            fx = UniswapExchangeInterface(e2tTo[i]);
            fx.ethToTokenTransferInput.value(e2tAmount[i])(1, 1739591241, msg.sender);
        }
        
        // tokenToToken
        for (i=0; i<t2tLen; i++) {
            token = ERC20Interface(t2tFromToken[i]);
            token.transferFrom(msg.sender, address(this), t2tAmount[i]);
            fx = UniswapExchangeInterface(t2tFromExchange[i]);
            fx.tokenToTokenTransferInput(t2tAmount[i], 1, 1, 1739591241, msg.sender, t2tToToken[i]);
        }
        
        // tokenToEth
        for (i=0; i<t2eLen; i++) {
            token = ERC20Interface(t2eFromToken[i]);
            token.transferFrom(msg.sender, address(this), t2eAmount[i]);
            fx = UniswapExchangeInterface(t2eFromExchange[i]);
            fx.tokenToEthTransferInput(t2eAmount[i], 1, 1739591241, msg.sender);
        }
    }
    
    
}