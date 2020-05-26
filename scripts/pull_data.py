#!/usr/bin/env python3
import argparse
import requests
import os
from html.parser import HTMLParser

NORMAL_MODE = 0
INPUT_MODE = 1
INPUT_MODE_PRE = 2
OUTPUT_MODE = 3
OUTPUT_MODE_PRE = 4

class IOParser(HTMLParser):
    def __init__(self):
        super().__init__()
        self.mode = NORMAL_MODE
        self.testcase = 0
        self.curfile = None
        self.str = ""

    def handle_starttag(self, tag, attrs):
        if any(name == "class" and data == "input" for (name, data) in attrs):
            self.mode = INPUT_MODE
        elif any(name == "class" and data == "output" for (name, data) in attrs):
            self.mode = OUTPUT_MODE
        elif self.mode == INPUT_MODE and tag == "pre":
            self.testcase += 1
            self.mode = INPUT_MODE_PRE
            self.str = ""
            self.curfile = os.path.join(os.getcwd(), "data/{}.in".format(self.testcase))
        elif self.mode == OUTPUT_MODE and tag == "pre":
            self.mode = OUTPUT_MODE_PRE
            self.str = ""
            self.curfile = os.path.join(os.getcwd(), "data/{}.out".format(self.testcase))

    def handle_endtag(self, tag):
        if tag == "pre":
            self.mode = NORMAL_MODE
            with open(self.curfile, "w") as f:
                f.write(self.str.strip())

    def handle_data(self, data):
        if self.mode == INPUT_MODE_PRE or self.mode == OUTPUT_MODE_PRE:
            self.str += data + "\n"

def main():
    arg_parser = argparse.ArgumentParser(description="Fetch CodeForces input/output files")
    arg_parser.add_argument('url', metavar="url", type=str, help="The url of the problem\neg. https://codeforces.com/problemset/problem/266/B")
    args = arg_parser.parse_args()

    r = requests.get(args.url)
    assert(r.ok)

    parser = IOParser()
    parser.feed(str(r.text))

if __name__ == "__main__":
    main()
