#include "pinger.h"
#include "pinger_mv.h"
#include "main.h"

aPinger::aPinger()
{
	host=NULL;
	stopflag=false;
}

aPinger::aPinger(char * _host)
{
	setHost(_host);
	stopflag=false;
}

aPinger::~aPinger()
{
	delete[] host;
	if (pipe!=NULL)
		pclose(pipe);
}

void aPinger::setHost(char * _host)
{
	host=strdup(_host);
}

void aPinger::stop()
{
	stopflag=true;
}

void aPinger::ping()
{
	char * command=new char[ strlen(host)+6 ];
	sprintf(command , "ping %s", host);
	pipe=popen(command, "r");
	if (pipe==NULL)
	{
		errcode=ERR;
		return;
	}
	stopflag=false;
	if (pipe==NULL)
		errcode=ERR;
	while (!stopflag)
	{
		theMainWindow->PingSaid(10);
		//TODO WRITE IT!!!!
	}
	if (pipe!=NULL)
		pclose(pipe);
}