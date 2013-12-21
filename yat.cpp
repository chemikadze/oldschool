#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

class parabola
{
	double x,a,b,c;
public:
	parabola()
	{
		cout<<"PARABOLA";
		cout<<"\nvvedite a...";
		cin>>a;
		cout<<"\nvvedite b...";
		cin>>b;
		cout<<"\nvvedite c...";
		cin>>c;
		cout<<"\nvvedite x...";
		cin>>x;
		cout<<"\ny="<<a*x*x+b*x+c<<"\n";
	}

	void otric()
	{
		cout<< "\n\tOTRICTATEL'NOE ZNACHENIE FUNKCTII\n";
		double t,m,w,i,j,n,v,k,g=0;
		cout<<"\nvvedite niznyu granictu...";
		cin>>n;
		cout<<"\nvvedite verhnyu granictu...";
		cin>>m;
		cout<<"\nvvedite chag...";
		cin>>t;
		w=0;

		for(i=n;i<=m;i=i+t){
			if((a*i*i+b*i+c)<0){
				for(j=i+t;j=10000;j=j+t){    /// может быть j == 10000 ?
					if((a*j*j+b*j+c)<0){
						w=j;
						break;
					}
				}
				{	
					if(w<m)
						cout<<"\n("<<i<<","<<w<<")";
					else 
						cout<<"\n("<<i<<","<<m<<")";
				}
				break;
			}
			else 
				g=1; 
		}

		if (a<0){
			for(i=w;i<=m;i=i+t){
				if((a*i*i+b*i+c)<0){
					k=i; 
					cout<<"\n("<<k;n=k+t;
					for(j=k+t;j<=m;j=j+t){
						if((a*j*j+b*j+c)>0){
							cout<<","<<j<<")";
							w=j;
							break;
						}
						else {
							cout<<","<<m<<")";
							break;
						}
					}
					break;
				}
				else 
					g=1; 
			}

		}
		if (g==1)
			cout<<"\nnet intervalov";
	}
};


int main(){
	parabola u;
	u.otric();
	getch();
	return 0;
}

//он если вводишь a=1 b=0 c=-1 n=-3 m=3 выводит (-1,0) хотя должен (-1,1)???
