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
    if(n<k)
    {
        cout<<0;
        return 0;
    }
    //do wypisywania tabelki
    /*for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<tab[i][j]<<" ";
        }
        cout<<"\n";
    }*/

    int pictures = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            for (int sz = 1; sz + j <= c; sz++) {//szerokosc
                for (int wys = 1; wys + i <= r; wys++) { //wysokosc
                    int violas = 0;
                    for (int x = i; x < i + wys; x++) {
                        for (int y = j; y < j + sz; y++) {
                            if (tab[x][y] == 1)
                                violas++;
                        }
                    }
                    if(violas >= k) {
                        pictures++;
                    }
                }
            }
        }
    }
    cout << pictures << '\n';
    return 0;
}
