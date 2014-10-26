#!/usr/bin/python
import sys
import math
from operator import itemgetter
from functools import partial
x = 5.12
f_values = []
def membership(value,center):
    #square root of square of value
    output = value*center
    g_values.append(output)
    result = sum([g_values[n] for n in range(0,len(g_values))])
    print(result)
    outputTap(result)

def outputTap(result):
    if result >= 60:
        print("tap 4")
    elif result > 20 and result < 60:
        print("tap 3")
    elif result >= -20 and result <=20:
        print("tap 2")
    elif result > -60 and result < -20:
        print("tap 1")
    else:
        print("tap 0")

def trap(a, b, c, d, x):
    first = (x - a) / (b - a)
    second = (d - x) / (d - c)
    return( max(min(first, 1., second), 0.))
        
def tri(a, b, x):
    a = float(a)
    b = float(b)
    m = (a + b) / 2.
    first = (x - a) / (m - a)
    second = (b - x) / (b - m)
    print(max(min(first, second), 0.))

#input definition

largeNeg = trap(-51,-50,-6,-5,x)
if largeNeg > 0:
    centerVal = -100
    membership(largeNeg,centerVal)
    
#def neg(x):
neg = trap(-6,-5,-3,-2,x)
if neg > 0:
    centerVal = -50
    membership(neg,centerVal)

#def zero(x):
zero = trap(-3,-2,2,3,x)
if zero > 0:
    centerVal = 0
    membership(zero,centerVal)

#def positive(x):
positive = trap(2,3,5,6,x)
if positive > 0:
    centerVal = 50
    membership(positive,centerVal)

#def largePos(x):
largePos = trap(5,6,50,51,x)
if largePos > 0:
    centerVal = 100
    membership(largePos,centerVal)

