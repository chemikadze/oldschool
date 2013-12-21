#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>	// working with sockets
#include <netinet/in.h>	// sockaddr_in
#include <netdb.h>	// host naming
#include <arpa/inet.h>

const char filename="~/dick.html";

void error(char* estr)
{
	fprintf(stderr, "Error: %s\n" ,estr);
	exit(EXIT_SUCCESS);
}

int main(int argc, char* argv[])
{
	int sock, iosock;
	struct sockaddr_in  sa;
	struct hostent     *hst;

	char* target;
	char port_s[10];
	int port;
	char buf[256];
	int   bufsize=256;
	int i;
	int servnumber=0;
	
	if (argc==1)
	{
		printf("Using: socket addres [port]\n");
		exit(EXIT_SUCCESS);
	}
	else
		target=argv[1];
	if (argc==3)
		strcpy(port_s, argv[2]);
	else
		strcpy(port_s, "666\0");
	if (sscanf(port_s, "%d", &port)!=1)
	{
		printf("Error: port must be a number!");
		exit(EXIT_SUCCESS);
	}

	// socket opening
	//
	sock=socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		error("Can\'t open a socket");
	
	sa.sin_family=AF_INET;
	sa.sin_port=htons(port);
	//sockaddr part
	if (!inet_aton(target, &sa.sin_addr))			// numeric
	{
		hst=gethostbyname2(target, AF_INET);		// !numeric
		if (hst==NULL)
		{
			printf("Error: unknown host %s\n", target);
			exit(EXIT_SUCCESS);
		}
		memcpy(&sa.sin_addr, hst->h_addr, 4);		
	}
	
		
	// bind part -- making open for connection
	//
	if ( 0 > bind(sock, (struct sockaddr*)(&sa), sizeof(sa)) )
		error("Bind");
	while ( listen(sock, 1000) >=0 )
	{
		servnumber++;
		iosock=accept(sock, NULL, NULL);
		if (fork())
			continue;
		
		printf("Listener: Connected.\n");
		while (true)
		{
			for (i=0; i<bufsize; i++)
				buf[i]=0;
			recv(iosock, buf, bufsize, 0);
			printf("Seans%3d: Hey, they said to me: %s", servnumber, buf);
			sprintf(buf, "RECIEVED\n\0");
			send(iosock, buf, 10, 0);
		}
	}
	error("Can\'t listen!");
}
