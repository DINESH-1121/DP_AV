#include <bits/stdc++.h>
using namespace std;

int rodCutting(int length[], int size, int profit[], int N)
{
    // Step 1: Initialization
    int t[size + 1][N + 1];
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            if (j == 0)
                t[i][j] = 0;
            else if (i == 0)
                t[i][j] = profit[i - 1];
        }
    }

    // Step 2: Iterative code
    for (int i = 1; i < size + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if (length[i - 1] <= j)
                t[i][j] = max(profit[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }

    // Step 3: Return
    return t[size][N];
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
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int profit[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(length) / sizeof(length[0]);
    int N = 8;

    int maxProfit = rodCutting(length, size, profit, N);
    cout << "The profit will be " << maxProfit << endl;
}