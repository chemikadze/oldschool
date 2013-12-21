#include <stdio.h>
#include <stdlib.h>

FILE* in=fopen("sport.in","r");
FILE* out=fopen("sport.out","w");

long *a;
char* s;
long N,p,k;

int main()
{long i,j;
 long buf;
 fscanf(in,"%ld %ld %ld",&N,&p,&k);
 p--;
 a=(long*)calloc(N,sizeof(long));
 s=(char*)calloc(N-1,sizeof(char));
 for (i=0;i<N;i++) fscanf(in,"%ld",&a[i]);

 for (j=0;j<N-1;j++)
  {if (k==0) {s[j]='-';goto SORT;}
   if (p>0) if (a[p]<a[p-1]) {s[j]='-';goto SORT;}
   if (p<N-1) if (a[p]>a[p+1]) {s[j]='+';k--;goto SORT;}
   s[j]='-';
SORT:
   for (i=0;i<N-1;i++)
    {if ((s[j]=='-' || k==0) || (i!=p && i!=p+1))
      {if (a[i]>a[i+1])
	{p=(i==p?i+1:(p==(i+1)?p=i:p));
	 buf=a[i];a[i]=a[i+1];a[i+1]=buf;}}
     else
      i=p+1;
    }
  }
 s[j]='\0';
 fprintf(out,"%ld\n",p+1);
 fputs(s,out);

 fclose(in);
 fclose(out);
 return 0;
}