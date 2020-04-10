#!/usr/bin/python
# -*- coding: utf-8 -*-

import re
import json
import cfscrape
import requests

ETHERSCAN_LOGIN_COOKIE = '3zd0i5lcokvpjl20bpkon3rk'

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
labled_accounts = {}
for label in account_labels:
    url = 'https://etherscan.io/'+label[1]
    cookies, user_agent = cfscrape.get_tokens(url)
    cookies['ASP.NET_SessionId'] = ETHERSCAN_LOGIN_COOKIE
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
        if address not in labled_accounts:
            labled_accounts[address] = []
        account_label = account[1]
        if account_label != '' and account_label not in labled_accounts[address]:
            labled_accounts[address].append(account_label)
        category = label[0]
        if category not in labled_accounts[address]:
            labled_accounts[address].append(category)
        if category not in categories:
            categories.append(category)

with open('labled_accounts.json', 'w') as jsonfile:
    json.dump(labled_accounts, jsonfile)

with open('categories.json', 'w') as jsonfile:
    json.dump(categories, jsonfile)
