#include<iostream>
#include<string>
using namespace std;
bool pal(long long a, long long b, string s)
{
    while(a<b)
    {
        if(s[a]!=s[b]) return false;
        a++;
        b--;
    }
    return true;
}
int main()
{
    string s;
    long long k;
    cin>>s>>k;
    if(s.length()%k!=0)
    {
        cout<<"NO";
        return 0;
    }
    long long n=s.length()/k;
    for(long long i=0;i<k;i++)
    {
        if(!pal(i*n,(i+1)*n-1,s))
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}