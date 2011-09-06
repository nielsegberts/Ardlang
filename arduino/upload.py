#!/usr/bin/python

import os.path
import sys
import subprocess
import serial
import time


pathname = os.path.dirname(sys.argv[0])
fullpath = os.path.abspath(pathname)
os.chdir(fullpath)

ser = serial.Serial("/dev/ttyUSB0")
ser.setDTR(1)
time.sleep(0.5)
ser.setDTR(0)
ser.close()

step = ['arduino-0022/hardware/tools/avrdude','-Carduino-0022/hardware/tools/avrdude.conf','-v','-v','-v','-v','-patmega168','-cstk500v1','-P/dev/ttyUSB0','-b19200','-D','-Uflash:w:Main.cpp.hex:i'] 

retcode = subprocess.call(step)

