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

    int n;
    int inp, temp;
    array<array<int, 3>, 10001> dp = {};

    cin >> n;
    cin >> dp[1][1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> inp;
        dp[i][2] = dp[i - 1][1] + inp;
        dp[i][1] = dp[i - 1][0] + inp;
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
    }

    int max = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (dp[n][i] > max)
        {
            max = dp[n][i];
        }
    }

    cout << max;

    return 0;
}