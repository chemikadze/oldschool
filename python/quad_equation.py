#!/usr/bin/python
# -*- coding: utf-8 -*-

from math import sqrt

print('Решение квадратного уравнения')

A = float(raw_input('Введите коэфициент A: '))
B = float(raw_input('Введите коэфициент B: '))
C = float(raw_input('Введите коэфициент C: '))

D = B*B - 4. * A * C

if (D == 0):
	x = - (B) / (2*A)
	print('D = %f\nОдин корень' % D)
	print('x = %f' % x)

elif (D < 0):
	print('D = %f < 0\nНет решений' % D)

elif (D > 0):
	x1 = - (B - sqrt(D)) / (2*A)
	x1 = - (B + sqrt(D)) / (2*A)
	print('D = %f > 0\n2 корня')
	print('x1 = %f\nx2 = %f' % x1, x2)
