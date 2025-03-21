#include <algorithm>
#include <iostream>
#include <vector>

// cin.tie(NULL)과 sync_with_stdio(false)를 둘 다 적용해 주고, endl 대신 개행문자(\n)

using namespace std;

void backtrack(vector<int> &num, vector<int> &perm, int m)
{
    for (int i = 0; i < num.size(); ++i)
    {
        if (num.at(i) == 1)
        {
            continue;
        }
        else
        {
            num.at(i) = 1;
            perm.push_back(i + 1);

            if (perm.size() != m)
            {
                backtrack(num, perm, m);
            }
            else
            {
                for (auto iter = perm.begin(); iter != perm.end(); ++iter)
                {
                    cout << *iter << " ";
                }
                cout << "\n";
            }

            num.at(i) = 0;
            perm.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> num(n, 0);
    vector<int> perm;

    backtrack(num, perm, m);

    return 0;
}