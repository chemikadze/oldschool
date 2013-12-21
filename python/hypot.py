# -*- coding: utf-8 -*-

from math import sqrt

print('Вычисление гипотенузы прямоугольного треугольника.')
x = int(raw_input('Введите первый катет: '));
y = int(raw_input('Введите второй катет: '));

hypot = sqrt( x*x + y*y )

print hypot

print (u'Длина гипотенузы %f' % hypot)
