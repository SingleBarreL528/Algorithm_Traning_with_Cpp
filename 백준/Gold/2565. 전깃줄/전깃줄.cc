#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a, b;
    int m = 0;
    vector<pair<int, int>> arr;
    array<int, 100> dp = {};

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j].second < arr[i].second)
            {
                dp[i] = max(dp[j], dp[i]);
            }
        }
        ++dp[i];

        m = max(m, dp[i]);
    }

    cout << n - m;

    return 0;
}