#include <iostream>
#include <vector>

using namespace std;

// (PrefixSum[j] - PrefixSum[i]) % MOD = 0
// (PrefixSum[j] % MOD - PrefixSum[i] % MOD) % MOD = 0
// PrefixSum[j] % MOD = PrefixSum[i] % MOD

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<long long> psum(n + 1, 0);
    vector<long long> cnt_rem(m, 0);
    long long result = 0;

    for (int idx = 1; idx <= n; ++idx)
    {
        cin >> psum[idx];
        psum[idx] = (psum[idx] % m + psum[idx - 1]) % m;
        if (psum[idx] == 0)
        {
            ++result;
        }
        ++cnt_rem[psum[idx]];
    }

    for (int idx = 0; idx < m; ++idx)
    {
        result += (cnt_rem[idx] * (cnt_rem[idx] - 1)) / 2;
    }

    cout << result;

    return 0;
}