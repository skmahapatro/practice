#!/bin/python

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    singleStringOccurance = 0;
    totalOccurance = 0
    lastPartOccurance = 0
    for i, ch in enumerate(s):
        if ch is 'a':
            singleStringOccurance = singleStringOccurance+1
        if i == len(s)%n:
            lastPartOccurance = singleStringOccurance

    return ((singleStringOccurance *(int(n/len(s)))) + lastPartOccurance)


if __name__ == '__main__':

    s = "aba"
    n = 10
    result = repeatedString(s, n)
    print (result)

