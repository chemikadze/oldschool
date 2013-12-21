//---------------------------------------------------------------------------
#pragma hdrstop
#include "NPS.h"
//#define debug
//---------------------------------------------------------------------------
#pragma package(smart_init)
//***************************************************************************
//*******************CHANGEBLE***********************************************

enum TLex {cpi='à',cx,
	   //insert new CONSTANT here
	   fexp,fln,flog,flogn,
	   fpow,f_op_pow,froot,f_op_root,fsqr,fsqrt,f_abs,
	   //insert new FUNCTION here
	   fsin,fcos,ftan,fctan};

char* SLex[]=
	  {"pi","x",
	   //insert new CONSTANT here, don't forget ","
	   "exp","ln","log","logn",
	   "pow","**","root","//","sqr","sqrt","abs",
	   //insert new FUNCTION here, don't forget ","
	   "sin","cos","tg","ctg",
	   "arcsin","arccos","arctg","arcctg",
	   "sinh","cosh","tgh","ctgh",
	  #ifndef _OLD_
	   "arcsinh","arccosh","arctgh","arcctgh"
	  #endif
	   };

#ifndef strlwr
char* strlwr(char* s)
{
  int i;
  for (i=0; i<strlen(s); i++)
    if (s[i]>='A' && s[i]<='Z')
      s[i]-='a'-'A';
}
#endif

int argcnt(const char c)                //count of arguments
{if (isconst(c)) return 0;
 if (isfn(c) && c!=fpow && c!=f_op_pow && c!=f_op_root && c!=froot && c!=flogn || c=='!' || c=='_') return 1;
 return 2;
}

long double torad(long double x)
{while (x>=M_PI) x-=M_PI;
 while (x<=M_PI) x+=M_PI;
 return x;
}

int prior(const char f)           //gives priority of function
{if (isfn(f))  return 0;
 switch (f)
   {case '(':
    case '[': return 0;
    case ']':
    case ')': return 1;
    case f_op_root:
    case f_op_pow:
    case '^':    return 2;
    case '*':
    case '/':  return 3;
    case '+':
    case '-':  return 4;
    case '_':  return 5;
    case ',':  return 6;
    default:   return -1;
   }
}

long double TSolver::calc(const char f,const long double a,const long double b) //calculates function
{switch (f)
   {case '+' : return a+b;
    case '-' : return a-b;
    case '*' : return a*b;
    case '/' : if (b==0) {Err=E_DEV_ZERO;return 0;};return a/b;
    case '!' : if (floorl(a)!=a) {Err=E_ARG;return 0;}return factor(a);
    case '_' : return -a;

    case cpi   : return M_PI;
    case cx    : return X;

    case fexp  : return exp(a);
    case fln   : if (a<0) {Err=E_ARG;return 0;}return logl(a);
    case flog  : if (a<0) {Err=E_ARG;return 0;}return log10l(a);
    case flogn : if (a<0) {Err=E_ARG;return 0;}return log(a)/log(b);

    case '^':
    case f_op_pow:
    case fpow  : if (a<0 && b<1 && b>0 && (!fmodl(b,2))) {Err=E_ARG;return 0;}return powl(a,b);
    case fsqr  : return a*a;
    case f_op_root:
    case froot : if (a<0 && (!fmodl(b,2))){Err=E_ARG;return 0;}
                   return (a>0 || (!fmodl(b,2)))?powl(a,1/b):-powl(-a,1/b);
    case fsqrt : if (a<0) {Err=E_ARG;return 0;}return sqrtl(a);
    case f_abs  : return fabsl(a);

    case fsin  : return sinl(a);
    case fcos  : return cosl(a);
    case ftan  : if (a==M_PI_2 || a==(M_PI_2+M_PI)) {Err=E_ARG;return 0;} return tanl(a);
    case fctan : if (a==0 || a==M_PI) {Err=E_ARG;return 0;} return 1/tanl(a);

    case fsin+ARC : if (fabsl(a)>1) {Err=E_ARG;return 0;} return asinl(a);
    case fcos+ARC : if (fabsl(a)>1) {Err=E_ARG;return 0;} return acosl(a);
    case ftan+ARC : return atanl(a);
    case fctan+ARC: return atanl(1/a);

    case fsin+HYP : return sinhl(a);
    case fcos+HYP : return coshl(a);
    case ftan+HYP : return tanhl(a);
    case fctan+HYP : return 1/tanhl(a);
#ifndef _OLD_
    case fsin+HYP+ARC : return asinhl(a);
    case fcos+HYP+ARC : return acoshl(a);
    case ftan+HYP+ARC : if (fabsl(a)>=1) {Err=E_ARG;return 0;} return atanhl(a);
    case fctan+HYP+ARC : if (a==0 ) {Err=E_ARG;return 0;} return atanhl(1/a);
#endif
    default: return 0;
   }
}

