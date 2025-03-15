#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// cin.tie(NULL)과 sync_with_stdio(false)를 둘 다 적용해 주고, endl 대신 개행문자(\n)

using namespace std;

void print(vector<int> set)
{
    for (auto iter = set.begin(); iter != set.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << "\n";
}

void backtrack(vector<int> &num, vector<int> &set, int &m)
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
            set.push_back(i + 1);
            m -= 1;

            if (m != 0)
            {
                backtrack(num, set, m);
            }
            else
            {
                for (auto iter = set.begin(); iter != set.end(); ++iter)
                {
                    cout << *iter << " ";
                }
                cout << "\n";
            }

            num.at(i) = 0;
            set.pop_back();
            m += 1;
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
    vector<int> set;
    backtrack(num, set, m);
}