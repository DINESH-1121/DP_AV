#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[103][200005];

// time complexity = O(N*W)
int knapsack(int wt[],int val[],int W,int n)
{
    if(n==0 || W==0)
        return 0;
    if(dp[n][W]!=-1)
        return dp[n][W];
    
    if(wt[n-1]<=W)
    {
        return dp[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else
        return dp[n][W]=knapsack(wt,val,W,n-1);
}

void solve()
{
    memset(dp,-1,sizeof(dp));
    int W = 7;
    int n = 4;
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};

    cout << knapsack(wt,val,W,n) << endl;
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
