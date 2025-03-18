#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int psum[n + 1] = {0};

    for (int idx = 1; idx <= n; ++idx)
    {
        cin >> psum[idx];
        psum[idx] += psum[idx - 1];
    }

    while (m--)
    {
        int i, j;
        cin >> i >> j;

        cout << (psum[j] - psum[i - 1]) << "\n";
    }

    return 0;
}