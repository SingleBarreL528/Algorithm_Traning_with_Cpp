#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

long long cnt_less(long long val, long long N)
{
    long long cnt = 0;

    for (int i = 1; i <= N; ++i)
    {
        cnt += min(N, val / i);
    }

    return cnt;
}

long long search(long long min, long long max, long long n, long long key)
{
    while (min < max)
    {
        long long mid = (min + max) / 2;
        long long cnt = cnt_less(mid, n);
        if (cnt < key)
        {
            min = mid + 1;
        }
        else
        {
            max = mid;
        }
    }

    return min;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, k;

    cin >> N >> k;

    cout << search(0, N * N + 1, N, k);

    return 0;
}