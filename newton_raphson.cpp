#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
ld a,b,c;

ld func(ld x)
{
    return a*x*x+b*x+c;
}

ld derivative(ld x)
{
    return 2*a*x+b;
}

ld newton_raphson()
{
 ld x1=0,x2,f,d,count=0;

 while(func(x1)!=0)
 {
   count++;
   d=derivative(x1);
   f=func(x1);
   x2=x1-(f/d);
   x1=x2; 
 }
 cout<<"Total iteration for newton_raphson method is: "<<count<<endl;
 return x2;

}


int main()
{
    cout<<"Enter a, b, c for the equation ax^2+bx+c :";
    cin>>a>>b>>c;
    ld result;
    result=newton_raphson();
    cout<<setprecision(10)<<fixed;
    cout<<"The root is : "<<result<<endl;

    return 0;
}