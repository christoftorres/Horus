#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import sys
import json
import time
import cfscrape
import requests

from urllib.parse import urlparse

class Etherscan():
    def __init__(self, api_key=None):
        self.api_key = api_key

    def get_block_number_by_timestamp(self, timestamp, closest='after'):
        response = requests.get("https://api.etherscan.io/api?module=block&action=getblocknobytime&timestamp="+str(timestamp)+"&closest="+closest+"&apikey="+str(self.api_key))
        return int(response.json()["result"])

    def get_normal_transactions(self, address, start_block=0, end_block=99999999, offset=10000):
        response = requests.get("http://api.etherscan.io/api?module=account&action=txlist&address="+str(address)+"&startblock="+str(start_block)+"&endblock="+str(end_block)+"&page=1&offset="+str(offset)+"&sort=asc&apikey="+str(self.api_key))
        return response.json()["result"]

    def get_internal_transactions(self, address, start_block=0, end_block=99999999, offset=10000):
        response = requests.get("http://api.etherscan.io/api?module=account&action=txlistinternal&address="+str(address)+"&startblock="+str(start_block)+"&endblock="+str(end_block)+"&page=1&offset="+str(offset)+"&sort=asc&apikey="+str(self.api_key))
        return response.json()["result"]

    def get_token_transactions(self, address, start_block=0, end_block=99999999, offset=10000):
        response = requests.get("http://api.etherscan.io/api?module=account&action=tokentx&address="+str(address)+"&startblock="+str(start_block)+"&endblock="+str(end_block)+"&page=1&offset="+str(offset)+"&sort=asc&apikey="+str(self.api_key))
        return response.json()["result"]

    def get_labels(self, session_cookie=None):
        if os.path.isfile(os.path.abspath(os.path.dirname(sys.argv[0]))+'/tracer/ethereum/data/labeled_accounts.json'):
            with open(os.path.abspath(os.path.dirname(sys.argv[0]))+'/tracer/ethereum/data/labeled_accounts.json') as json_file:
                return json.load(json_file)
        scraper = cfscrape.create_scraper()
        content = scraper.get('https://etherscan.io/labelcloud').content.decode('utf-8')
        labels = re.compile('<div class="dropdown-menu list-unstyled py-2 mb-0 w-100 font-size-base" aria-labelledby="(.+?)"><a class="py-1 px-3 d-block" href="(.+?)">').findall(content)
        account_labels = []
        for label in labels:
            if 'accounts' in label[1]:
                account_labels.append(label)
        print("Found "+str(len(labels))+" labels.")
        print(str(len(account_labels))+" labels realted to accounts.")
        categories = []
        labeled_accounts = {}
        for label in account_labels:
            url = 'https://etherscan.io/'+label[1]
            cookies, user_agent = cfscrape.get_tokens(url)
            cookies['ASP.NET_SessionId'] = session_cookie
            headers = {'User-Agent': user_agent}
            page_count = 1
            accounts = []
            accounts_extracted = []
            total = 0
            while accounts_extracted or page_count == 1:
                content = requests.get(url+'/'+str(page_count), cookies=cookies, headers=headers).text
                if total == 0:
                    total = int(re.compile('A total of (.+?) account').findall(content)[0].replace(',', ''))
                accounts_extracted = re.compile('<tr><td>.*?<a href=\'.+?\'>(.+?)</a>.*?</td><td>(.*?)</td><td>.+?</td><td>.+?</td></tr>').findall(content)
                accounts += accounts_extracted
                page_count += 1
            print("Extracted for '"+label[0]+"' "+str(len(accounts))+" accounts out of "+str(total))
            for account in accounts:
                address = account[0]
                if address not in labeled_accounts:
                    labeled_accounts[address] = {"labels": [], "category": ""}
                account_label = account[1]
                if account_label != '' and account_label not in labeled_accounts[address]["labels"]:
                    labeled_accounts[address]["labels"].append(account_label)
                category = label[0]
                if category and labeled_accounts[address]["category"] == "":
                    labeled_accounts[address]["category"] = category
                if category not in categories:
                    categories.append(category)
        with open(os.path.abspath(os.path.dirname(sys.argv[0]))+'/tracer/ethereum/data/labeled_accounts.json', 'w') as jsonfile:
            json.dump(labeled_accounts, jsonfile)
        with open(os.path.abspath(os.path.dirname(sys.argv[0]))+'/tracer/ethereum/data/categories.json', 'w') as jsonfile:
            json.dump(categories, jsonfile)
        return labeled_accounts

    def get_geographic_locations(self, labels=list(), path=os.path.abspath(os.path.dirname(sys.argv[0]))+'/tracer/ethereum', update=False):
        geographic_locations = {}
        if os.path.isfile(path+'/data/geographic_locations.json'):
            with open(path+'/data/geographic_locations.json') as json_file:
                geographic_locations = json.load(json_file)
                if not update:
                    return geographic_locations
        for label in labels:
            if label in geographic_locations:
                continue
            time.sleep(1)
            print("Contract address:", label)
            scraper = cfscrape.create_scraper()
            content = scraper.get('https://etherscan.io/address/'+label).content.decode('utf-8')
            website = re.compile("<a href='(.+?)' target='_blank' rel='nofollow' data-toggle='tooltip' title='External Site - More Info'>.+?</a>").findall(content)
            if len(website) > 0:
                website = website[0]
                print("Website:", website)
                domain = urlparse(website).netloc.replace("www.", "")
                print("Domain:", domain)
                try:
                    response = requests.get('http://ip-api.com/json/'+domain).json()
                    if response["status"] == "success":
                        del response["status"]
                        geographic_locations[label] = response
                    else:
                        domain = "www."+domain
                        response = requests.get('http://ip-api.com/json/'+domain).json()
                        if response["status"] == "success":
                            del response["status"]
                            geographic_locations[label] = response
                        else:
                            print(response)
                except:
                    pass
            with open(path+'/data/geographic_locations.json', 'w') as jsonfile:
                json.dump(geographic_locations, jsonfile)
        return geographic_locations

def main():
    etherscan = Etherscan()
    with open(os.path.abspath(os.path.dirname(sys.argv[0]))+'/data/labeled_accounts.json', 'r') as f:
        labels = json.load(f)
        print(len(labels))
        geographic_locations = etherscan.get_geographic_locations(labels, os.path.abspath(os.path.dirname(sys.argv[0])), True)
        print(len(geographic_locations))

if __name__ == "__main__":
    main()
