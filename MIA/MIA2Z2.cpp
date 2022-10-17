#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int tab[n];
    int a,b,sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>tab[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        if(tab[a-1]>tab[b-1])
        {
            sum+=tab[b-1];
        }
        else
            sum+=tab[a-1];
    }
    cout<<sum;
    return 0;
}
