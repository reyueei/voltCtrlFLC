#!/usr/bin/python
import sys
import math
from operator import itemgetter
from functools import partial
x = 5.12
g_values = []
def membership(value,center):
    #square root of square of value
    #DOM and deffuzification
    output = value*center
    g_values.append(output)
    result = sum([g_values[n] for n in range(0,len(g_values))])
    print(result)
    outputTap(result)



#GPIOS ACTIVATION
def largeDown(gpio,value):
    print("Tap Large Down.\n")
    path = '/sys/class/gpio/gpio' + gpio + '_pg4' + gpio + '/value'
    f = open(path,'w')
    f.write(str(value))
    f.close()
    
     
def down(gpio,value):
    print("Tap Down\n")
    path = '/sys/class/gpio/gpio' + gpio + '_pg3' + gpio + '/value'
    f = open(path,'w')
    f.write(str(value))
    f.close()
 
def noChange(gpio,value):
    print("No Change Tap\n")
    path = '/sys/class/gpio/gpio' + gpio + '_pg1' + gpio + '/value'
    f = open(path,'w')
    f.write(str(value))
    f.close()
 
def up(gpio,value):
    print("Tap Up\n")
    path = '/sys/class/gpio/gpio' + gpio + '_pg0' + gpio + '/value'
    f = open(path,'w')
    f.write(str(value))
    f.close()

def largeUp(gpio,value):
    print("Tap Large Up \n")
    path = '/sys/class/gpio/gpio' + gpio + '_pg2' + gpio + '/value'
    f = open(path,'w')
    f.write(str(value))
    f.close()
    

def outputTap(result):
    
    if result >= 60:
        print("tap 4")
        gpio1=int(4)
        gpio=str(gpio1)
        value=1
        largeDown(gpio,value)
        
    elif result > 20 and result < 60:
        print("tap 3")
        gpio1=int(5)
        gpio=str(gpio1)
        value=1
        down(gpio,value)
             
    elif result >= -20 and result <=20:
        print("tap 2")
        gpio1=int(6)
        gpio=str(gpio1)
        value=1
        noChange(gpio,value)
      
    elif result > -60 and result < -20:
        print("tap 1")
        gpio1=int(7)
        gpio=str(gpio1)
        value=1
        up(gpio,value)
     
    elif result < -60 :
        print("tap 0")
        gpio1=int(8)
        gpio=str(gpio1)
        value=1
        largeUp(gpio,value)

    else:
        value = 0
        

        
def trap(a, b, c, d, x):
    first = (x - a) / (b - a)
    second = (d - x) / (d - c)
    return( max(min(first, 1., second), 0.))

#input definition

largeNeg = trap(-51,-50,-6,-5,x)
if largeNeg > 0:
    centerVal = -100
    print("LN = ", largeNeg)
    membership(largeNeg,centerVal)
    
#def neg(x):
neg = trap(-6,-5,-3,-2,x)
if neg > 0:
    centerVal = -50
    print("N = ", neg)
    membership(neg,centerVal)

#def zero(x):
zero = trap(-3,-2,2,3,x)
if zero > 0:
    centerVal = 0
    print("Z = ", zero)
    membership(zero,centerVal)

#def positive(x):
positive = trap(2,3,5,6,x)
if positive > 0:
    centerVal = 50
    print("P = ",positive)
    membership(positive,centerVal)

#def largePos(x):
largePos = trap(5,6,50,51,x)
if largePos > 0:
    centerVal = 100
    print("LP = ",largePos)
    membership(largePos,centerVal)
