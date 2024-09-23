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

ld secant()
{
    ld x1,x2,x3=0,f1,f2,count=0;
    x1=0,x2=5;
    while(true)
    {
        count++;
        f1=func(x1);
        f2=func(x2);
        x3=x2-((f2*(x2-x1))/(f2-f1));
        if(func(x3)==0)
        break;
        x1=x2;
        x2=x3;
    }
    cout<<"Total needed iteration for secant method : "<<count<<endl;
    return x3;
}


int main()
{
    cout<<"Enter a, b, c for the equation ax^2+bx+c :";
    cin>>a>>b>>c;
    ld result;
    result=secant();
    cout<<setprecision(10)<<fixed;
    cout<<"The root is : "<<result<<endl;

    return 0;
}
