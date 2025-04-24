#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &v, long long min, long long max, int val)
{
    if (min == max)
    {
        return min - 1;
    }
    else
    {
        long long mid = (min + max) / 2;
        int cnt = 0;
        for (auto &i : v)
        {
            cnt += i / mid;
        }

        if (cnt < val)
        {
            return search(v, min, mid, val);
        }
        else
        {
            return search(v, mid + 1, max, val);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    long long min = 1, max;
    int temp;
    vector<int> v;

    cin >> K >> N;
    for (int i = 0; i < K; ++i)
    {
        cin >> temp;
        v.push_back(temp);
    }
    max = (long long)*max_element(v.begin(), v.end()) + 1;

    cout << search(v, min, max, N);

    return 0;
}