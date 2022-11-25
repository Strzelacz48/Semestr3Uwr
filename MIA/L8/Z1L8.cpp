#include<iostream>
using namespace std;
long long slabnia(long long x)
{
    x--;
    long long wynik=(1+x)*x/2;
    return wynik;
}
int main()
{
    long long m,n,kmin=0,kmax=0;
    cin>>n>>m;
    kmax=slabnia(n-m+1);
    if(n%m==0)
    {
        kmin=m*slabnia(n/m);
    }
    else
    {
        kmin=(n%m)*slabnia((n/m)+1)+(m-(n%m))*slabnia(n/m);
    }
    cout<<kmin<<" "<<kmax;
    return 0;
}