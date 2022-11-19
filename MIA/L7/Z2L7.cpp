#include<iostream>
using namespace std;
long long GCD(long long a, long long b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return GCD(b,a%b);
    }
}
int main()
{
    long long t,n,a[100000],b[100000];
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        //Tutaj kod piszemy dalej
        //chcemy żeby ciąg b_n a_i = GCD(b_i,b_(i+1)) dla i=1,2,...,n-1
        //b będzie o 1 większy zawsze od a
        //b_1 = lcm(a_1,a_0) a tak naprawdę to lcm | b_1
        //b_2 = lcm(a_2,a_1) a tak naprawdę to lcm | b_2
        //szukamy najmniejszych liczb możliwych
        //i to w sumie wszystko teraz trzeba napisać
        if()
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}