long double TSolver::gcalc(const char f,const long double a,const long double b,const long double step) //calculates function
{
 #define ain(x) (a-step<=x && a+step>=x)
 #define bin(x) (b-step<=x && b+step>=x)
 #define angin(x) (torad(a)-step<x && torad(a)+step>x)
 switch (f)
   {case '+' : return a+b;
    case '-' : return a-b;
    case '*' : return a*b;
    case '/' : if (bin(0)) {Err=E_DEV_ZERO;return 0;};return a/b;
    case '!' : if (floorl(a)!=a) {Err=E_ARG;return 0;}return factor(a);
    case '_' : return -a;

    case cpi   : return M_PI;
    case cx    : return X;

    case fexp  : return exp(a);
    case fln   : if (a<0) {Err=E_ARG;return 0;}return logl(a);
    case flog  : if (a<0) {Err=E_ARG;return 0;}return log10l(a);
    case flogn : if (a<0) {Err=E_ARG;return 0;}return log(a)/log(b);

    case '^':
    case f_op_pow:
    case fpow  : if (a<0 && b<1 && b>0 && (!fmodl(b,2))) {Err=E_ARG;return 0;}return powl(a,b);
    case fsqr  : return a*a;
    case f_op_root:
    case froot : if (a<0 && (!fmodl(b,2))){Err=E_ARG;return 0;}
		   return (a>0 || (!fmodl(b,2)))?powl(a,1/b):-powl(-a,1/b);
    case fsqrt : if (a<0) {Err=E_ARG;return 0;}return sqrtl(a);
    case f_abs  : return fabsl(a);

    case fsin  : return sinl(a);
    case fcos  : return cosl(a);
    case ftan  : if (angin(M_PI_2) || angin(M_PI_2+M_PI)) {Err=E_ARG;return 0;} return tanl(a);
    case fctan : if (angin(0) || angin(M_PI)) {Err=E_ARG;return 0;} return 1/tanl(a);

    case fsin+ARC : if (fabsl(a)>1) {Err=E_ARG;return 0;} return asinl(a);
    case fcos+ARC : if (fabsl(a)>1) {Err=E_ARG;return 0;} return acosl(a);
    case ftan+ARC : return atanl(a);
    case fctan+ARC: return atanl(1/a);

    case fsin+HYP : return sinhl(a);
    case fcos+HYP : return coshl(a);
    case ftan+HYP : return tanhl(a);
    case fctan+HYP : return 1/tanhl(a);
#ifndef _OLD_
    case fsin+HYP+ARC : return asinhl(a);
    case fcos+HYP+ARC : return acoshl(a);
    case ftan+HYP+ARC : if (fabsl(a)>=1) {Err=E_ARG;return 0;} return atanhl(a);
    case fctan+HYP+ARC : if (angin(0)) {Err=E_ARG;return 0;} return atanhl(1/a);
#endif
    default: return 0;
   }
}

char* TSolver::getruserr()const
{switch (Err)
   {case E_NO       : return R_E_NO;
    case E_DEV_ZERO : return R_E_DEV_ZERO;
    case E_FN       : return R_E_FN;
    case E_ARG      : return R_E_ARG;
    case E_HUGE     : return R_E_HUGE;
    case E_VOID     : return R_E_VOID;
    case E_EXPR     : return R_E_EXPR;
    case E_BR       : return R_E_BR;
    default         : return R_E_UNK;
   }
}

