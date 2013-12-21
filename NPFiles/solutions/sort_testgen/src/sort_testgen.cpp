

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>

const int N=5000;

FILE* out=fopen("sort.in","w");

int main(int argc, char *argv[])
{
  int i;
  fprintf(out,"%d\n",N);
  for (i=5000;i>0;i--)
    fprintf(out,"%d ",i);
  fprintf(out,"\n0");
  fclose(out);
  
  return EXIT_SUCCESS;
}
