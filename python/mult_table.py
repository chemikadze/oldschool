#!/usr/bin/python
# -*- coding: utf-8 -*-

print('Таблица умножения для одного числа, от a до b')
N = int(raw_input('Введите N:'))
a = int(raw_input('Введите a:'))
b = int(raw_input('Введите b:'))

for i in range(a,b+1):
	print N, ' * ', i, ' = ', N*i
