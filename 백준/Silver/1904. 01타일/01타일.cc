#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

array<int, 1000001> a = {};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    a[0] = 1;
    a[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        a[i] = a[i - 1] + a[i - 2];
        a[i] %= 15746;
    }

    cout << a[N];

    return 0;
}