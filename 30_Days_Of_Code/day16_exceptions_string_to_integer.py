#!/bin/python3

import sys

S = input().strip()

try:
    print(int(S))
except Exception as e:
    print("Bad String")

