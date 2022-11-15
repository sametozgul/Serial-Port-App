import serial
from datetime import datetime
import time

class SerialPort():
    def __init__(self,baudrate=9600,port="/dev/ttyUSB0"):
        self.serial_port=serial.Serial()
        self.serial_port.baudrate=baudrate
        self.serial_port.port=port

    def isport_working(self,message):
        try:
            self.serial_port.open()
            self.serial_port.write(bytes(message,"utf-8"))
            self.serial_port.close()
            return True
        except:
            raise "Port is not working"

    def send_datetime(self):
        self.serial_port.open()
        while(True):
            now=bytes(datetime.now().strftime("%H:%M:%S")+"\n","utf-8")
            self.serial_port.write(now)
            time.sleep(1)

sp=SerialPort()
print(sp.isport_working("OK"))
sp.send_datetime()
