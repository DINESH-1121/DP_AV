#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
vector<vector<char>> gr;
vector<vector<bool>> vis;

int dfs(int i,int j,int n,int m)
{
    cout << "dines fn" << endl;

    if(i<0 || j<0 || i>=n ||j>=m)
        return 0;
    if(gr[i][j]=='*')
        return 1;
    
    ll ans = 0;
    ans+=dfs(i+1,j,n,m);
    ans+=dfs(i-1,j,n,m);
    ans+=dfs(i,j+1,n,m);
    ans+=dfs(i,j-1,n,m);

    return ans;
}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    cout << "dines"<<n<<m << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            cin >>gr[i][j];
            cout<<gr[i][j];
            vis[i][j] = -1;
        }
        cout<<endl;
    }

    while(k--)
    {
        int i1,j1;
        cin >> i1>> j1;
        cout <<i1 << " " << j1 << endl;

        i1--,j1--;

        cout << dfs(i1,j1,n,m) << endl;
    }

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
