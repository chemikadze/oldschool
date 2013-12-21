//---------------------------------------------------------------------------
#ifndef NPSH
#define NPSH

#ifdef __MSDOS__
#define _OLD_
#endif

#ifdef _OLD_
#define NFUNC (fctan-cpi+1+HYP)                //count of functions
#define cst_free (cst==NULL || cdeep==0)
#define nst_free (nst==NULL || ndeep==0)
#define cst_clear while (!cst_free) cpop()
#define nst_clear while (!nst_free) npop()
#define cst_end cst->val
#define nst_end nst->val
#define nst_preend nst->next->val
#else
#include <fastmath.h>
#include <vector.h>
#define cst_free (cst.empty())
#define nst_free (nst.empty())
#define cst_clear cst.clear()
#define nst_clear nst.clear()
#define cst_end cst.back()
#define nst_end nst.back()
#define nst_preend nst.at(nst.size()-2)
#define NFUNC (fctan-cpi+1+ARC+HYP)                //count of functions
#endif

#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define ARC 4                               //offset of ARC- functions
#define HYP 8                               //offset of HYP- functions

#define _DEFX_ 1

#define isfn(c) (c>=fexp && c<=ARC+fctan+HYP && c!=f_op_root && c!=f_op_pow)  //is function
#define isconst(c) (c==cpi || c==cx)          //is constant
#define isstrevul(c) (isfn(c) || isconst(c))  //is string evulated expression
#define issymbevul(c)  (c=='+' || c=='-' || c=='*' || c==f_op_pow || c==f_op_root || c=='^' || c=='/' || c=='!' || c==',' || c=='_')
#define isevul(c) (isstrevul(c) || issymbevul(c)) //is evulated expression
#define isnumc(c) (isdigit(c) || c=='.' || c=='e') //is numeric charter
#define isgood(c) (isnumc(c) || isevul(c) || c=='(' || c==')' || c==' ' || c=='_' || c=='[' || c==']')          //is "good" symbol (for polish)
#define isgoodin(c) (isnumc(c) || c>='a' && c<='z' || issymbevul(c) || c=='(' || c==')' || c==' ' || c=='[' || c==']')//is "good" input

#define addspc() if (r[j-1]!=' ') r[j++]=' '
#define minusE (i>0?S[i-1]=='e':0)
#define minusN ((i>0 && i<SL)?((S[i-1]=='(' || S[i-1]==',' || S[i-1]=='[' || issymbevul(S[i-1]))&&isnumc(S[i+1])):1)
#define minusF ((i>0?(S[i-1]=='(' || S[i-1]==',' || S[i-1]=='[' || issymbevul(S[i-1])):1)&&(i<SL?(isevul(S[i+1])):1))
//***********************************************************************
//******************CHANGEBLE********************************************
#define S_E_NO       "No errors"
#define S_E_DEV_ZERO "Devision by zero"
#define S_E_FN       "Bad operand or function name"
#define S_E_ARG      "Bad value or argument"
#define S_E_HUGE     "Too huge value"
#define S_E_VOID     "Void expression"
#define S_E_EXPR     "Bad expression"
#define S_E_BR       "Error in brackets"
#define S_E_UNK      "Unknown error"

#define R_E_NO       "Нет ошибок"
#define R_E_DEV_ZERO "Деление на ноль"
#define R_E_FN       "Неправильное имя функции или оператора"
#define R_E_ARG      "Плохое значение аргумента"
#define R_E_HUGE     "Слишком большое значение"
#define R_E_VOID     "Пустое выражение"
#define R_E_EXPR     "Неправильное выражение"
#define R_E_BR       "Ошибка скобок"
#define R_E_UNK      "Неизвестная ошибка"

typedef enum {E_NO=0,
	      E_DEV_ZERO,
	      E_FN,
	      E_ARG,
	      E_HUGE,
              E_VOID,
              E_EXPR,
              E_BR,
	      E_UNK} TError;
//********************END END CHENGABLE FNS*********************************
//**************************************************************************

struct tcst
  {struct tcst* next;
   char val;
  };

struct tnst
  {struct tnst* next;
   long double val;
  };

typedef struct tnst TNSt;
typedef struct tcst TCSt;

char* strdbl(const char* s);

class TSolver
{protected:
   char* S;
   long double R;
   TError Err;
   TError seterr(const TError E)
     {if (Err==E_NO) Err=E;return Err;}
   long double X;
   int poled;
   int converted;
   int good;
#ifndef _OLD_
   vector<long double> nst;
   vector<char> cst;
#else
   long int ndeep;
   long int cdeep;
   TNSt* nst;
   TCSt* cst;
#endif
   char cpop();
   long double npop();
   void cpush(const char c);
   void npush(const long double n);
   char* convtopol();
   char* convert();
   long double calc(const char f,const long double a,const long double b);
   long double calcstp(const char f,const long double a,const long double b,const int pos);
   long double gcalc(const char f,const long double a,const long double b,const long double step);
   int checkin();
   int checkout();
   int checkbr();
   int checkexpr();
 public:
   void sets(const char* s)
     {if (S!=NULL && S!="") free(S);
      S=strdbl(s);
      poled=converted=good=0;
     }
   inline char* gets()const {return S;}
   TError geterr()const;
   char* getstrerr()const;
   char* getruserr()const;
   inline void setx(const long double x);
   inline long double getx()const;
   char* strtopol();
   long double solvepol();
   long double solve();
   long double solvepolstp(const long double step=0);
   long double solvepolx(const long double x,const long double step=0);
   long double solvex(const long double x,const long double step=0);
   inline long double result()const {return R;}

   TSolver():X(_DEFX_),R(0),Err(E_NO),S(NULL),poled(0),converted(0),good(0)
     {
      #ifdef _OLD_
      ndeep=cdeep=0;
      #endif
     }
   TSolver(const char* s):X(_DEFX_),R(0),Err(E_NO),S(NULL),poled(0),converted(0),good(0)
     {sets(s);
      #ifdef _OLD_
      ndeep=cdeep=0;
      #endif
     }
   TSolver(const char* s,const long double x):X(x),R(0),Err(E_NO),S(NULL),poled(0),converted(0),good(0)
     {sets(s);
      #ifdef _OLD_
      ndeep=cdeep=0;
      #endif
     }
   ~TSolver()
     {if (S!=NULL)
      free(S);
      nst_free;
      cst_free;
     }
};

extern int prior(const char f);           //gives priority of function
extern int argcnt(const char c);          //count of arguments
extern long double factor(long double f);                    //factorial 2 :)
 //calculates function
//---------------------------------------------------------------------------
#endif


