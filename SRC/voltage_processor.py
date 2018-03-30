from __future__ import division
import threading
import errors as e
import time

class VoltageProcessor(threading.Thread):
        def __init__(self):
                threading.Thread.__init__(self)
                self.__m_volcol_list = None
                self.__m_exit = False

        def run(self):
                while not self.__m_exit:
                        result = int(self.__theAverage())

			time.sleep(1)

                        if result >= 60:
                                print("tap 4")
                                gpio1=int(4)
                                gpio=str(gpio1)
                                value=1
				self.largeDown(gpio,value)

                        else:
                                gpio1=int(4)
                                gpio=str(gpio1)
                                value=0
                                self.largeDown(gpio,value)


                        if result > 20 and result < 60:
                                print("tap 3")
                                gpio1=int(5)
                                gpio=str(gpio1)
                                value=1
                                self.down(gpio,value)

                        else:
                                gpio1=int(5)
                                gpio=str(gpio1)
                                value=0
                                self.down(gpio,value)


                        if result >= -20 and result <=20:
                                print("tap 2")
                                gpio1=int(6)
                                gpio=str(gpio1)
                                value=1
                                self.noChange(gpio,value)

                        else:
                                gpio1=int(6)
                                gpio=str(gpio1)
                                value=0
                                self.noChange(gpio,value)

                        if result > -60 and result < -20:
                                print("tap 1")
                                gpio1=int(7)
                                gpio=str(gpio1)
                                value=1
                                self.up(gpio,value)
                        else:
                                gpio1=int(7)
                                gpio = str(gpio1)
                                value=0
                                self.up(gpio,value)

                        if result <= -60 :
                                print("tap 0")
                                gpio1=int(8)
                                gpio=str(gpio1)
                                value=1
                                self.largeUp(gpio,value)

                        else:
                                gpio1=int(8)
                                gpio=str(gpio1)
                                value=0
                                self.largeUp(gpio,value)

        def addVolCol(self, p_volcol):
                if self.__m_volcol_list is None:
                        self.__m_volcol_list = []
                self.__m_volcol_list.append(p_volcol)

        def closeProcessor(self):
                self.__m_exit = True

        def __theAverage(self):
                if self.__m_volcol_list is None:
                        return 0
                if len(self.__m_volcol_list) == 0:
                        raise e.E_NoProcesses()

                temp_val = 0
                counter = 0
                index = 0
                for volcol in self.__m_volcol_list:
                        try:
                                counter += 1
                                temp_val += volcol.getValue()
                        except e.E_NoValue:
                                pass
                        except (Exception) as err:
                                continue
                        index += 1
                return temp_val/counter


        #GPIOS ACTIVATION
        def largeDown(self,gpio,value):
            # print("Tap Large Down.\n")
                path = '/sys/class/gpio/gpio' + gpio + '_pg4/value'
                f = open(path,'w')
                f.write(str(value))
                f.close()

        def down(self,gpio,value):
          #  print("Tap Down\n")
                path = '/sys/class/gpio/gpio' + gpio + '_pg3/value'
                f = open(path,'w')
                f.write(str(value))
                f.close()

        def noChange(self,gpio,value):
           # print("No Change Tap\n")
                path = '/sys/class/gpio/gpio' + gpio + '_pg1/value'
                f = open(path,'w')
                f.write(str(value))
                f.close()

        def up(self,gpio,value):
           # print("Tap Up\n")
                path = '/sys/class/gpio/gpio' + gpio + '_pg0/value'
                f = open(path,'w')
                f.write(str(value))
                f.close()

        def largeUp(self,gpio,value):
           # print("Tap Large Up \n")
                path = '/sys/class/gpio/gpio' + gpio + '_pg2/value'
                f = open(path,'w')
                f.write(str(value))
                f.close()
