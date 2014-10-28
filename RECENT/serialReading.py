#!python
import time
import cgi
from serial import Serial
import subprocess
import re
import threading
g_values = []
class myThread(threading.Thread):
    def _init_(self,threadID,portname):
        threading.Thread._init_(self)
        self.threadID = threadID
        self.portname = portname
    def run(self):
        threadLock.acquire()
        uart1(self.threadID,self.portname)
        threadLock.release()
        
def uart1(name,portName):
    ser = Serial(portName, baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=None)
    print("connected to: " + ser.portstr)
    while True:
        line = ser.readline(ser.inWaiting()).decode('utf-8')[:-2]
        if line:
            t = line.split(",")
            line2 = float(t[5])
            if line2 > 0:
                do_fuzzy(line2)
    ser.close()
#errorResult = [(220-g_values[n]) for n in range(0,len(g_values))]
#result = [abs(errorResult[n]) for n in range(0,len(errorResult))]
#maxhere=max(result)
#do_fuzzy(errorResult,name)
    #ser.close()

def do_fuzzy(value):
    print(value)
#errorResult = [(220-g_values[n]) for n in range(0, len(g_values))]
#do_fuzzy(errorResult)
    
threadLock=threading.Lock()
threads = []
#create new threads
thread1 = threading.Thread(target = uart1, args=(" uart4",'/dev/ttyS4'))
thread2 = threading.Thread(target = uart1, args=("uart3",'/dev/ttyS3'))
thread3 = threading.Thread(target = uart1, args=("uart7",'/dev/ttyS6'))
#thread4 = threading.Thread(target = uart1, args=("uartUSB",'/dev/ttyUSB0')
#start new Thread!
thread1.start()
thread2.start()
thread3.start()
#thread4.start()
#add threads to thread list
threads.append(thread1)
threads.append(thread2)
threads.append(thread3)
#threads.append(thread4)
#wait for all threads to complete
for t in threads:
    t.join()
#print("Exiting Main Thread")

#errorResult = [(220-g_values[n]) for n in range(0,len(g_values))] 
#result = [abs(errorResult[n]) for n in range(0,len(errorResult))]
#do_fuzzy(max(result))   
    
