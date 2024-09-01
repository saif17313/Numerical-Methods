//2107017
//Jacobian Iterative Method
#include<bits/stdc++.h>
using namespace std;

int main()
{
  double a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3,x1=0,y1=0,z1=0,x,y,z,p,q,r,l,m,n;
  cout<<"ax+by+cz=d"<<endl;
  cout<<"Enter a,b,c,d of first equation"<<endl;
  cin>>a1>>b1>>c1>>d1;
  cout<<"Enter a,b,c,d of second equation"<<endl;
  cin>>a2>>b2>>c2>>d2;
  cout<<"Enter a,b,c,d of third equation"<<endl;
  cin>>a3>>b3>>c3>>d3;
  cout<<"Successfully taken the three equations!"<<endl;
  const int maxIt=30;
  int cnt=1;
  x1=0; y1=0; z1=0;
  const long double maxTl=0.001;
  while(true)
  {
      x=(d1-(b1*y1+c1*z1))/a1; p=abs(x-x1);
      y=(d2-(a2*x1+c2*z1))/b2; q=abs(y-y1);
      z=(d3-(a3*x1+b3*y1))/c3; r=abs(z-z1);
      x1=x; y1=y; z1=z;
      cout<<cnt<<". "<<"x = "<<x<<", Ex = "<<p<<"        , y = "<<", Ey = "<<q<<"        , z = "<<z<<", Ez = "<<r<<endl;
      cnt++;
      if(p<=maxTl && q<=maxTl && r<=maxTl)
        break;
      if(cnt>=maxIt)
      {cout<<"Maximum Iteration limit reached!"<<endl;
        break;}
  }
  cout<<"\nThe Result is:\nx = "<<x<<" , y = "<<y<<" , z = "<<z<<endl;
  return 0;
}

