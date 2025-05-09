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
    int inp;
    array<int, 1001> arr;
    array<int, 1001> dp = {};

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[j], dp[i]);
            }
        }
        ++dp[i];
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}