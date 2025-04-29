#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int cnt_wifi(vector<int> &v, int dist)
{
    int cnt = 1;
    int start = v.front();
    int end;
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
        end = *iter;
        if (end - start >= dist)
        {
            start = end;
            ++cnt;
        }
    }

    return cnt;
}

int search(vector<int> &v, int min, int max, int val)
{
    while (min < max)
    {
        int mid = (min + max) / 2;

        int cnt = cnt_wifi(v, mid);
        if (cnt < val)
        {
            max = mid;
        }
        else
        {
            min = mid + 1;
        }
    }

    return min - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    vector<int> v;

    cin >> N >> C;
    for (int i = 0; i < N; ++i)
    {
        v.emplace_back();
        cin >> v.back();
    }
    sort(v.begin(), v.end());

    cout << search(v, 0, v.back() + 1, C);

    return 0;
}