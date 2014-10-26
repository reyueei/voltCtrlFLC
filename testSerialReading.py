#!python
import time
import cgi
from serial import Serial
import re
import threading
g_values = []
f_values = []
class myThread(threading.Thread):
    def _init_(self,threadID,portname):
        threading.Thread._init_(self)
        self.threadID = threadID
        self.portname = portname
    def run(self):
        print("Starting ",self.threadID)
        threadLock.acquire()
        do_process(self.threadID,self.portname)
        threadLock.release()
        
def do_process(name,portName):
    ser = Serial(portName, baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=None)
    print("connected to: " + ser.portstr)
    while True:
        line = ser.readline(ser.inWaiting()).decode('utf-8')[:-2]
        if line:
            t = line.split(",")
            line2 = float(t[5])
            if line2 > 0:
                #g_values.append(line2)
                error = 221-line2
                do_fuzzy(line2)
    ser.close()

def membership(value,center):
    #square root of square of value
    output = value*center
    f_values.append(output)
    result = sum([g_values[n] for n in range(0,len(g_values))])
    print(result)
    g_values.append(result)
    #outputTap(result)

# output    
def outputTap(average):
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
def do_fuzzy(x):
    
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

def trap(a, b, c, d, value):
    first = (value - a) / (b - a)
    second = (d - value) / (d - c)
    return( max(min(first, 1., second), 0.))

#input:voltage error fuzzy sets
largeNeg = trap(-51,-50,-6,-5,value)
neg = trap(-6,-5,-3,-2,value)
zero = trap(-3,-2,2,3,value)
positive = trap(2,3,5,6,value)
largePos = trap(5,6,50,51,value)

    
threadLock=threading.Lock()
threads = []
#create new threads
thread1 = threading.Thread(target = do_process, args=(" uart1",'/dev/ttyS4'))
thread2 = threading.Thread(target = do_process, args=("uart2",'/dev/ttyS2'))
thread3 = threading.Thread(target = do_process, args=("uart3",'/dev/ttyS6'))
#start new Thread!
thread1.start()
thread2.start()
thread3.start()
#add threads to thread list
threads.append(thread1)
threads.append(thread2)
threads.append(thread3)
#wait for all threads to complete
for t in threads:
    t.join()

#errorResult = [(220-g_values[n]) for n in range(0,len(g_values))]
#result = [abs(errorResult[n]) for n in range(0,len(errorResult))]
#do_fuzzy(max(result))
ave = sum(g_values[n] for n in range(0,len(g_values)))
average = ave/3
outputTap(average)
    