char* TSolver::getstrerr()const
{switch (Err)
   {case E_NO       : return S_E_NO;
    case E_DEV_ZERO : return S_E_DEV_ZERO;
    case E_FN       : return S_E_FN;
    case E_ARG      : return S_E_ARG;
    case E_HUGE     : return S_E_HUGE;
    case E_VOID     : return S_E_VOID;
    case E_EXPR     : return S_E_EXPR;
    case E_BR       : return S_E_BR;
    default         : return S_E_UNK;
   }
}
//*******************END*****************************************************
//***************************************************************************

//copys string
char* strdbl(const char* s)
{char* r=(char*)malloc(strlen(s)+1);
 strcpy(r,s);
 return r;
}
#ifdef _OLD_
//=====stack for function names
void TSolver::cpush(const char c)
 {TCSt* pst=(TCSt*)malloc(sizeof(TCSt));
  pst->val=c;
  pst->next=cst;
  cst=pst;
  cdeep++;
  return;
 }

char TSolver::cpop()
 {char c;
  if (cst==NULL || cdeep==0)
    {seterr(E_EXPR);
     return '\0';
    }
  TCSt* pst;
  c=cst->val;
  pst=cst->next;
  free(cst);
  cst=pst;
  cdeep--;
  return c;
 }
//==============end of stack

//=====stack for numbers
void TSolver::npush(const long double n)
 {TNSt* pst=(TNSt*)malloc(sizeof(TNSt));
  pst->val=n;
  pst->next=nst;
  nst=pst;
  ndeep++;
  return;
 }

long double TSolver::npop()
 {TNSt* pst;
  long double n;
  n=nst->val;
  pst=nst->next;
  free(nst);
  nst=pst;
  ndeep--;
  return n;
 }
//==============end of stack
/**/
#else
void TSolver::cpush(const char c)
 {cst.push_back(c);
 }

char TSolver::cpop()
 {char c=cst.back();
  cst.pop_back();
  return c;
 }
//==============end of stack

//=====stack for numbers
void TSolver::npush(const long double n)
 {nst.push_back(n);
  return;
 }

long double TSolver::npop()
 {if (nst_free)
    {seterr(E_EXPR);
     return 0;
    }
  long double n=nst.back();
  nst.pop_back();
  return n;
 }
#endif
inline void TSolver::setx(const long double x)
{X=x;
}

inline long double TSolver::getx()const
{return X;
}

char* TSolver::convtopol()   //converts symbol-function string to polish record
{if (S==NULL || !strlen(S)) seterr(E_VOID);
 char* r;
 if (Err!=E_NO)
   {ERROR:
    if (r!=NULL) free(r);
    free(S);
    return S=NULL;
   }
 int i,j=0;
 int p;
 int SL=strlen(S);
 r=(char*)calloc(SL*2+2,sizeof(char));
 r[0]='\0';
 cst_clear;
 for (i=0;S[i]!='\0';i++)
   {if (isnumc(S[i]) || isconst(S[i]) || (S[i]=='-' && (minusE || minusN)))
      {r[j++]=S[i];
       continue;
      }
    if (S[i]=='!')
      {addspc();
       r[j++]=S[i];
       addspc();
       continue;
      }
    p=prior(S[i]);
      {if (S[i]==')')
	 {addspc();
	  while ((!cst_free) && cst_end!='(')
	    {r[j++]=cpop();
	     r[j++]=' ';
	    }
	  cpop();
	  if ((!cst_free) && isfn(cst_end))
	    {r[j++]=cpop();
	     r[j++]=' ';
	    }
	  continue;
	 }

       if (S[i]==']')
	 {addspc();
	  while ((!cst_free) && cst_end!='[')
	    {r[j++]=cpop();
	     r[j++]=' ';
	    }
	  cpop();
	  r[j++]=f_abs;
          r[j++]=' ';
	  continue;
	 }
       if ((((!cst_free) && (p>=prior(cst_end)) && (prior(cst_end)>0)&&cst_end!='_'&&S[i]!='_') || S[i]==','))
	   {addspc();
	    while ((!cst_free) && p>=prior(cst_end) && prior(cst_end)>0)
	      {r[j++]=cpop();
	       r[j++]=' ';
	      }
	    if (S[i]==',') continue;
	   }
       cpush(S[i]);
       if (j>0) addspc();
      }
   }
 if (Err!=E_NO) goto ERROR;
 if (r[j-1]!=' ') r[j++]=' ';
 while (!cst_free)
  {r[j++]=cpop();
   r[j++]=' ';
  }
 if (r[j-1]!=' ') r[j++]=' ';
 r[j]='\0';
 free(S);
 S=strdbl(r);
 free(r);
#ifdef debug
 printf("%s\n",S);
#endif
 poled=1;
 return S;
}

