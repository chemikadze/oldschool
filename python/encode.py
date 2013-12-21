#!/usr/bin/python
# -*- coding: utf-8 -*-

s = unicode(raw_input('Введите строку:\n'), 'UTF-8')

for i in ['cp1251', 'utf-16' ]:
	print s.encode( i )

