//---------------------------------------------------------------------------

#include <stdio.h>
#include <vector>
#include <cmath>
using std::vector;

//---------------------------------------------------------------------------

class SpeedRadar
{
  public:
    double averageSpeed(int minLimit, int maxLimit, vector <int> readings);
};

double SpeedRadar::averageSpeed(int minLimit, int maxLimit, vector <int> readings)
{
  register int i, j;
  int ok=0;
  double speedSum;
  for (i=0; i<readings.size(); i++)
    if (readings[i]>=minLimit && readings[i]<=maxLimit)
    {
      speedSum+=readings[i];
      ok++;
    }
  if (double(ok)/readings.size()>0.1)
    return 0.0;
  else
    return speedSum/ok;
}

SpeedRadar* radar;

int main(int argc, char* argv[])
{
  double ans;
  vector <int> v;
  v.reserve(3);
  v[0]=40; v[1]=45; v[2]=50;
  radar=new SpeedRadar;
  ans=radar->averageSpeed(1, 50, v);

  return 0;
}
//---------------------------------------------------------------------------
