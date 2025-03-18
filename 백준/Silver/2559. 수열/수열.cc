#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> psum(n + 1, 0);
    int max = INT_MIN;

    for (int idx = 1; idx <= n; ++idx)
    {
        cin >> psum[idx];
        psum[idx] += psum[idx - 1];

        if (idx >= k)
        {
            int temp = psum[idx] - psum[idx - k];
            if (temp > max) max = temp;
        }
    }

    cout << max;

    return 0;
}