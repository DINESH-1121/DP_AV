#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool dp[103][200004];

void solve()
{
    int target = 6;
    int n = 5;        
    int arr[] = {2,3,7,8,10};

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(j==0)
                dp[i][j] = true;
            else if(i==0)
                dp[i][j] = false;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = (dp[i-1][j]||dp[i-1][j-arr[i-1]]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][target] << endl;
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


