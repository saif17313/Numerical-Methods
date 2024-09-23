//2107017
//False Position Method
#include<bits/stdc++.h>
using namespace std;

long double a,b,c;

long double func(long double x)
{
    return a*x*x+b*x+c;
}

void false_position(long double p,long double q)
{
    long double x,x1=0,d=1000;
    int count=0;
    while(d>0.0001)
    {
        count++;
       x=(p*func(q)-q*func(p))/(func(q)-func(p));

    if(func(x)==0.0)
        break;

    if(func(x)*func(p)<0.0)
    {
       q=x;
    }
    else
    {
      p=x;
    }
    d=abs(x-x1);
    x1=x;
    }
    cout<<setprecision(10)<<fixed;
    cout<<"The value is : "<<x<<endl;
    cout<<"The total needed iteration is:"<<count<<endl;
}

int main()
{
    cout<<"ax^2+bx+c\n Enter a,b,c : ";
    cin>>a>>b>>c;
    long double p=0,q=1,time_taken;
    //time_t start,end;
    //time(&start);
    while(func(p)*func(q)>=0)
    {
       if(func(p)==0.0)
       {
           cout<<"The value is : "<<p<<endl;
           return 0;
       }
       else if(func(q)==0.0)
       {
         cout<<"The value is : "<<q<<endl;
           return 0;
       }
       p++;
       q++;
    }
    cout<<"a,b:\n"<<p<<endl<<q<<endl;
    false_position(p,q);
    //time(&end);
    //time_taken=double(end-start);
    cout<<setprecision(20)<<fixed;
    //cout<<"Total taken time to solve this equation is: "<<time_taken<<" sec"<<endl;
    return 0;
}






