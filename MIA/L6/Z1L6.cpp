#include<iostream>
using namespace std;
int main()
{
    long k,n;
    long long maxawake=0;
    cin>>n;
    cin>>k;
    bool awake[n];
    int theorems[n];
    long long sums[n];
    for(int i=0;i<n;i++)
    {
        cin>>theorems[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>awake[i];
        if(awake[i])
        {
            maxawake+=theorems[i];
            if(i<k)
            {
                if(i==0)
                {
                    sums[i]=0;
                }
                else
                {
                    sums[i]=sums[i-1];
                }
            }
            else
            {
                if(awake[i-k])
                {
                    sums[i]=sums[i-1];
                }
                else
                {
                    sums[i]=sums[i-1]-theorems[i-k];
                }
            }
        }
        else
        {
            if(i<k)
            {
                if(i==0)
                {
                    sums[i]=theorems[i];
                }
                else
                {
                    sums[i]=sums[i-1]+theorems[i];
                }
            }
            else
            {
                if(awake[i-k])
                {
                    sums[i]=sums[i-1]+theorems[i];
                }
                else
                {
                    sums[i]=sums[i-1]+theorems[i]-theorems[i-k];
                }
            }
        }
    }
    //cout<<"maxawake : "<<maxawake;
    long long maxasleep=0;
    for(int i=0;i<n;i++)
    {
        if(sums[i]>maxasleep)
        {
            maxasleep=sums[i];
        }
    }
    cout<<maxawake+maxasleep;

    return 0;
}