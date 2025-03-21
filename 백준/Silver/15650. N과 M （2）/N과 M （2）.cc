#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void backtrack(vector<int> &comb, int m, int min, int max)
{
    for (int idx = min; idx <= max; ++idx)
    {
        comb.push_back(idx);

        if (comb.size() == m)
        {
            for (auto iter = comb.begin(); iter != comb.end(); ++iter)
            {
                cout << *iter << " ";
            }
            cout << "\n";
        }
        else
        {
            backtrack(comb, m, ++min, max);
        }

        comb.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> comb;

    backtrack(comb, m, 1, n);

    return 0;
}