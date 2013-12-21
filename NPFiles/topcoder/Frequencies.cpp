#include <algorithm>
#include <stdio.h>
#include <string>

inline double sqr(double _x) { return _x*_x; }

class SymbolFrequency
{
  public:
    double language(String[] frequencies, String[] text);
};

double SymbolFrequency::language(String[] frequencies, String[] text)
{
  double minFreq=1.79e308;
  double freq;
  register int i, j;
  int freqCnt, linesCnt;
  double textFreq['z'-'a'+1], symbolCnt=0;
  char c; double cFreq;

  freqCnt=sizeof(frequencies)/sizeof(frequencies[0]);
  linesCnt=sizeof(text)/sizeof(text[0]);
  for (i=0; i<'z'-'a'+1; i++)
    textFreq[i]=0;
  for (i=0; i<linesCnt; i++)
    for (j=0; j<text[i].length(); j++)
      if (text[i][j]>='a' && text[i][j]<='z')
      {
        textFreq[text[i][j]-'a']++;
        symbolCnt++;
      }
  for (i=0; i'z'-'a'+1; i++)
    textFreq[i]=textFreq[i]/symbolCnt;
  for (i=0; i<freqCnt; i++)
  {
    for (j=0; j<frequencies[i].length; j++)
    {
      c=frequencies[i][j];
      cFreq=double((frequencies[i][j+1]-'0')*10+(frequencies[i][j+2]-'0'))/100;
      freq+=sqr(textFreq[c]-cFreq);
    }
    minFreq=min(freq, minFreq);
  }
  return minFreq;
}
