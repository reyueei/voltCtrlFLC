#!/usr/bin/python
import sys
import math
from operator import itemgetter
from functools import partial

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
    return(max(min(first, second), 0.))

#Input : Voltage Error
x = 0.12
largeNeg = trap(-51,-50,-6,-5,x)
neg = trap(-6,-5,-3,-2,x)
zero = trap(-3,-2,2,3,x)
positive = trap(2,3,5,6,x)
largePos = trap(5,6,50,51,x)

result = max(largeNeg,neg,zero,positive,largePos)
print(result)

#rules
if result == largeNeg:
    largeDown(result)
if result == neg:
    print("N")
if result == zero:
    print("Z")
if result == positive:
    print("P")
if result == largePos:
    print("LP")

#define Outputs
    
"""    
def largeDown():
    return tri(-100, -100, -80)
def down():
    return tri(-80,-50,-20)
def noChage():
    return tri(-20, 0, 20)
def up():
    return tri(20, 50, 80)
def largeUp():
    return tri(80,100,100)
    

 return tri(5., 9., size)


rules = [
    (largeNeg, largeDown),
    (neg, down),
    (zero, noChange),
    (positive, up),
    (largePos, largeUp)
]

"""
