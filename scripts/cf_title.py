#!/usr/bin/env python3
import argparse
import requests
import os
import bs4

def main():
    arg_parser = argparse.ArgumentParser(description="Fetch CodeForces input/output files")
    arg_parser.add_argument('url', metavar="url", type=str, help="The url of the problem\neg. https://codeforces.com/problemset/problem/266/B")
    args = arg_parser.parse_args()

    r = requests.get(args.url)
    if not r.ok:
        print("Web error {}".format(r.status_code))

    soup = bs4.BeautifulSoup(r.content, 'html.parser')
    titles = soup.findAll("div", {"class": "title"})
    if not titles:
        print("Cannot find title")
    else:
        print(titles[0].text)

if __name__ == "__main__":
    main()
