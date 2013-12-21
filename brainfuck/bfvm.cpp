#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
#include "bfvm.h"
using namespace std;

aInterpriter::aInterpriter()
{
	ipCounter=ibufpos=ip=ds=0;
	memory.resize(MEMSIZE);
 	ioread=ioread_def;
	iowrite=iowrite_def;
}


void aInterpriter::setReadFunc(ioread_t _f)
{	ioread=_f;	}

void aInterpriter::setWriteFunc(iowrite_t _f)
{	iowrite=_f;	}

err_t aInterpriter::loadProgram(const char* str)
{
	int len=strlen(str);
	int i;
	vector <int> stack;
	
	for (i=0; i<len; i++)
	{
		if (str[i]=='[')
			stack.push_back(i);
		else	if (str[i]==']')
			{
				if (!stack.size())
					return errorCode=E_WRONG_CODE;			
				brackets[i]=stack.back();
				brackets[stack.back()]=i;
				#ifdef DEBUG_BFVM
				printf("brackets[%2d] is %2d | brackets[%2d] is %2d\n", i, brackets[i], brackets[i], brackets[brackets[i]]);
				#endif
				stack.pop_back();
			}
	}
	if (stack.size())
		return errorCode=E_WRONG_CODE;

	for (i=0; i<len; i++)
		if (str[i]=='.' || str[i]==',' || str[i]=='[' || str[i]==']' || 
		    str[i]=='+' || str[i]=='-' || str[i]=='>' || str[i]=='<')
			program+=str[i];
	return E_NO;
}

const string* aInterpriter::getProgram() 
{	return &program;	}

err_t aInterpriter::run()
{
	ipCounter=0;
	ip=0;
	return cont();
}

err_t aInterpriter::cont()
{
	while (ip<program.length())
		if (step())	
			return errorCode;
}

err_t aInterpriter::step()
{
	if (errorCode==E_WRONG_CODE)
		return errorCode;
	if (ip<0 || ip>memory.size())
		return E_IP_OUT;
	#ifdef DEBUG_BFVM
	printf("Now ip=%3d ds=%3d memory[ds]=%3d: %c\n", ip, ds, memory[ds], program[ip]);
	#endif
	switch (program[ip])
	{
		case '>':
			ds++;	if (ds<0 || ds>=memory.size()) return errorCode=E_DS_OUT; break;
		case '<':
			ds--;	if (ds<0 || ds>=memory.size()) return errorCode=E_DS_OUT; break;
		case '+':
			memory[ds]++; break;
		case '-':
			memory[ds]--; break;
		case ',':
			if (ibufpos >= ibuf.length()) 
			{
				ibuf=ioread();
				ibufpos=0;
			} 
			memory[ds]=ibuf[ibufpos++];
			break;
		case '.':
			iowrite(memory[ds]);
			#ifdef DEBUG_BFVM
			printf("#%d", memory[ds]);
			#endif
			 break;
		case '[':
			if (!memory[ds])
				ip=brackets[ip];
			break;
		case ']':
			if (memory[ds])
				ip=brackets[ip];
			break;
	}
	ip++;
	ipCounter++;
	return errorCode=E_NO;
}

void aInterpriter::clearProgram()
{
	program="";
	ip=0;
	brackets.clear();	
}

void aInterpriter::clearMemory()
{
	ds=0;
	memory.assign(memory.size(), 0);
}

void aInterpriter::clearAll()
{
	clearProgram();
	clearMemory();
}

int aInterpriter::getIpCounter()
{
	return ipCounter;
}

int aInterpriter::getErrorCode()
{
	return errorCode;
}

string ioread_def()
{
	string s;
	cout << "<< ";
	cin >> s;
	return s;
}

void iowrite_def(char _c)
{
	cout << _c;
}

