
from pyetherchain.pyetherchain import EtherChainApi

etherchain_api = EtherChainApi()

def get_one_eth_to_usd(timestamp):
    one_eth_to_usd = prices[-1]["value"]
    for index, price in enumerate(prices):
        if index < len(prices)-1:
            if prices[index]["time"] <= timestamp and timestamp <= prices[index+1]["time"]:
                one_eth_to_usd = prices[index]["value"]
                break
    return one_eth_to_usd

prices = etherchain_api.get_stats_price_usd()
print(prices)
