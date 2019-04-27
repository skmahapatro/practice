#!/bin/python
import math
import os
import random
import re
import sys

# Hacker Rank: countingValleys function below.
def countingValleys(n, s):
    currentLevel = 0
    prevLevel    = 0
    numOfValley  = 0
    for c in s:
	print(c)
        prevLevel = currentLevel
        if c is 'D':
            currentLevel = currentLevel-1
        else:
            currentLevel = currentLevel+1
        if currentLevel is 0 and prevLevel is -1:
            numOfValley = numOfValley+1
    return numOfValley

if __name__ == '__main__':
    s = 'UDDDUDUU'

    result = countingValleys(8, s)
    print(result)

