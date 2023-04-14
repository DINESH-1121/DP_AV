#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int dp[102][1002];
int knapsack(int n,int wt[],int val[],int W)
{
    if(n==0 || W==0)
        return 0;
    if(dp[n-1][W]!=-1)
        return dp[n-1][W];

    int ans = 0;
    if(wt[n-1]<=W)
    {
        ans = max(val[n-1]+knapsack(n-1,wt,val,W-wt[n-1]),knapsack(n-1,wt,val,W));
        dp[n-1][W] = ans;
        return ans;
    }
    else{
        return dp[n-1][W] = knapsack(n-1,wt,val,W);
    }
}

void solve()
{
    int n = 4;
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int W=7;
    memset(dp,-1,sizeof(dp));
    cout << knapsack(n,wt,val,W) << endl;
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
