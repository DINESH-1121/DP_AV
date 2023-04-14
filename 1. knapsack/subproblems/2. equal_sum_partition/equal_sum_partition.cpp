#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool dp[103][200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 4,su=0;
    int arr[] = {1,5,5,11};
    for(int i=0;i<n;i++)
        su+=arr[i];

    if(su%2!=0){
        cout << 0 << endl;
        return 0;
    }
    su/=2;
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=su;j++)
        {
            if(j==0)
                dp[i][j] = true;
            else if(i==0)
                dp[i][j] = false;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=su;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            else 
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][su] << endl;

}