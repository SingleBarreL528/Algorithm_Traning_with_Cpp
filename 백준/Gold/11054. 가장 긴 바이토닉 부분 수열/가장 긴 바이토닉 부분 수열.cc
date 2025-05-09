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
    int res = 0;
    array<int, 1001> arr;
    array<int, 1001> dp_inc = {};
    array<int, 1001> dp_dec = {};

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];

        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                dp_inc[i] = max(dp_inc[j], dp_inc[i]);
            }
        }
        ++dp_inc[i];
    }

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (arr[j] < arr[i])
            {
                dp_dec[i] = max(dp_dec[j], dp_dec[i]);
            }
        }
        ++dp_dec[i];

        res = max(res, dp_inc[i] + dp_dec[i] - 1);
    }

    cout << res;

    return 0;
}