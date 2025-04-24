#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int cut(vector<int> &v, int min, int max, int &val)
{
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        long long sum = 0;

        for (auto i : v)
        {
            if (i > mid)
            {
                sum += i - mid;
            }
        }

        if (sum >= val)
        {
            min = mid + 1;
        }
        else
        {
            max = mid;
        }
    }

    return min - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int max = 0, min = 0;
    int temp;
    vector<int> v;

    cin >> N >> M; // 1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000
    for (int i = 0; i < N; ++i)
    {
        cin >> temp; // temp <= 1,000,000,000
        v.push_back(temp);
        if (max < temp)
        {
            max = temp;
        }
    }

    cout << cut(v, min, ++max, M);

    return 0;
}