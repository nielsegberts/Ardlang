#!/usr/bin/python

import sys
import serial # if you have not already done so
ser = serial.Serial('/dev/ttyUSB0', 9600)
print(sys.argv[1])
ser.write(sys.argv[1]+"~")
