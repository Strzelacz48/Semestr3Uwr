#include<iostream>
using namespace std;
int main()
{
int n,q;
int warriors[200000],pom[200001];
long arrows[200000];
cin>>n>>q;
for(int i=0;i<n;i++)
{
    cin>>warriors[i];
}
pom[0]=0;
for(int i=1;i<n+1;i++)
{
    pom[i]=pom[i-1]+warriors[i-1];
}
for(int i=0;i<=n;i++)
{
    cout<<pom[i]<<" ";
}
for(int i=0;i<q;i++)
{
    cin>>arrows[i];
}
int overdmg=0;
for(int i=0;i<q;i++)
{
//bin search upper_bound()
if(overdmg+arrows[i]>=pom[n])
{
    overdmg=0;
    cout<<n<<"\n";
}
else
{//bin search po pom
    int l=0;
    int r=n;
    int x=arrows[i]+overdmg;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(pom[mid]>x)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
        if(pom[mid-1]<=x && pom[mid]>x)
        {
            cout<<n-mid+1<<"\n";
            overdmg=x-pom[mid];
            break;
        }
        //działa test 1 test 2 nie
    }
    //cout<<n-l<<endl;
}
}
return 0;
}

/*for(int i=0;i<q;i++)
{
    while(arrows[i]>0)
    {
        if(idx>=n)
        {
            idx=0;
            for(int j=0;j<n;j++)
            {
                warriors[j]=pom[j];
            }
        }
        if(warriors[idx]>0)
        {
            warriors[idx]--;
            arrows[i]--;
        }
        else
        {
            idx++;
        }
    }
    cout<<idx+1<<endl;
}*/
