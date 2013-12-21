#!/usr/bin/python

import sys
from xml.sax.saxutils import escape as escapehtml

blocksize = 1024*1024*4

if __name__ == '__main__':
	while True:
		data = sys.stdin.read(blocksize)
		if data:
			sys.stdout.write(escapehtml(data))
		else:
			exit()
