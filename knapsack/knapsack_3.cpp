#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int knapsack(int n,int wt[],int val[],int W)
{
    if(n==0 || W==0)
    {
        return 0;
    }
    int ans = 0;
    if(wt[n-1]<=W)
    {
        ans = max(val[n-1]+knapsack(n-1,wt,val,W-wt[n-1]),knapsack(n-1,wt,val,W));
    }
    else
        return knapsack(n-1,wt,val,W);
}

void solve()
{
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};

    int W=7;

    cout << knapsack(4,wt,val,W) << endl;
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
