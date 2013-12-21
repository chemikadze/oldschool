#!/usr/bin/python
# -*- coding: utf-8 -*-

import urllib
import re

class Timezones:
	def get_tzhash():
		res = {}
		inp = urllib.urlopen("http://www.time-zones.ru/goroda.htm")
		regexp = r"<tr>\s*<td>\s*([^<\s]+)\s*</td>\s*<td>\s*GMT\+([0-9]+)\s*</td>"
		for city,gmtplus in re.findall(regexp, inp.read()):
			city = unicode(city, 'cp1251').encode('utf8')
			res[city] = int(gmtplus)
		return res
	
	tzhash = get_tzhash()

	def get_gmt_plus(self, string):
		if (self.tzhash.has_key(string)):
			return self.tzhash[string]
		return None

if (__name__ == '__main__'):
	tz = Timezones()
	for city_gmt in tz.tzhash.iteritems():
		print "%s\tGMT+%d" % city_gmt
