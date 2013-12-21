#include <stdio.h>
#include <stdlib.h>

FILE* in=fopen("digit.in","r");
FILE* out=fopen("digit.out","w");

int K,//znaki
    S,//summa
    P,//summa A*D
    D;//no comments

long sumdig(int* n1)
{long r=0;
 for (int i=0;i<=K;i++)
  r+=n1[i];
 return r;
}

int* mult(int* n1,int n2)
{int* r=(int*)malloc(K+1);
 int buf;
 r[0]=0;
 for (long i=0;i<K;)
  {buf=n1[i]*n2;
   r[i]+=buf%10;
   r[++i]=buf/10;
  }
 return r;
}

int buildnum(int* bnum,long sum,long pos)
{if (pos==-1)
  {if (/*S==sum(bnum) && */P==sumdig(mult(bnum,D))) return 1;
   else return 0;}
 int i;
 int min=(int)(sum-pos*9>0?sum-pos*9:0);
 int max=sum>9?9:sum;
 for (i=min;i<=max;i++)
  {bnum[pos]=i;
   if (buildnum(bnum,sum-i,pos-1)) return 1;
  }
// bnum[pos]=0;
 return 0;
}

int main()
{int* a;
 long i=0;
 long max;
 int r;
 fscanf(in,"%d %d %d %d",&K,&S,&P,&D);
 a=(int*)calloc(K+1,sizeof(int));
 i=(S-(K-1)*9>0?S-(K-1)*9:1);
 max=S>9?9:S;
 do
  {a[K-1]=i;
  }
 while ((!(r=buildnum(a,S-i,K-2))) && (i++!=max));
 if (r)
  {for (i=K-1;i>=0;i--)
    fprintf(out,"%d",a[i]);
  }
 else fprintf(out,"-1");
 fclose(in);
 fclose(out);
 free(a);
 return 0;
}