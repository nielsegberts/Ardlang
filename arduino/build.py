#!/usr/bin/python

import subprocess
import os.path
import sys

pathname = os.path.dirname(sys.argv[0])
fullpath = os.path.abspath(pathname)
os.chdir(fullpath)

steps = [['avr-g++','-c','-g','-Os','-w','-fno-exceptions','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','Main.cpp','-oMain.cpp.o'],
['avr-gcc','-c','-g','-Os','-w','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','wiring_digital.c','-owiring_digital.c.o'],
['avr-gcc','-c','-g','-Os','-w','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','wiring_analog.c','-owiring_analog.c.o'],
['avr-gcc','-c','-g','-Os','-w','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','wiring_shift.c','-owiring_shift.c.o'],
['avr-gcc','-c','-g','-Os','-w','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','wiring.c','-owiring.c.o'],
['avr-gcc','-c','-g','-Os','-w','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','wiring_pulse.c','-owiring_pulse.c.o'],
['avr-gcc','-c','-g','-Os','-w','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','pins_arduino.c','-opins_arduino.c.o'],
['avr-gcc','-c','-g','-Os','-w','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','WInterrupts.c','-oWInterrupts.c.o'],
['avr-g++','-c','-g','-Os','-w','-fno-exceptions','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','WString.cpp','-oWString.cpp.o'],
['avr-g++','-c','-g','-Os','-w','-fno-exceptions','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','WMath.cpp','-oWMath.cpp.o'],
['avr-g++','-c','-g','-Os','-w','-fno-exceptions','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','HardwareSerial.cpp','-oHardwareSerial.cpp.o'],
['avr-g++','-c','-g','-Os','-w','-fno-exceptions','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','Print.cpp','-oPrint.cpp.o'],
['avr-g++','-c','-g','-Os','-w','-fno-exceptions','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','Tone.cpp','-oTone.cpp.o'],
#['avr-g++','-c','-g','-Os','-w','-fno-exceptions','-ffunction-sections','-fdata-sections','-mmcu=atmega168','-DF_CPU=16000000L','-DARDUINO=22','-I.','main.cpp','-omain.cpp.o'],
['avr-ar','rcs','core.a','wiring_digital.c.o'],
['avr-ar','rcs','core.a','wiring_analog.c.o'],
['avr-ar','rcs','core.a','wiring_shift.c.o'],
['avr-ar','rcs','core.a','wiring.c.o'],
['avr-ar','rcs','core.a','wiring_pulse.c.o'],
['avr-ar','rcs','core.a','pins_arduino.c.o'],
['avr-ar','rcs','core.a','WInterrupts.c.o'],
['avr-ar','rcs','core.a','WString.cpp.o'],
['avr-ar','rcs','core.a','WMath.cpp.o'],
['avr-ar','rcs','core.a','HardwareSerial.cpp.o'],
['avr-ar','rcs','core.a','Print.cpp.o'],
['avr-ar','rcs','core.a','Tone.cpp.o'],
#['avr-ar','rcs','core.a','main.cpp.o'],
['avr-ar','rcs','core.a','Main.cpp.o'],
['avr-g++','-Os','-Wl,--gc-sections','-mmcu=atmega168','-o','Main.cpp.elf','Main.cpp.o','core.a','-L/tmp/build8507635072943001777.tmp','-lm'],
['avr-objcopy','-O','ihex','-j','.eeprom','--set-section-flags=.eeprom=alloc,load','--no-change-warnings','--change-section-lma','.eeprom=0','Main.cpp.elf','Main.cpp.eep'],

['avr-objcopy','-O','ihex','-R','.eeprom','Main.cpp.elf','Main.cpp.hex']]

for step in steps:
	retcode = subprocess.call(step)
	if retcode!=0:
		print("Something has gone wrong!, exiting")
		break
	



