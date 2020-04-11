
import requests

class Etherscan():
    def __init__(self, api_key):
        self.api_key = api_key

    def get_normal_transactions(self, address, start_block=0, end_block=99999999):
        response = requests.get("http://api.etherscan.io/api?module=account&action=txlist&address="+str(address)+"&startblock="+str(start_block)+"&endblock="+str(end_block)+"&sort=asc&apikey="+str(self.api_key))
        return response.json()["result"]

    def get_internal_transactions(self, address, start_block=0, end_block=99999999):
        response = requests.get("http://api.etherscan.io/api?module=account&action=txlistinternal&address="+str(address)+"&startblock="+str(start_block)+"&endblock="+str(end_block)+"&sort=asc&apikey="+str(self.api_key))
        return response.json()["result"]

    def get_token_transactions(self, address, start_block=0, end_block=99999999):
        response = requests.get("http://api.etherscan.io/api?module=account&action=tokentx&address="+str(address)+"&startblock="+str(start_block)+"&endblock="+str(end_block)+"&sort=asc&apikey="+str(self.api_key))
        return response.json()["result"]
