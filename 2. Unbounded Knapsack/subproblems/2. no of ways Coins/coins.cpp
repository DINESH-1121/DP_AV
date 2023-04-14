#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[103][200005] = {0};

int dp1[103][200005];
int unknapsack(int n,int coins[],int target)
{
    if(target==0){

        return 1;
    }
    if(n==0)
        return 0;
    if(dp1[n][target]!=-1)
        return dp1[n][target];
    int ans = 0;
    if(coins[n-1]<=target)
    {
        ans = unknapsack(n,coins,target-coins[n-1])+unknapsack(n-1,coins,target);
    }
    else
    {
        ans = unknapsack(n-1,coins,target);
    }
    return dp1[n][target] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 3;
    int coins[] = {1, 2, 3};
    int target = 5;
    memset(dp1,-1,sizeof(dp));

    cout << unknapsack(n,coins,target) << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (coins[i-1] <= j)
            {
                dp[i][j] = (dp[i][j-coins[i-1]] + dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
 
    cout << dp[n][target] << endl;
}