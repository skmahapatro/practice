#!/bin/python
# Hacker Rank : socks stock merchant problem
import math
import os
import random
import re
import sys

# Complete the sockMerchant function below.
def sockMerchant(n, ar):
    numOfPairs = 0
    colorsDict = dict()
    for ele in ar:
        if ele in colorsDict:
            del colorsDict[ele]
            numOfPairs = numOfPairs+1
        else:
            colorsDict[ele] = 1

    return numOfPairs

if __name__ == '__main__':
#    n = int(raw_input())

#    ar = map(int, raw_input().rstrip().split())
    ar = [10,20,10,20, 30]
    result = sockMerchant(5, ar)

    print(result)
