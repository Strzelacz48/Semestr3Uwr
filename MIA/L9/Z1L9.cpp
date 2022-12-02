#include<iostream>
using namespace std;
struct student
{
    long long blame;
    bool punished;
};
/*
void DFS(struct studnet *tab,long long i,long long n)
{
    for(int j=0;j<n;j++)
    {
        tab[j].punished=false;
    }
    while(tab[i].punished==false)
    {
        tab[i].punished=true;
        i=tab[i].blame;
    }
    cout<<i<<" ";
}*/
int main()
{
    long long n;
    cin>>n;
    student tab[n];
    //bool pom[n];
    for(int i=0;i<n;i++)
    {
        cin>>tab[i].blame;
        tab[i].blame--;
        tab[i].punished=false;
    }
    
    for(int ii=0;ii<n;ii++)
    {
        long long i=ii;
        for(int j=0;j<n;j++)
        {
            tab[j].punished=false;
        }
        while(tab[i].punished==false)
        {
            tab[i].punished=true;
            i=tab[i].blame;
        }
        cout<<i+1<<" ";
    }
    return 0;
}