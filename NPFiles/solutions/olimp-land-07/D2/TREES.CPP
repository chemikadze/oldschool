#include <stdio.h>
#include <stdlib.h>

FILE* in=fopen("trees.in","r");
FILE* out=fopen("trees.out","w");

long K;
long P;
long R;
long* a;
long* p;

long inc(long* i,long max)
{(*i)++;
 if ((*i)==max) (*i)=0;
 return (*i);
}

int sort(const void *a, const void* b)
{return *((long*)b)-*((long*)a);
}

int main()
{long i=0,j=0;
 long stop;
 long li,la;
 long r=0;

 fscanf(in,"%ld %ld",&K,&P);
 a=(long*)calloc(K,sizeof(long));
 p=(long*)calloc(P,sizeof(long));
 for (i=0;i<K;i++)
  fscanf(in,"%ld",&a[i]);
 qsort((void*)a,K,sizeof(long),sort);
 for (i=0;i<K;i++)
  r+=a[i];
 if (r==P) goto end;
 r=0;
 i=-1;
 do
  {r++;
   li=i;
   while (!a[inc(&i,K)] && li!=i);
   a[i]--;
   p[j]=i;
   inc(&j,P);
  }
 while (a[i]>=0 && (r<=P || p[j==0?P-1:j-1]!=p[j]));
 if (p[j==0?P-1:j-1]==p[j])
  r--;
end:
 fprintf(out,"%d",r);
 fclose(in);
 fclose(out);
 return 0;
}