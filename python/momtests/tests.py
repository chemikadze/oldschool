#!/usr/bin/python
try:
	while True:
		question = raw_input().replace('%', '\%').split('~')
		correct = int(question[2])
		ans = question[4:]
		i = 0
		print r"\textbf{%s}" % (question[3])
		print r"\begin{enumerate}"
		for s in ans:
			if i == correct:
				print r"\item \textit{%s}" % (s)
			else:
				print r"\item %s" % (s)
			i+=1
		print r"\end{enumerate}"

		print '\n\n' 
except:
	exit()