char* TSolver::convert()  //converts function names to symbols
{if ((S==NULL || !strlen(S)) || !checkin() || !checkbr())
  {seterr(E_VOID);if(S!=NULL)free(S);return NULL;}
 char* p;
 int i,j;
 int sl;
 int SL=strlen(S);
 Err=E_NO;
 for (i=0;i<=SL;i++)
   if (S[i]==' ')
    {for (j=i;j<=SL+1;j++)
       S[j]=S[j+1];
     SL--;
    }
 for (i=NFUNC-1;i>=0;i--)
   while ((p=strstr(S,SLex[i]))!=NULL)
     {S[p-S]=cpi+i;
      sl=strlen(SLex[i])-1;
      SL-=sl;
      for (j=p-S+1;j<=SL;j++)
	S[j]=S[j+sl];
     }
 for (i=0;i<SL;i++)
   if (S[i]=='-' && (minusF))
     S[i]='_';
#ifdef debug
 printf("%s\n",S);
#endif
 if (!checkout() || !checkexpr()) {converted=good=0;return NULL;}
 converted=good=1;
 return S;
}

char* TSolver::strtopol()            //converts string to polish record
{if (S==NULL || !strlen(S))
   {seterr(E_VOID);
    free(S);
    return S=NULL;}
 char* p;
 if (poled || good) return S;
 Err=E_NO;
 strlwr(S);
 if (!converted)
   {convert();
    if (Err!=E_NO || S==NULL) {seterr(E_FN);return NULL;}
   }
 convtopol();
 if (Err!=E_NO || S==NULL) {seterr(E_FN);return NULL;}
 return S;
}

long double factor(long double f) //factorial 2 :-)
{long double r=1;
 if (f<0) return 0;
 while (f>0) r*=(f--);
 return r;
}

long double TSolver::solvepol()         //solves polish record
{if (S==NULL || !strlen(S)) seterr(E_VOID);
 if (!converted || !poled) seterr(E_EXPR);
 if (Err!=E_NO)
   {free(S);
    return 0;
   }
 char n[20]="";
 int sl=strlen(S);
 int i,j=0;
 long double r;

 cst_clear;
 if (!good)
   {for (i=0;i<sl;i++)
      if (!isgood(S[i]))
        {Err=E_FN;
         return 0;
        }
    good=1;
   }
 for (i=0;i<sl;i++)
   {if (S[i]!=' ')
      {if (isnumc(S[i]) || (S[i]=='-' && S[i+1]!=' ')) {n[j++]=S[i];continue;}
       else
         {switch (argcnt(S[i]))
            {case 0: npush(calc(S[i],0,0));continue;
             case 1: nst_end=calc(S[i],nst_end,0);continue;
             case 2: r=calc(S[i],nst_end,npop());
                     nst_end=r;
                     continue;
	     }
	  if (Err!=E_NO) return 0;
	 }
      }
    else
      if (strcmp(n,""))
	{n[j]='\0';
	 npush(_atold(n));
	 strcpy(n,"");
	 j=0;
	}
   }
 return R=npop();
}

