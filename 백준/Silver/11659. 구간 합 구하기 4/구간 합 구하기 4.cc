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
    int arr[n + 1] = {0};
    int psum[n + 1] = {0};

    for (int idx = 1; idx <= n; ++idx)
    {
        cin >> arr[idx];
        psum[idx] = psum[idx - 1] + arr[idx];
    }

    while (m--)
    {
        int i, j;
        cin >> i >> j;

        int sum = psum[j] - psum[i - 1];
        cout << sum << "\n";
    }

    return 0;
}