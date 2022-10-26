#include<iostream>
using namespace std;
int main()
{
    int r,c,n,k;
    cin>>r>>c>>n>>k;
    bool tab[r][c];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            tab[i][j]=false;
        }
    }
    int rp,cp;
    for(int i=0;i<n;i++)
    {
        cin>>rp>>cp;
        tab[rp-1][cp-1]=true;
    }
    if(n==k)
    {
        cout<<1;
        return 0;
    }
    else if(n<k)
    {
        cout<<0;
        return 0;
    }
    //rp=r;
   // cp=c;
   // int sum=0;
   // while(rp*cp>=k)
   // {

   // }
    //do wypisywania tabelki
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
