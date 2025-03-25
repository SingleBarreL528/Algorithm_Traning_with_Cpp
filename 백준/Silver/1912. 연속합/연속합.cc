#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int dp[100001] = {0};
int max_val = -100000000;

int comp(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> dp[i];
        dp[i] = comp(dp[i - 1] + dp[i], dp[i]);
        max_val = comp(dp[i], max_val);
    }

    cout << max_val;

    return 0;
}