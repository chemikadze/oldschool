#!/usr/bin/python

import sys
import os
import time

class LoadAvgLogger:
	def log(self, a):
		sys.stderr.write("Not implemented storage!\nLoad average: %f %f %f" % a)
		pass

class LoadAvgFileLogger(LoadAvgLogger):
	def __init__(self, file_object):
		self.out = file_object

	def log(self, a):
		self.out.write('%d %f %f %f\n' %  ((time.time(),) + a) )
		if hasattr(self.out, 'flush'):
			self.out.flush()

logger = LoadAvgFileLogger(sys.stderr)
while True:
	logger.log(os.getloadavg())
	time.sleep(30)
