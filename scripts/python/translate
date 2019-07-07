#! /usr/bin/python3

import sys


def help():
	print('usage: translate file_name')

if len(sys.argv) > 1:
	path = sys.argv[1]
else:
	print('Error: Argument needed')
	help()
	sys.exit(-1)

try:
	f = open(path, 'rb')
except IOError:
	print('Error: could not read file "' + path + '".')
	sys.exit(-2)

print('+------------+-------+-------+------+-------+')
print('|   Binary   |  Oct. |  Dec. | Hex. | UTF-8 |')
print('+------------+-------+-------+------+-------+')
byte = f.read(1)
while byte:
	print('|  {0:08b}  |  {0:03o}  |  {0:03}  |  {0:02X}  |  {1:2s}   |'.format(ord(byte), str(byte)[2:-1]))
	byte = f.read(1)


print('+------------+-------+-------+------+-------+')

