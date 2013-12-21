#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PINGER_H
#define PINGER_H

typedef enum {ENO=0, ERR} anError;

class aPinger
{
public:
	anError errcode;
	void setHost(char * _host);
	void ping();
	void stop();
	aPinger();
	aPinger(char * _host);
	~aPinger();
private:
	bool stopflag;
	char * host;
	FILE * pipe;
	char * buf;
	double ms;
};

#endif