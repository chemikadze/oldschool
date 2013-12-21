#!/usr/bin/python

tableC = {}
tableN = {}

def countToWin(glasses, to_win):
	__sum = lambda x,y: x+y
	fac = lambda n: reduce(lambda x,y: x*y, xrange(1, n+1), 1)
	#A = lambda num,frm: reduce(lambda x,y: x*y, xrange(frm-num+1, frm+1), 1)
	def C(num, frm):
		global tableC
		if tableC.has_key((num,frm,)):
			return tableC[(num,frm,)]
		else:
			c = fac(frm)/(fac(num)*fac(frm-num))
			tableC[(num,frm,)] = c
			return c
	def N(num, frm):
		global tableN
		if tableN.has_key((num,frm,)):
			return tableN[(num,frm,)]
		else:
			n = frm==num and 1 or C(num,frm)*(fac(frm-num)-reduce(__sum, [N(i,frm-num) for i in xrange(1, frm-num+1)], 0))
			tableN[(num,frm,)] = n
			return n
	return reduce(lambda x,y: (x+y)%1051962371, [N(i, glasses) for i in range(to_win, glasses)], 1)

N = raw_input()
for i in xrange(int(N)):
	test = [int(s) for s in raw_input().split()]
	print countToWin(test[0], test[1])