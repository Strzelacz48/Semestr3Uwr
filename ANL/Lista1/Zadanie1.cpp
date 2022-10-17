#include<iostream>
#include <cmath>
using namespace std;
double funkcja1(double x)
{
    x=pow(x,13);
    return 4044*(((sqrt(x+1))-1)/x);
}
double funkcja2(double x)
{
    x=pow(x,13);
    return 4044/((sqrt(x+1))+1);
}
int main()
{
    cout<<"Oczekiwany wynik (z WolframAplha): ok. 2022 =2021.99999999999..\n";
    cout<<"Wynik z podejścia bez namysłu : "<<funkcja1(0.001)<<"\n";
    cout<<"Wynik z podejścia po namyśle : "<<funkcja2(0.001)<<"\n";

    return 0;
}
