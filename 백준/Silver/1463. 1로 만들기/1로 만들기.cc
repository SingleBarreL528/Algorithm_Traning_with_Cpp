#include <algorithm>
#include <iostream>

using namespace std;

int n;
int dp[1000001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0)
        {
            if (dp[i] == 0)
            {
                dp[i] = dp[i / 2] + 1;
            }
            else
            {
                dp[i] = min(dp[i], dp[i / 2] + 1);
            }
        }

        if (i % 3 == 0)
        {
            if (dp[i] == 0)
            {
                dp[i] = dp[i / 3] + 1;
            }
            else
            {
                dp[i] = min(dp[i], dp[i / 3] + 1);
            }
        }
    }
    cout << dp[n];

    return 0;
}