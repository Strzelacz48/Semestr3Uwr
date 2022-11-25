#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long wynik=1;//pom=n*n,it=0;
    //n--;
    wynik=n*n*(n-1)*(n-1)/4*(n-2)*(n-2)*(n-3)*(n-3)/6*(n-4)*(n-4)/5;
    //wynik/=120;
    cout<<wynik;
    return 0;
}