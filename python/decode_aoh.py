#!/usr/bin/python
# -*- coding: utf-8 -*-

s = unicode( raw_input('Введите полученный номер: ') )
answer = ''

if (not len(s)):
	print 'Номер пуст.'
	exit()

encoded = False
buf = s[0]
last = ''
for i in s[1:]:
	if ((i == buf) and (not encoded)):
		if ('0' <= i <= '9'):
			encoded = True
			answer += i
			last = i
		elif (i == '#'):
			answer += last
			encoded = True
	elif (i != buf):
		buf = i
		encoded = False

print (u'Полученный номер: %s' % answer)
