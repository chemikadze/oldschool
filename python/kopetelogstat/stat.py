#!/usr/bin/python

import sys

class LogRec:
	def __init__(self):
		self.income = 0
		self.outcome = 0
	
	def __getattr__(self, attr):
		if self.__dict__.has_key(attr):
			return self.__dict__[attr]
		elif attr == 'count':
			return self.income+self.outcome
		else:
			raise AttributeError()

class LogStat:
	def __init__(self):
		self.stat = {}
	
	def count_msg(self, user, income):
		if not self.stat.has_key(user):
			self.stat[user] = LogRec()
		if income:
			self.stat[user].income += 1
		else:
			self.stat[user].outcome += 1

if __name__ == '__main__':
	try:
		stat = LogStat()
		while True:
			data = sys.stdin.readline()
			if not data:
				raise IOError
			data = data.split()
			data = (' '.join(data[:-1]), data[-1])
			try:
				stat.count_msg(data[0], int(data[1]))
			except:
				print >> sys.stderr, 'Error with dataset: %s' % str(data)
	except IOError:
		print stat.stat.keys()
		for name, rec in sorted(stat.stat.items(), lambda x,y: cmp(x[1].count, y[1].count)):
#			print '%s: %d %d %d' % (name, rec.count, rec.income, rec.outcome)
			print '%s: %d' % (name, rec.count)
