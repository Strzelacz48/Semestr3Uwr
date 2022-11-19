#include<iostream>
using namespace std;
int main()
{
    long long n,x,wynik=0;
    cin>>n>>x;
    
    for(long long i=1;i<=n;i++)
    {
        if(x == i)
        {
            wynik+=1;
            cout<<wynik;
            return 0;
        }
        else if(x%i==0 && x/i<=n)
        {
            wynik+=1;
        }
    }
    cout<<wynik;
    
    return 0;
}
