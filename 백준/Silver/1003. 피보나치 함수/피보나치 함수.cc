#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

array<array<long long, 2>, 41> dp;

void fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    else
    {
        if (dp[n - 1][0] == 0 && dp[n - 1][1] == 0)
        {
            fibonacci(n - 1);
        }
        if (dp[n - 2][0] == 0 && dp[n - 2][1] == 0)
        {
            fibonacci(n - 2);
        }
        dp[n][0] = dp[n - 1][0] + dp[n - 2][0];
        dp[n][1] = dp[n - 1][1] + dp[n - 2][1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    dp[0][0] = 1;
    dp[1][1] = 1;

    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        fibonacci(n);

        cout << dp[n][0] << " " << dp[n][1] << "\n";
    }

    return 0;
}