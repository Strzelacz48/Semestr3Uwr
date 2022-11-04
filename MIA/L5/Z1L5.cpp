#include<iostream>
using namespace std;
struct FU
{
    int parent; // ojciec
    int sz; // rozmiar
    int cost; // koszt danego słowa
    int minimum;// indeks najmniejszego kosztu w grupie
};
FU tab[1000007];
string nazwy[1000007];
int n;
void init()
{
    for(int i=0; i<n; i++)
    {
        tab[i].parent = i; // uznajemy, że korzeń jest swoim własnym ojcem
        tab[i].sz = 1; // rozmiar każdej składowej to 1
        cin>>tab[i].cost;
        tab[i].minimum=i;
    }
}
int Find(int nr)
{
    if(tab[nr].parent == nr)
        return nr;
    tab[nr].parent = Find(tab[nr].parent);
    return tab[nr].parent;
}
void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a == b)
        return;
    if(tab[a].sz < tab[b].sz)
        swap(a, b);
    if(tab[tab[a].minimum].cost>tab[tab[b].minimum].cost)
        tab[a].minimum=tab[b].minimum;
    tab[b].parent = a;
    tab[a].sz += tab[b].sz;
}
int Fnazwy(string x)
{
    for(int i=0;i<n;i++)
    {
        if(nazwy[i]==x)
            return i;
    }
    return 0;
}
int main()
{
    int k,m;
    cin>>n>>k>>m;
    
    for(int i=0;i<n;i++)
    {
        cin>>nazwy[i];
    }
    init();
    for(int i=0;i<k;i++)
    {
        int j,pop,nast;
        cin>>j>>pop;
        pop-=1;
        for(int ii=1;ii<j;ii++)
        {
            cin>>nast;
            nast-=1;
            Union(pop,nast);
        }
    }
    string slowo;
    int wynik=0;
    for(int i=0;i<m;i++)
    {
        cin>>slowo;
        int struktura=Fnazwy(slowo);
        wynik+=tab[tab[tab[struktura].parent].minimum].cost;
        //cout<<nazwy[struktura]<<" ";
    }
    cout<<wynik;
    return 0;
}