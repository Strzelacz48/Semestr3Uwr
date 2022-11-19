#include<iostream>
#include<cmath>
using namespace std;
void naiwnie(float a,float b, float c)
{
    float pierwiastek1,pierwiastek2;
    pierwiastek1=(-b+sqrt(b*b-4*a*c))/(2*a);
    pierwiastek2=(-b-sqrt(b*b-4*a*c))/(2*a);
    cout<<"Pierwiastek 1 naiwnie: "<<pierwiastek1<<", Pierwiastek 2 naiwnie: "<<pierwiastek2<<"\n";
}
void ponamysle(float a,float b, float c)
{
    float pierwiastek1,pierwiastek2;
    pierwiastek1=(-2*c)/(b+sqrt(b*b-4*a*c));
    pierwiastek2=(-b-sqrt(b*b-4*a*c))/(2*a);
    cout<<"Pierwiastek 1 z namyslem: "<<pierwiastek1<<", Pierwiastek 2 z namyslem: "<<pierwiastek2<<"\n";
}
int main()
{
        float a,b,c;
        cin>>a>>b>>c;
        cout<<"a: "<<a<<", b: "<<b<<", c: "<<c<<"\n";
        naiwnie(a,b,c);
        ponamysle(a,b,c);
    return 0;
}