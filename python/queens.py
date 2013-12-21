#!/usr/bin/python

N = 8
a = [ [ 0 for i in range(N) ] for i in range(N) ]
rows = [ 0 for i in range(N) ]
cols = [ 0 for i in range(N) ]
pos = []
k = 1

def checkDiagonal(x, y, f):
	x,y = f(x,y)
	while ((x>=0) and (y>=0) and (x<N) and (y<N)):
		if (a[y][x]):
			return 0
		x,y = f(x,y)
	return 1

def checkPos(x, y):
	if (rows[y] or cols[x]):
		return 0
	for f in [ lambda x, y: (x+1, y+1), lambda x, y: (x-1, y+1), lambda x, y: (x+1, y-1), lambda x, y: (x-1, y-1) ]:
		if (not checkDiagonal(x, y, f)):
			return 0
	return 1

def printPos():
	global k
	print ("%d" + " %s"*len(pos)) % tuple( [k] + [chr(ord('a')+x)+str(y+1) for x,y in pos] )
#	print
#	for row in a:
#		print row
#	print
	k = k+1

def makeStep(x, y):
	pos.append((x, y))
	if (checkPos(x, y)):
		rows[y] = cols[x] = a[y][x] = 1
		if (len(pos) < N):
			nextStep(x, y)
		else:
			printPos()
		rows[y] = cols[x] = a[y][x] = 0
	pos.pop()

def nextStep(x, y):
	for j in range(x+1, N):
		makeStep(j, y)
	for i in range(y+1, N):
		for j in range(N):
			makeStep(j, i)

def solve():
	nextStep(-1, 0)

solve()
