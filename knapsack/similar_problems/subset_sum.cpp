#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    vector<int> v({2,3,7,8,10});
    int n =v.size();
    int sum = 11;

    bool table[n+1][sum+1];
    memset(table,-1,sizeof(table));
    bool f = false;

    for(int i=0;i<n+1;i++)
        table[i][0] = true;
    for(int i=1;i<=sum;i++)
        table[0][i] = false;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(v[i-1]<=sum)
                table[i][j] = (table[i-1][j-v[i-1]]||table[i-1][j]);
            else
                table[i][j] = table[i-1][j];
        }
    }
    cout << table[n][sum] << endl;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll test=1;
//cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}