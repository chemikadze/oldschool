#!/usr/bin/python
# -*- coding: utf-8 -*-

import os
import sys
import urllib
import re

DEST = './loadpage/'

def getCorrectName(filename = ''):
	i = 1
	result = filename
	while (os.path.exists( result ) ):
		result = filename + '(%d)' % i
		i += 1
	return result


def loadResource(url = '', dst = ''):
	if (url == ''):
		return
	print 'Loading \'%s\'' % url
	if (dst[-1] != '/'):
		dst += '/'
	filename = url.split('/')[-1]
	if (filename == ''):
		filename = 'noname'
	filename = getCorrectName(dst + filename)
	out = open(filename, 'w')
	try:
		res = urllib.urlopen(url)
	except:
		print 'Failed.'
		return
	data = res.read()
	out.write( data )
	res.close()
	out.close()
	print 'Saved as \'%s\'' % filename
	return (data, filename)


def loadPage(url = ''):
	if (url == ''):
		return
	data, destination = loadResource( url, DEST )
	destination += '.files'
	if (not os.path.exists(destination)):
		os.mkdir(destination)
	for i in re.findall( ur'http://[^\ \'\"\n]+', data ):
		loadResource( i, destination )

if (not os.path.exists(DEST)):
	os.mkdir(DEST)

if (len(sys.argv) > 1):
	for i in sys.argv[1:]:
		loadPage(i)
else:
	url = str(raw_input('Enter URL: '))
	loadPage(url)
