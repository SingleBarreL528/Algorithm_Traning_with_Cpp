#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(vector<int> set)
{
    for (int i = 0; i < (set.size() - 1); ++i)
    {
        if (set.at(i) > set.at(i + 1))
        {
            return false;
        }
    }
    return true;
}

void backtrack(vector<int> set, int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        set.push_back(i);

        if (set.size() != m)
        {
            backtrack(set, n, m);
        }
        else
        {
            if (comp(set) == true)
            {
                for (auto iter = set.begin(); iter != set.end(); ++iter)
                {
                    cout << *iter << " ";
                }
                cout << "\n";
            }
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