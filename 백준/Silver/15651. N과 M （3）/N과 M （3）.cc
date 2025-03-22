#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int> set, int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        set.push_back(i);

        if (set.size() == m)
        {
            for (auto iter = set.begin(); iter != set.end(); ++iter)
            {
                cout << *iter << " ";
            }
            cout << "\n";
        }
        else
        {
            backtrack(set, n, m);
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

    backtrack(set, n, m);

    return 0;
}