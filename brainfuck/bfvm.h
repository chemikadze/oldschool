#ifndef BFVM_H
#define BFVM_h

#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

typedef string (*ioread_t)();
typedef void   (*iowrite_t)(char);

const	int MEMSIZE=30000;
enum	err_t { E_NO=0, E_DS_OUT, E_IP_OUT, E_WRONG_CODE };

string	ioread_def();
void	iowrite_def(char _c);

class aInterpriter
{
    private:
	// program text/data
	string  program;
	map < int, int, less<int> >	brackets;
	
	// runtime info
	int	ip;
	int	ds;
	int	ipCounter;
	vector < char >	memory;
	
	// input/output
	int	ibufpos;
	string  ibuf;
	char    obuf;
	err_t	errorCode;
    public:
	string	(*ioread)();
	void	(*iowrite)(char);
	
	void 	setReadFunc(ioread_t _f);
	void	setWriteFunc(iowrite_t _f);
	
	err_t	loadProgram(const char* str);
  	const string* getProgram();
	void	clearProgram();
	void	clearMemory();
	void	clearAll();
	
	int	getIpCounter();
	int	getErrorCode();
	
	aInterpriter();

	err_t	run();	// running
	err_t	step();	// step by step
	err_t	cont();	// continue from ip
};


#endif
