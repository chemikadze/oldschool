//---------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma hdrstop
#include "NPS.h"
//---------------------------------------------------------------------------
#pragma argsused

int main(int argc, char* argv[])
{char s[80];
 long int i;
 gets(s);
 TSolver solver(s);
 solver.strtopol();
 if (solver.geterr()!=E_NO) goto ERROR;
// for (i=0;i<10000000;i++)
//   {solver.sets(s);
    solver.solvepol();
//   }
 if (solver.geterr()==E_NO)
   {printf("\n%Lg",solver.result());
   }
 else
   {ERROR:
    printf("\nError [%02d]: %s",(int)solver.geterr(),solver.getstrerr());
   }
 getc(stdin);

 return 0;
}
//---------------------------------------------------------------------------
