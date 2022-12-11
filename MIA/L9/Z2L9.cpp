#include <algorithm>
#include <iostream>
#include <vector>
 
#define MAX 105
 
using namespace std;
vector<bool> Reach(MAX, false);
vector< pair<int,int> > Interval;
 
void dfs(int n)
{
    Reach[n] = true;
 
    for(int i = 1; i < Interval.size(); i++)
        if(!Reach[i])
            if((Interval[n].first > Interval[i].first && Interval[n].first < Interval[i].second) || (Interval[n].second > Interval[i].first && Interval[n].second < Interval[i].second))
                dfs(i);
}
 
int main()
{
    int Q;
    cin >> Q;
    Interval.push_back(make_pair(0,0));
 
    while(Q--)
    {
        int t, x, y;
        cin >> t >> x >> y;
 
        if(t == 1)
            Interval.push_back(make_pair(x,y));
        else
        {
            fill(Reach.begin(), Reach.end(), false);
            dfs(x);
 
            if(Reach[y])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}
