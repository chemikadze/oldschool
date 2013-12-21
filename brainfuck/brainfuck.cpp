#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "bfvm.h"
using namespace std;

int main(int argc, char* argv[])
{
	aInterpriter bf;
	string s;
	int errcode;
	
	if (argc>1)
		freopen(argv[1], "r", stdin);	
	else
		cout << "Enter your program.\n>> ";
	cin >> s;
	if (bf.loadProgram(s.c_str())==E_NO);
		bf.run();
	switch (bf.getErrorCode())
	{
		case E_NO: 	printf("\nNormal exiting. Inerprited %d command(s).", bf.getIpCounter()); break;
		case E_DS_OUT:	printf("\nError! Out of bounds."); break;
		case E_IP_OUT:	printf("\nError! IP register out of program!"); break;
		case E_WRONG_CODE:
				printf("\nError! Wrong program code!");
	}
	cout << endl;
	return 0;
}
