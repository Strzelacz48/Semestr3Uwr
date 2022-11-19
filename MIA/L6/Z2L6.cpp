#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int mpaircount=0,wpaircount=0;
    bool lastw,latsm;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='m' || s[i]=='w')
        {
            cout<<0;
            return 0;
        }
        else if(i>1 && s[i]=='n')
        {
            if(s[i-1]=='n')
            {
                mpaircount++;
            }
        }
        else if(i>1 && s[i]=='u')
        {
            if(s[i-1]=='u')
            {
                wpaircount++;
            }
        }
    }
    return 0;
}