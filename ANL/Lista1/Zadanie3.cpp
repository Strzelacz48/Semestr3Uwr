#include<iostream>
#include <cmath>
using namespace std;
double funkcja1(int n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)
    {
        return -1.0/7.0;
    }
    else
        return ((146.0/7.0)*funkcja1(n-1))+(3*funkcja1(n-2));
}
double funkcja2(int n)
{
    return pow(-1.0/7.0,n);
}
int main()
{
    //printf("y_%d = %lf",5,funkcja(5));
    short typ;
    cout<<"Wersja zoptymailzowana 2 \nWersja niezoptymailowana 1\n";
    cin>>typ;
    if(typ==1)
    {
        for(int i=2;i<40;i++)
        {
            printf("y_%d = %lf \n",i,funkcja1(i));
        }
    }
    else
    {
        for(int i=2;i<40;i++)
        {
            printf("y_%d = %lf \n",i,funkcja1(i));
        }
    }

    //cout<<pow(10,-3);
    return 0;
}
