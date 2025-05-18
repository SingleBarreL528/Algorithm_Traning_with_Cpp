#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

void search(int &n, array<int, 12> &dp)
{
    if (dp[n] != 0)
    {
        cout << dp[n] << "\n";
    }
    else
    {
        for (int i = 4; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        cout << dp[n] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n;
    array<int, 12> dp = {};

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        search(n, dp);
    }

    return 0;
}