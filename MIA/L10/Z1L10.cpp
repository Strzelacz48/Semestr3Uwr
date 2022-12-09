#include<iostream>
using namespace std;
long long newton(long long n)
{
    if(n < 2)
        return 0;
    else
        return n*(n-1)/2;
}
int main()
{
    long long n,distance;
    cin>>n>>distance;
    long long tab[n];
    for(long long i = 0; i < n; i++)
    {
        cin>>tab[i];
    }
    long long a = 0,b = 0,wynik = 0;
    bool last = false;
    while(a < n)
    {
        if(abs(tab[b]-tab[a]) <= distance && b < n)
        {
            last = true;
            b++;
            //cout<<"b ";
        }
        else
        {
            wynik += newton(abs(b - a - 1));
            //cout<<"wynik "<<wynik<<endl;
            a++;
            //cout<<"a ";
        }
    }
    cout<<wynik;
    return 0;
}