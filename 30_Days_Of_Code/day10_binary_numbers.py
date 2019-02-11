#!/bin/python3

import math
import os
import random
import re
import sys



if __name__ == '__main__':
    n = int(input())
    outputVect = []
    maxOnes, count = 0, 0
    
    # construct binary representation of a number
    while(n > 0):
        remainder = n % 2
        n = math.floor(n / 2)
        outputVect.append(remainder)

    # find max consecutive ones
    while len(outputVect) != 0:
        currentNum = outputVect.pop()
        if currentNum == 1:
            count += 1
        if currentNum == 0:
            count = 0
        if maxOnes < count:
            maxOnes = count

    print(maxOnes)
