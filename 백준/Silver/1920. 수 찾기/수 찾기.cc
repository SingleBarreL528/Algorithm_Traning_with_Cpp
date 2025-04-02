#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> &arr, int &target, int idx_start, int idx_end)
{
    int idx_mid = (idx_start + idx_end) / 2;
    if (arr[idx_mid] == target)
    {
        return 1;
    }
    else if (idx_end - idx_start <= 1)
    {
        return 0;
    }
    else
    {
        if (arr[idx_mid] > target)
        {
            return find(arr, target, idx_start, idx_mid);
        }
        else
        {
            return find(arr, target, idx_mid, idx_end);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<int> arr;
    int M;
    int temp;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> temp;
        cout << find(arr, temp, 0, N) << "\n";
    }

    return 0;
}
