#include <stdio.h>
#include <stdlib.h>

FILE* in=fopen("rail.in","r");
FILE* out=fopen("rail.out","w");

long N,M,K;
long*  sta;  //tarif
long** per;  //matriza dostigimosti
long** ele;  //marshrut

struct tst
{long val;
 struct tst* next;
} *st;

long push(long val)
{struct tst* pst=(struct tst*)malloc(sizeof(struct tst));
 pst->val=val;
 pst->next=st;
 st=pst;
 return val;
}

long pop()
{struct tst* pst;
 long val=st->val;
 pst=st->next;
 free(st);
 st=pst;
 return val;
}

/* long N,M,K;
   long*  sta;  //stantion tarif
   long** per;  //matriza dostigimosti
   long** ele;  //marshrut
*/

int input()
{long i,j;
 long x,y;
 long buf;
 fscanf(in,"%ld %ld",&N,&M);
 sta=(long*)calloc(N,sizeof(long));
 for (i=0;i<N;i++)
  sta[i]=0;
 for (i=0;i<M;i++)
  {fscanf(in,"%ld %ld",&x,&y);
//   per[--x][--y]=-1;
//   per[y][x]=-1;
  }
 fscanf(in,"%ld",&K);
 ele=(long**)calloc(K,sizeof(long*));
 for (i=0;i<K;i++)
  {j=0;
   do
    {j++;
     fscanf(in,"%ld",&buf);
     push(--buf);
    }
   while (buf>=0);
   ele[i]=(long*)calloc(j+1,sizeof(long));
   ele[i][0]=j;
   while (j) {ele[i][j]=(pop());
	      j--;}
  }
 return 0;
}

/* long N,M,K;
   long*  sta;  //tarif
   long** ele;  //marshrut
*/

#define UP    1
#define DOWN -1
#define NO    0
#define BAD  -10

int used(long marnum,long* start)
{long i;
 long p;
 long last=0;
 long ist=0;
 int  r=NO;
 *start=0;

 for (i=1;i<ele[marnum][0];i++)
  {if (sta[ele[marnum][i]])
    {if (!ist) ist=i;
     p=sta[ele[marnum][i]]-last;
     if (p)
      {if (p>0 && r==DOWN || p<0 && r==UP) return BAD;}
     else
      if (r) return BAD;
     if (last) r=(p==0?NO:(p>0?UP:DOWN));
     last=sta[ele[marnum][i]];
    }
  }
 *start=sta[ele[marnum][ist]]-r*ist;
 return r;
}

int main()
{long i,j,start;
 int u;
 input();
 for (i=0;i<K;i++)
  {u=used(i,&start);
   switch (u)
    {case NO  :start=0;u=1;
     case DOWN:
     case UP  :goto numerate;
     case BAD :goto end;
    }
numerate:
   for (j=1;j<=ele[i][0];j++)
    sta[ele[i][j]]=start+j*u;
  }
end:
 if (u==BAD) fprintf(out,"NO");
 else
  {fprintf(out,"YES\n");
   for (i=0;i<N;i++)
    fprintf(out,"%d ",sta[i]?sta[i]:2);
  }
 fclose(in);
 fclose(out);
 return 0;
}