long double TSolver::solvepolstp(const long double step)         //solves polish record
{if (S==NULL || !strlen(S)) seterr(E_VOID);
 if (!converted || !poled) seterr(E_EXPR);
 if (Err!=E_NO)
   {free(S);
    return 0;
   }
 char n[20]="";
 int sl=strlen(S);
 int i,j=0;
 long double r;

 nst_clear;
 if (!good)
   {for (i=0;i<sl;i++)
      if (!isgood(S[i]))
	{Err=E_FN;
	 return 0;
	}
    good=1;
   }
 for (i=0;i<sl;i++)
   {if (S[i]!=' ')
      {if (isnumc(S[i]) || (S[i]=='-' && S[i+1]!=' ')) {n[j++]=S[i];continue;}
       else
	 {switch (argcnt(S[i]))
	    {case 0: npush(gcalc(S[i],0,0,step));continue;
	     case 1: nst_end=gcalc(S[i],nst_end,0,step);continue;
	     case 2: r=gcalc(S[i],nst_end,npop(),step);
		     nst_end=r;
		     continue;
	     }
	  if (Err!=E_NO) return 0;
	 }
      }
    else
      if (strcmp(n,""))
	{n[j]='\0';
	 npush(_atold(n));
	 strcpy(n,"");
	 j=0;
	}
   }
 return R=npop();
}

long double TSolver::solve()             //solve string
{Err=E_NO;
 strtopol();
 return solvepol();
}

long double TSolver::solvex(const long double x,const long double step)             //solve string
{Err=E_NO;
 X=x;
 strtopol();
 return solvepolstp(step);
}

long double TSolver::solvepolx(const long double x,const long double step)             //solve string
{Err=E_NO;
 X=x;
 return solvepolstp(step);
}

TError TSolver::geterr()const
{return Err;
}

int TSolver::checkin()
{int i;
 int SL=strlen(S);
 for (i=0;i<SL;i++)
   if (!isgoodin(S[i]))
     {seterr(E_EXPR);
      return 0;
     }
 return 1;
}

int TSolver::checkout()
{int i;
 int SL=strlen(S);
 for (i=0;i<SL;i++)
   if (!isgood(S[i]))
     {seterr(E_FN);
      return 0;
     }
 return 1;
}

int TSolver::checkbr()
{int i;
 int SL=strlen(S);
 char* st=(char*)malloc(SL/2);
 int pos=-1;
 for (i=0;i<SL;i++)
   {if (S[i]=='(' || S[i]=='[')
      st[++pos]=S[i];
    else
      if (S[i]==')' || S[i]==']')
        {if (!(pos>=0 && ( (S[i]==')' && st[pos]=='(') || (S[i]==']' && st[pos]=='[') )))
           {seterr(E_BR);
            return 0;
           }
         else
           pos--;
        }
   }
 if (pos>=0)
   {seterr(E_BR);
    return 0;
   }
 return 1;
}

int TSolver::checkexpr()
{int i,j;
 int SL=strlen(S);
 if (SL==1)
   if (!(isconst(S[0])||isnumc(S[0])) )
     {seterr(E_EXPR);
      return 0;
     }
   else return 1;
 if (!(isnumc(S[SL-1])||S[SL-1]==')'||S[SL-1]==']'||isconst(S[SL-1])))
   {seterr(E_EXPR);
    return 0;
   }
#define ib(x) (i>0?(x):1)
 for (i=0;i<SL-1;i++)
   {if (isfn(S[i])||isconst(S[i])||issymbevul(S[i])||S[i]=='('||S[i]=='[')
    if(!( ( isfn(S[i]) && (S[i+1]=='(') )||
          ( i>0?S[i]=='(' && isfn(S[i-1]):1 )||
          ( isconst(S[i]) && (issymbevul(S[i+1])||S[i+1]==')'||S[i+1]==']') )||
          ( ((issymbevul(S[i])||S[i]=='('||S[i]=='[')&&(isnumc(S[i+1])||S[i+1]=='-'||S[i+1]=='_'||isstrevul(S[i+1])||S[i+1]=='('||S[i+1]=='[')) )
         )
      )
      {seterr(E_EXPR);
       return 0;
      }
   }
 return 1;
}
