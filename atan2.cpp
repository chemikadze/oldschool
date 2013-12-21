#include <math.h>
#include <iostream>

using namespace std;
	
int main()
{
	double x, y;
	double alpha, alpha2;
	cout << "Enter X, Y: ";
	cin >> x >> y;
	alpha2=atan2(y, x);
	cout << "atan2: " << alpha2 + (alpha2<0)*M_PI*2 << endl;
	cout << "atan:  " << ((x!=0) ? ( atan(y/x) + (x<0)*M_PI + (x>0 && y<0)*2*M_PI ) : ( (y>0)*M_PI/2 + (y<0)*3*M_PI/2 )) << endl; 
}
