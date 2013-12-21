#!/usr/bin/python
# -*- coding: utf-8 -*-

import re

print 'Нахождение наибольшего слова в строке.'
s = unicode(raw_input('Введите строку:\n'), 'UTF-8')

words = re.split( '\.|\ |,', s )
maxwlen = len(words[0])
maxw = words[0]

for i in words[1:]:
	length = len(i)
	if (length > maxwlen):
		maxwlen = length
		maxw = i

print (u'Наибольшее слово:\'%s\' длиной %d.' % (maxw, maxwlen))
