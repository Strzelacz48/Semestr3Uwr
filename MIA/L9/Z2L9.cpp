#include<iostream>
using namespace std;
//przy dodaniu przedziału zapisujesz gdzie mozesz isc
//Odpalamy dfs-a przy pomocy tych danych
//
struct {
    long long x;
    long long y;
    bool visited;
}interval;
bool pathfind(pair<long long,long long> *tab, long long target,long long position,long long n)
{
    if(tab[target].first<tab[position].second && tab[position].second<tab[target].second || tab[target].first<tab[position].first && tab[position].first<tab[target].second)
    {
        return true;
    }
    for(int i=n;i>0;i--)
    {
        if(i==position)
        {
            continue;
        }
        if(tab[i].first<tab[position].second && tab[position].second<tab[i].second || tab[i].first<tab[position].first && tab[position].first<tab[i].second)
        {
            if(pathfind(tab,target,i,n))
            {
                return true;
            }
        }
    }
    return false;
}
/*
void DFS(struct interval *tab,long long from,long long to,long long n)
{
    for(int i=0;i<n;i++)
    {
        tab[i].visited=false;
    }
    WIP
} */
int main()
{
    int pom;
    long long n,x,y,it=0;
    pair<long long,long long> tab[n];
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        cin>>pom;
        if(pom==1)//add interval
        {
            cin>>x>>y;
            tab[it].first=x;
            tab[it].second=y;
            it++;

        }
        else//check interval
        {
            cin>>x>>y;
            if(pathfind(tab,y,x,it))
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
    return 0;
}