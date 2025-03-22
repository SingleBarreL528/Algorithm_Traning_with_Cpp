#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int> set, int m, int min, int max)
{
    for (int i = min; i <= max; ++i)
    {
        set.push_back(i);

        if (set.size() != m)
        {
            backtrack(set, m, i, max);
        }
        else
        {
            for (auto iter = set.begin(); iter != set.end(); ++iter)
            {
                cout << *iter << " ";
            }
            cout << "\n";
        }

        set.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> set;

    backtrack(set, m, 1, n);

    return 0;
}