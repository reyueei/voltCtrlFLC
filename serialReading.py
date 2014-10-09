#!python
import time
import cgi
from serial import Serial
import subprocess
import re
import threading

class myThread(threading.Thread):
    def _init_(self,threadID,portname):
        threading.Thread._init_(self)
        self.threadID = threadID
        self.portname = portname
    def run(self):
        print("Starting ",self.threadID)
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
                print(name,line2)
                if line == '520':
                    subprocess.call(["xte", "key Up"])
                elif line == '620':
                    subprocess.call(["xte", "key Down"])
                elif line == '110':
                    break
    ser.close()
    
threadLock=threading.Lock()
threads = []
#create new threads
thread1 = threading.Thread(target = uart1, args=(" uart1",'/dev/ttyS4'))
thread2 = threading.Thread(target = uart1, args=("uart2",'/dev/ttyS2'))

#start new Thread!
thread1.start()
thread2.start()

#add threads to thread list
threads.append(thread1)
threads.append(thread2)

#wait for all threads to complete
for t in threads:
    t.join()
print("Exiting Main Thread")
    
    
