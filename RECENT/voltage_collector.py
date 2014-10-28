from serial import Serial
import re
import threading
import errors as e
import random
import time
import sys
import math
import cgi
from operator import itemgetter
from functools import partial


class VoltageCollector(threading.Thread):

        def membership(self,value,center):
            #square root of square of value
            #DOM and deffuzification
            output = value*center
           #g_values.append(output)
           # result = sum([g_values[n] for n in range(0,len(g_values))])
            #print(output)
	    self.__m_bucket.append(output)
            #print(result)
            #outputTap(result)

   
        def trap(self, a, b, c, d, error):
            first = (error - a) / (b - a)
            second = (d - error) / (d - c)
            return( max(min(first, 1., second), 0.))

        #input definition
        


        def __init__(self, p_thread_id, p_portname, p_path):
                threading.Thread.__init__(self)
                self.__m_thread_id = p_thread_id
                self.__m_portname = p_portname
                self.__m_path = p_path
                self.__m_serial = Serial(self.__m_path, baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=None)
                self.__m_bucket = []
                #self.__m_fuzzify = fuzzification(error)
                
                        
        def run(self):
                while True:
                        #number = random.uniform(1,100)
                        #self.__m_bucket.append(number)
                        #print (str(self.__m_thread_id) + " generated: " + str(number))
                        #time.sleep(5)
                        try:
                                raw_data = self.__m_serial.readline(self.__m_serial.inWaiting()).decode('utf-8')[:-2]
                                if raw_data:
                                        list_of_val = raw_data.split(",")
                                        voltage = float(list_of_val[5])
                                        error = 220 - voltage
                                        self.fuzzification(error)
                                        #self.__m_bucket.append(voltage)
                        except (Exception) as err:
                                print("Error:" + str(err))
                                #time.sleep(5)
                self.__m_serial.close()

        
        def getValue(self):
                if len(self.__m_bucket) == 0:
                        raise e.E_NoValue()
                return self.__m_bucket.pop(0)

        def fuzzification(self,error):
            
            largeNeg = self.trap(-51,-50,-6,-5,error)
            if largeNeg > 0:
                centerVal = -94
                print("LN = ", largeNeg)
                self.membership(largeNeg,centerVal)
                
            #def neg(x):
            neg = self.trap(-6,-5,-3,-2,error)
            if neg > 0:
                centerVal = -53.3
                print("N = ", neg)
                self.membership(neg,centerVal)

            #def zero(x):
            zero = self.trap(-3,-2,2,3,error)
            if zero > 0:
                centerVal = 0
                print("Z = ", zero)
                self.membership(zero,centerVal)

            #def positive(x):
            positive = self.trap(2,3,5,6,error)
            if positive > 0:
                centerVal = 53.3
                print("P = ",positive)
                self.membership(positive,centerVal)

            #def largePos(x):
            largePos = self.trap(5,6,50,51,error)
            if largePos > 0:
                centerVal = 94
                print("LP = ",largePos)
                self.membership(largePos,centerVal)

        
