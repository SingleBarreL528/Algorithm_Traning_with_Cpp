#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

#define RED 0
#define GREEN 1
#define BLUE 2

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    array<array<int, 3>, 1001> dp;
    array<int, 3> cost;

    cin >> N;
    cin >> dp[1][0] >> dp[1][1] >> dp[1][2];
    for (int i = 2; i <= N; ++i)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[2];
    }

    int res = 1000000;
    for (int i = 0; i < 3; ++i)
    {
        if (dp[N][i] < res)
        {
            res = dp[N][i];
        }
    }

    cout << res;

    return 0;
}