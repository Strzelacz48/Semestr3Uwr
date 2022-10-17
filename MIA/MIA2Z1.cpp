#include<iostream>
using namespace std;
int main()
{
    int v,n;
    cin >> n >> v;
    if (n <= v) {
        cout << n - 1;
        return 0;
    }
    cout << v + ((n - v + 1) * (n - v)) / 2 - 1;
}
