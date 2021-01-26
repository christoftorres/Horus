# HTTP-RPC host
RPC_HOST = 'localhost'
# HTTP-RPC port
RPC_PORT = 8545
# Web3 instance
W3 = None
# Datalog facts folder
FACTS_FOLDER = './facts'
# Datalog results folder
RESULTS_FOLDER = './results'
# Datalog rules/quries file
DATALOG_FILE = './analyzer/datalog/attacks.dl'
# Debug mode
DEBUG_MODE = False
# Etherscan API key token
ETHERSCAN_API_TOKEN = 'VZ7EMQBT4GNH5F6FBV8FKXAFF6GS4MPKAU'
# Maximum block Height
MAX_BLOCK_HEIGHT = 10000000
# Block ranges to skip due to DoS attacks
# https://ethereum.stackexchange.com/questions/9883/why-is-my-node-synchronization-stuck-extremely-slow-at-block-2-306-843/10453
DOS_ATTACK_BLOCK_RANGES = [
    [2283397, 2301372],
    [2283416, 2379641],
    [2421507, 2463130],
    [2468209, 2474792],
    [2550666, 2551428],
    [2619660, 2620384]
]
# Number of connection retries to Ethereum client
CONNECTION_RETRIES = 10
# Time to wait in seconds before connection retry
CONNECTION_RETRY_INTERVAL = 30
# Timeout in seconds for requesting debug trace
REQUEST_TIMEOUT = 100
# Time to wait in seconds before request retry
REQUEST_RETRY_INTERVAL = 60
# Folder for temporary results
TMP_FOLDER = None
# Maximum number of transactions to be traced
MAX_TRANSACTIONS = 1000
# Etherscan offset for transactions to be retrieved
ETHERSCAN_OFFSET = 1000
# Minimum amount of wei to be traced
MIN_AMOUNT = 10000000000000000000 # 10 ETH
