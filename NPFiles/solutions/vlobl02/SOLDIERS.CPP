#include <stdio.h>
#include <conio.h>

void swap(char* &a, char* &b)
{
  char *t=a;
  a=b;
  b=t;
}

int N;
char *a;
unsigned long ans=0;

int main()
{
  int i, k;
  char* b;

  scanf("%d", &N);
  a=new char[N+1];
  b=new char[N+1];b[N]='\0';
  scanf("%s", a);

  while (1)
  {
    k=0;
    for (i=0; i<N; i++)
    {
      if (a[i]!=a[i+1] && a[i+1]=='<')
      {
	b[i++]='<';
	b[i]='>';
	k++;
      }
      else
	b[i]=a[i];
    }
    swap(a, b);
    //printf("%s\n", a);
    ans+=k;
    if (!k) break;
  }
  printf("%ld\n", ans);
  getch();
  delete[] a;
  delete[] b;
  return 0;
}