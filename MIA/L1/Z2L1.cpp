#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m,k;// n - number of broken segments m - length of the stick, k - max amount of tape pieces
    cin>>n>>m>>k;
    long long broken_segments[n];
    long long distance[n];//distance to the previous broken segment
    for(int i=0; i<n; i++)
    {
        cin>>broken_segments[i];
        if(i>0)
            distance[i]=broken_segments[i]-broken_segments[i-1];   
        else
            distance[i]=0;
    }
    if(k>=n)
    {
        cout<<n;
        return 0;
    }
    long long used_tape = n;
    long long sum = n;
    sort(distance,distance+n);
    long long it=1;
    while(used_tape>k)
    {
        //long long shortest_distance_idx=find_shortest_distance_idx(distance,n,m);
        used_tape--;
        sum+=distance[it]-1;
        it++;
    }
    cout<<sum;    

    
    return 0;
}