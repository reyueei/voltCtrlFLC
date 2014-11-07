#!python
import time
import cgi
from serial import Serial
import subprocess
import re
import threading
import Queue

exitFlag=0
class myThread(threading.Thread):
    def _init_(self,threadID,portname,q):
        threading.Thread._init_(self)
        self.threadID = threadID
        self.portname = portname
        self.q = q
    def run(self):
        print("Starting ",self.threadID)
        threadLock.acquire()
        uart1(self.portname,self.q)
        threadLock.release()
        
def uart1(portName,q):
    while not exitFlag:
        queueLock.acquire()
        if not workQueue.empty():
            data = q.get()
            ser = Serial(data, baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=None)
            while True:
                line = ser.readline(ser.inWaiting()).decode('utf-8')[:-2]
                if line:
                    t = line.split(",")
                    line2 = float(t[5])
                    if line2 > 0:
                        print(portName,line2)
                        if line == '520':
                            subprocess.call(["xte", "key Up"])
                        elif line == '620':
                            subprocess.call(["xte", "key Down"])
                        elif line == '110':
                            break
            ser.close()

threadList = ["uart-1","uart-2"]
portList = ['/dev/ttyS2','/dev/ttyS3']
queueLock=threading.Lock()
workQueue = Queue.Queue(2)
threads = []
threadID = 1

#create new threads
for tname in threadList:
    thread = myThread(threadID, tname, workQueue)
    thread.start()
    threads.append(thread)
    threadID +=1

#Fill the queue
queueLock.acquire()
for word in portList:
    workQueue.put(word)
queueLock.release()

#wait for workQueue to empty
while not workQueue.empty():
    pass
exitFlag = 1

#wait for all threads to complete
for t in threads:
    t.join()
print("Exiting Main Thread")
    
    
