#include <stdio.h>
#include <stdlob.h>

FILE* in=fopen("internrt.in","r");
FILE* in=fopen("internet.out","w");

typedef struct tway
{long double x,y;
 char c;
 long double l;
};

int N;
long double K;
tway* way;
char* matrix;

int main()
{long i;
 fscanf(in,"%d %Lf",&N,&K);
 way=(tway*)calloc(way,sizeof(tway));
 for (i=0;i<N;i++)
  fscanf(in,"%Lf %Lf %c %Lf");
 return 0;
}