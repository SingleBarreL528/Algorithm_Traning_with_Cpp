#include <climits>
#include <iostream>

using namespace std;

int n;
int tri[501][501] = {0};
int dp[501][501] = {0};
int max_val = INT_MIN;

int comp(int a, int b)
{
    return (a > b) ? a : b;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int row = 1; row <= n; ++row)
    {
        for (int col = 1; col <= row; ++col)
        {
            cin >> tri[row][col];
            dp[row][col] = comp(tri[row][col] + dp[row - 1][col - 1], tri[row][col] + dp[row - 1][col]);
            if (dp[row][col] > max_val)
            {
                max_val = dp[row][col];
            }
        }
    }

    cout << max_val;

    return 0;
}