#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    int n = 4;
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int W=7;

    int table[n+1][W+1];
    memset(table,-1,sizeof(table));
    for(int i=0;i<n;i++)
        table[i][0] = 0;
    for(int j=0;j<W;j++)
        table[0][j] = 0;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(wt[i]<=W)
            {
                table[i][j] = max(val[i-1]+table[i-1][j-wt[i-1]],table[i-1][j]);
            }
            else
            {
                table[i][j] = table[i-1][j];
            }        
        }
    }
    cout << table[n][W] << endl;
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
