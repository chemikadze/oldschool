#include <stdio.h>
#include <string.h>

#ifdef _DEBUG
#include <conio.h>
#endif

const int N=101;

char src[N]; 
char res[N];
char br[9][N];
int brc=0;
int sl, fl, rl;

char f[N]; //find
char r[N]; //put

int main()
{
  int i, pi, j, k=0, rp=0;
  bool b;
  bool bract=false;
   
  gets(src);
  gets(f);
  gets(r);
  sl=strlen(src);
  fl=strlen(f);
  rl=strlen(r);
  for (i=0; i<sl; )
  {
    b=true;
    pi=i;
    for (j=0; j<fl && b; j++)
    {
      switch (f[j])
      {
        case '[' :
          if (f[j+1]!='!')
            for (j+=1; f[j]!=']' && j<fl; j++)
            {
              if (f[j+1]=='-')
                switch (f[j])
                {
                  case '0': b=src[i]>='0' && src[i]<='9'; j+=2; break;
                  case 'a': b=src[i]>='a' && src[i]<='z'; j+=2; break;
                  case 'A': b=src[i]>='A' && src[i]<='Z'; j+=2; break;
                }
              else
              {
                if (f[j]=='\\')
                  b=src[i]==f[j+1];
                else
                  b=src[i]==f[j];
              }
              if (b)
              {
                if (bract) 
                  br[brc][k++]=src[i];
                while (f[j++]!=']' && j<fl);
                break;
              }
            }
          else
            for (j+=2; f[j]!=']' && j<fl; j++)
            {
              if (f[j+1]=='-')
                switch (f[j])
                {
                  j+=2;
                  case '0': b=src[i]<'0' || src[i]>'9'; j+=2; break;
                  case 'a': b=src[i]<'a' || src[i]>'z'; j+=2; break;
                  case 'A': b=src[i]<'A' || src[i]>'Z'; j+=2; break;
                }
              else
              {
                if (f[j]=='\\')
                  b=src[i]!=f[j+1];
                else
                  b=src[i]!=f[j];
              }
              if (b)
              {
                if (bract)
                  br[brc][k++]=src[i];
                while (f[j++]!=']' && j<fl);
                break;
              }
            }
          i++;
          j--;
          break;
        case '(' :
          bract=true;
          k=0;
          b=true;
          break;
        case ')':
          bract=false;
          b=true;
          br[brc++][k]=0;
          break;
        case '?':
          b=true;
          if (bract)
            br[brc][k++]=src[i++];
          break;
        case '\\':
          j++;    
        default:
          b=src[i++]==f[j];
          if (b && bract)
            br[brc][k++]=src[i-1];
      }
      if (!b)
      {
        brc=0;
        bract=false;
      }
    }
    if (b)
    {
      for (j=0; j<rl; j++)
      {
        if (r[j]=='\\')
        {
          for (k=0; k<strlen(br[r[j+1]-'1']); k++)
            res[rp++]=br[r[j+1]-'1'][k];
          j++;
        }
        else
          res[rp++]=r[j];
      }
      brc=0;
    }
    else
    {
      i=pi;
      res[rp++]=src[i++];
    }
  }
  printf("%s", res);
  #ifdef _DEBUG
  getch();
  #endif
  return 0;
}
