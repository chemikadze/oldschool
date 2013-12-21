//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

FILE *in= fopen("train.in","r");
FILE *out=fopen("train.out","w");

int main(int argc, char* argv[])
{
  int i,j;
  fscanf(in,"%d %d",&i,&j);
  if (i!=j)
  {
    fprintf(out,"%d",i+j-1);
  }
  else
  {
    fprintf(out,"0");
  }
  fclose(in);
  fclose(out);
  return 0;
}
//---------------------------------------------------------------------------
