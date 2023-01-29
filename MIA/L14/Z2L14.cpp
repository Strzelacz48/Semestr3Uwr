#include<iostream>
using namespace std;
long long area(long long x1,long long y1, long long x2, long long y2)
{
    return abs(x1-x2)*abs(y1-y2);
}
int main()
{
    long long x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,x6,y6;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;
    long long a1=area(x1,y1,x2,y2);
    long long a2=area(x3,y3,x4,y4);
    long long a3=area(x5,y5,x6,y6);
    //cout<<"a1 : "<<a1<<endl;
    //cout<<"a2 : "<<a2<<endl;
    //cout<<"a3 : "<<a3<<endl;
    if(a1>a2+a3)
    {
        cout<<"YES";
        return 0;
    }
    if(x3<x1)
    {
        //cout<<"x3<x1\n"<<"x3 : "<<x3<<endl<<"x1 : "<<x1<<endl;
        x3=x1;
    }
    if(y3<y1)
    {
        y3=y1;
    }
    if(x4>x2)
    {
        x4=x2;
    }
    if(y4>y2)
    {
        y4=y2;
    }
    if(x5<x1)
    {
        x5=x1;
    }
    if(y5<y1)
    {
        y5=y1;
    }
    if(x6>x2)
    {
        x6=x2;
    }
    if(y6>y2)
    {
        y6=y2;
    }
    //cout<<"a1 : "<<a1<<endl;
    a2=area(x3,y3,x4,y4);
    //cout<<"a2 : "<<a2<<endl;
    a3=area(x5,y5,x6,y6);
    //cout<<"a3 : "<<a3<<endl;
    if(a1>a2+a3)//nie dziala bo nie sprawdza czy nie ma przeciecia czarnych prostokatow
    {
        cout<<"YES";
        return 0;
    }
    else
    {
        cout<<"NO";
        return 0;
    }
}