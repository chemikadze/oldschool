#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::max;

//#define DEBUG
//#define _DEBUG


const char* times_str="time";
const int bar_len=80;

extern void error(const char * err, int exit_status=1);
extern double getms(const char * buf);

int main(int argc, char* argv[])
{
	FILE * pipe;
	char * buf, * runstring, * b, ** tail=NULL;
	double ms;
	int i;
	int max_ms=500;
	
	runstring=new char[80];
	b=new char[80];
	strcat(runstring, "ping ");

	if (argc==1)
		error("Not enough parameters!\n");
	for (i=1; i<argc; i++)
	{
		if (*((short*)argv[i])==0x5A2D)
		{
			i++;
			#ifdef _DEBUG
			printf("*");
			#endif
			if (argc < i)
				error("Parameter requied for -Z option.");
			try
			{
				max_ms=strtol(argv[i], tail, 10);
			}
			catch (...)
			{
				error("Error parsing timeout to integer.");
			}
			#ifdef _DEBUG
			printf("*\n");
			#endif
			//todo error if *tail==argv[i]
			//todo write	`void error(char* ERR)`
		}
		else
		{
			#ifdef _DEBUG
			printf("*");
			#endif
			sprintf(b, "%s ", argv[i]);
			strcat(runstring, b);
			#ifdef _DEBUG
			printf("*\n");
			#endif
		}
	}
	#ifdef DEBUG
	printf("rs=\"%s\"\n", runstring);
	#endif
	//sprintf(runstring, "ping %s", runstring);
	pipe=popen(runstring, "r");
	if (!pipe)
		error("Error creating a pipe...\n");

	buf=new char[80];
	while (true)
	{			
		fgets(buf, 80, pipe);
		ms=getms(buf);
		i=0;
		if (ms>0.0)
		{	
			putchar('[');
			for (; i<( int(ms/max_ms*bar_len)<bar_len ? int(ms/max_ms*bar_len) : bar_len); i++)
				putchar('#');
			for (; i<bar_len; i++)
				putchar(' ');
			printf("] %.3f ms\n", ms);
		}
		else
		{
			printf(buf);
			if (strstr(buf, "min/avg/max/mdev")!=NULL)
				break;
		}
	}

	pclose(pipe);
	return 0;
}

double getms(const char * buf)
{
	int len=strlen(buf);
	long times_int=*((long*)(times_str));
	char * ms_str=new char[10];
	char ms_pos=0;
	int i;

	for (i=0; i<len-3; i++)
		if (*((long*)(buf+i))==times_int)
		{
			i+=5;
			break;
		}
	if (buf[i-1]!='=')
		return 0;
	for (; buf[i]!=' ' && i<len; i++)
		ms_str[ms_pos++]=buf[i];
	ms_str[ms_pos]=0;
	if (ms_pos==1)
		return -1;
	return strtod(ms_str, NULL);
}

void error(const char *  err, int exit_status)
{
	printf(err);
	exit(exit_status);
}
