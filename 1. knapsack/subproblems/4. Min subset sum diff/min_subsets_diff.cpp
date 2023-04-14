#include<bits/stdc++.h>
using namespace std;

int t[103][100005];
bool dp[103][100005];
int fun(int n,int arr[],int s1,int s2)
{
    if(n==0)
    {
        return (abs(s1-s2));
    }
    if(t[n][s1]!=-1)
        return t[n][s1];
    int ans = 0;
    ans = min(fun(n-1,arr,s1+arr[n-1],s2-arr[n-1]),fun(n-1,arr,s1,s2));
    t[n][s1] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int arr[] = {1,5,6,11};
    int n = 4;
    int mi = INT_MAX,su=0;
    for(auto x:arr)
        su+=x;

    memset(t,-1,sizeof(t));
    cout << "recursion: " << fun(n,arr,0,su) << endl;

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
        for(int j=0;j<=su;j++)
        {
            if(arr[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    for(int j=0;j<=(su/2);j++)
    {
        if(dp[n][j])
        {
            mi = min(su-(2*j),mi);
        }
    }

    cout << mi << endl; 
    

}