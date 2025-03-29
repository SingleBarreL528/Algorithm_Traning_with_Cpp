#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int temp;
vector<int> arr;
vector<int> cnt;
vector<int> seq;

void backtrack()
{
    if (seq.size() == m)
    {
        for (auto iter = seq.begin(); iter != seq.end(); ++iter)
        {
            cout << *iter << " ";
        }
        cout << "\n";
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (cnt[i] == 0)
            {
                cnt[i] = 1;
                seq.push_back(arr[i]);

                backtrack();

                cnt[i] = 0;
                seq.pop_back();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.resize(n);
    cnt.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    backtrack();

    return 0;
}