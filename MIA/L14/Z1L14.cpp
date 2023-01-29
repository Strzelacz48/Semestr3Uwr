#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    long long xtab[4], ytab[4];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>xtab[i]>>ytab[i];
    }
    if(n<=1)
    {
        cout<<-1;
        return 0;
    }
    if(n==2)
    {
        if(xtab[0]==xtab[1] || ytab[0]==ytab[1])
        {
            cout<<-1;
            return 0;
        }
        else
        {
            cout<<abs(xtab[0]-xtab[1])*abs(ytab[0]-ytab[1]);
        }
    }
    if(n>=3)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(xtab[i]!=xtab[j] && ytab[i]!=ytab[j])
                {
                    cout<<abs(xtab[i]-xtab[j])*abs(ytab[i]-ytab[j]);
                    return 0;
                }
            }
        }
    }
    return 0;
}
