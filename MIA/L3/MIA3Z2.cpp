#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int k,p;
    long suma=0;
    cin>>k>>p;
    for(int i=1;i<=k;i++)
    {
        int num=i,rev=0,pot=0;
        while(num>0)
        {
            rev=rev*10+num%10;
            num/=10;
            pot++;
        }
        //cout<<i*pow(10,pot)+rev<<"\n";
        suma+=i*pow(10,pot)+rev;
    }
    cout<<suma%p;
    return 0;
}
