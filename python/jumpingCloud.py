#!/bin/python

import math
import os
import random
import re
import sys

# Complete the jumpingOnClouds function below.
def jumpingOnClouds(cloud):
    jumpNum = 0
    for i, c in enumerate(cloud):
        if i+2 > len(cloud):
            break;
        else:
            index = i+2
        if cloud[index] is 0:
            i += 2
            jumpNum += 1
        else:
            i += 1
            jumpNum += 1
    return jumpNum

if __name__ == '__main__':

    result = jumpingOnClouds('000010')

    print(result)
