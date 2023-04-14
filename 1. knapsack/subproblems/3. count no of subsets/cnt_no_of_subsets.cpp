#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[103][200005];

int fun(int n,int arr[],int target)
{
    if(target==0)
        return 1;
    if(n<0)
        return 0;
    int ans = 0;
    if(arr[n-1]<=target)
    {
        ans+=(fun(n-1,arr,target-arr[n-1]));
        ans+=fun(n-1,arr,target);
    }
    else
        ans+=fun(n-1,arr,target);
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 6;
    int arr[] = {2,3,5,6,8,10};
    int target = 10;

    cout << fun(n,arr,target) << endl;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=target;j++)
        {
            if(j==0)
                dp[i][j] = 1;
            else if(i==0)
                dp[i][j] = 0;
            else
                dp[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=target;j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n][target] << endl;

}