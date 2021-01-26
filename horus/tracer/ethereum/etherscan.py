#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re
import json
import cfscrape
import requests

from urllib.parse import urlparse

class Etherscan():
    def __init__(self, api_key):
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
        if os.path.isfile('./tracer/data/labeled_accounts.json'):
            with open('./tracer/data/labeled_accounts.json') as json_file:
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
        with open('./tracer/data/labeled_accounts.json', 'w') as jsonfile:
            json.dump(labeled_accounts, jsonfile)
        with open('./tracer/data/categories.json', 'w') as jsonfile:
            json.dump(categories, jsonfile)
        return labeled_accounts

    def get_geographic_locations_of_exchanges(self, labels):
        if os.path.isfile('./tracer/data/geographic_locations.json'):
            with open('./tracer/data/geographic_locations.json') as json_file:
                return json.load(json_file)
        exchanges = []
        for account in labels:
            if labels[account]["category"] == "Exchange":
                for label in labels[account]["labels"]:
                    exchanges.append(label)
        geographic_locations = {}
        for label in exchanges:
            label = label.split(":")[0]
            label = label.replace(" Exchange", " ")
            if " " in label:
                label = label.split(" ")[0]+''.join(i for i in label.split(" ")[1] if not i.isdigit())
            print(label)
            scraper = cfscrape.create_scraper()
            content = scraper.get('https://etherscan.io/directory/Exchanges?q='+label).content.decode('utf-8')
            website = re.compile('><a href=".+?" data-toggle="tooltip" class="btn btn-sm btn-icon btn-soft-secondary rounded-circle" data-original-title="\[Website\] (.+?)" rel="nofollow" target="_blank">').findall(content)
            if len(website) > 0:
                website = website[0]
                print(website)
                domain = urlparse(website).netloc.replace("www.", "")
                print(domain)
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
                    geographic_locations[label] = None
                    pass
            else:
                geographic_locations[label] = None
        with open('./tracer/data/geographic_locations.json', 'w') as jsonfile:
            json.dump(geographic_locations, jsonfile)
        return geographic_locations
