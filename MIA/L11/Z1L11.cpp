#include<iostream>
using namespace std;
bool ispal(string s)
{
    long long tab[26]={0}, odd=0;
    for(int i = 0;i < s.length();i++)
    {
        tab[s[i] - 97]++;
    }
    for(int i = 0;i < 26;i++)
    {
        if(tab[i]%2!=0)
        {
            odd++;
            //cout<<i<<" odd : "<<odd<<"\n";
        }
    }
    if(odd<=1)
        return true;
    else if(odd%2==0)
        return false;
    else
        return true;
}

int main()
{
    string s;
    //bool first = true;
    cin>>s;
    if(ispal(s))
    {
        cout<<"First";
    }
    else
    {
        cout<<"Second";
    }
    return 0;
}