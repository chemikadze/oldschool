#!/usr/bin/python
# -*- coding: utf-8 -*-

import urllib
import re
import sys
from math import ceil, floor
import getopt
		
global ENABLE_DEBUG
global DEFAULT_HOUR
global MAX_WIDTH
global RECONNECT_TIMES
ENABLE_DEBUG = False
DEFAULT_HOUR = 3
MAX_WIDTH = 80
RECONNECT_TIMES = 5

# tries to download data by URL, reconnecting one ore more times
def read_retrying(url):
	recon = RECONNECT_TIMES + (RECONNECT_TIMES==0)*1
	while (recon>0):
		try:
			fd = urllib.urlopen(url)
			if fd:
				return fd.read()
			else:
				return None
		except IOError:
			print("Error! Reconnecting...")
			if (fd):
				fd.close();
			recon -= 1
		except UnicodeError:
			if (ENABLE_DEBUG):
				print("Wrong url!")
			return None
	return None

# were in timezones.py, placed here to post to pastebin
class Timezones:
	def get_tzhash():
		res = {}
		inp = urllib.urlopen("http://www.time-zones.ru/goroda.htm")
		regexp = r"<tr>\s*<td>\s*([^<\s]+)\s*</td>\s*<td>\s*GMT\+([0-9]+)\s*</td>"
		for city,gmtplus in re.findall(regexp, inp.read()):
			city = unicode(city, 'cp1251').encode('utf8').strip()
			res[city] = int(gmtplus)
		return res
	
	tzhash = get_tzhash()

	def get_gmt_plus(self, string):
		if (self.tzhash.has_key(string)):
			return self.tzhash[string]
		return None

# welinux.ru parser
class Parser:
	users_cities = {}
	tzones = None
	expr = r"<div class='[fst_]*top'>\s*<span class='date'>\s*([0-9.]+)\s+([0-9:]+)\s*</span>\s*<a[^>]+>\s*([^<\s]+)\s*</a>\s*</div>"
	parser = re.compile(expr)
	
	def __init__(self, blognum = 0):
		if (not self.tzones):
			self.tzones = Timezones()
		self.hours = dict([ (i, 0) for i in range(24) ])
		self.blognum = blognum
		self.blogaddr = "http://welinux.ru/"
		if (self.blognum):
			self.blogaddr += "blog/%d/" % self.blognum
	
	def get_user_city(self, username):
		username = unicode(username, 'utf-8')
		if (self.users_cities.has_key(username)):
			return self.users_cities[username]

		if (ENABLE_DEBUG):
			print 'loading %s...' % username.encode('utf-8')

		reg = r'<a href=\'list/user/city/[^\']+\'>\s*([^<]+)\s*'
		data = read_retrying('http://welinux.ru/user/%s/' % username)
		
		if (ENABLE_DEBUG):
			print '\033[1A%s\033[1A' % (' '*80)
		
		if data:
			result = re.search(reg, data )
		else:
			result = None
	
		if (result):
			city = result.group(1).strip()
			self.users_cities[username] = city
			return city
		else:
			self.users_cities[username] = None
		return None

	def start_parsing(self, pages = -1, from_page = 0):
		url = "%sfrom/%d/" % (self.blogaddr, from_page*10)
		while (len(url) and pages):
			pages -= 1
			url = self.parse_page(url)
		
	def parse_page(self, url = ""):
		if (ENABLE_DEBUG):
			print url
		if (url == ""):
			return ""

		data = read_retrying(url)

		parsed = self.parser.findall(data)
		for date,time,username in parsed:
			city = self.get_user_city(username)
			# default
			tz = DEFAULT_HOUR
			if (city):
				tz = self.tzones.get_gmt_plus(city)
				# we do not know! setting default
				if (not tz):
					tz = DEFAULT_HOUR
			else:
				city = "None"
			real_hour = (int(time.split(':')[0]) + (tz-3)) % 24
			if real_hour < 0:
				real_hour = 24 - real_hour
			self.hours[real_hour] += 1
			output = unicode("{0}\t{1}\t{2:15}\t{3:18}\tGMT+{4}\t{5}").format(date, time, unicode(username, 'utf8'), unicode(city, 'utf8'), tz, real_hour)

			print output.encode('utf8')
			sys.stdout.flush()

		if (self.blognum):
			next_page_ref = "blog/%d/" % self.blognum
		else:
			next_page_ref = ""
		next_page = re.search(ur"<a class='nomnm' id='next' href='%sfrom/([0-9]+)/'\s*>\s*&#8594;\s*</a>" % next_page_ref, data)
		if (next_page):
			return "%sfrom/%s/" % (self.blogaddr, next_page.group(1))
		return ""

	def print_statistics(self):
		summ = sum( self.hours.values() )
		if (not summ):
			print "\nBlog №%d is empty!" % self.blognum
			return
		print "\nBy-hour statictics for blog №%d: " % self.blognum
		for hr in range(24):
			percent = float(self.hours[hr])/summ
			output = "%2d: %3.2f%%\t [%s]" % (hr, percent*100, ("=" * int(floor(percent*MAX_WIDTH))) + (" " * int(ceil((1-percent)*MAX_WIDTH))))
			print output

if (__name__ == "__main__"):
	optlist = """ 
	-n cnt      count of pages
	-r cnt      reconnect count
	-v          verbose output
	-f num      from page #num
	-?, -h      help
"""
	try:
		options, args = getopt.getopt(sys.argv[1:], "n:r:f:v?")
	except getopt.GetoptError:
		print "Wrong options! Correct are: " + optlist
		exit()
	pages = -1
	from_page = 0
	for opt,val in options:
		if opt=='-n':
			pages = int(val)
		elif opt=='-r':
			RECONNECT_TIMES = int(val)
		elif opt=='-v':
			ENABLE_DEBUG = True
		elif opt=='-f':
			from_page = int(val)
		elif opt=='-?' or opt=='-h':
			print "Fromat:\n\t./welinuxParser.py [OPTIONS] [BLOG NUMBERS]\nOptions: " + optlist 
			exit()

	if (len(args) == 0):
		print("Parsing entire site...")
		args.append(0)
	
	for blognum in args:
		blognum = int(blognum)
		if (blognum):
			print("Parsing blog №%d" % blognum)
		p = Parser(blognum)
		try:
			p.start_parsing(pages, from_page)
			p.print_statistics()
		except KeyboardInterrupt:
			print "\nStopping... By the way, collected this: "
			p.print_statistics()
			exit();
		except IOError:
			print "\nSomething gone wrong... By the way, collected this: "
			p.print_statistics()
			exit();
		print('\n')
