#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[103][200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n = 4;
    int wt[] = {1,2,4,5};
    int val[] = {1,4,5,7};
    int W = 7;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][W] << endl;

}