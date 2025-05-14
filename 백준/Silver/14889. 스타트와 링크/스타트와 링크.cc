#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
int min_res = 0x7fffffff;
array<int, 20> check = {};
vector<int> team_start;
array<array<int, 20>, 20> stat;

int calc_stat(vector<int> &team)
{
    int sum = 0;
    for (int i = 0; i < team.size(); ++i)
    {
        for (int j = 0; j < team.size(); ++j)
        {
            sum += stat[team[i]][team[j]];
        }
    }

    return sum;
}

void search()
{
    if (team_start.size() == n / 2)
    {
        vector<int> team_link;
        for (int i = 0; i < n; ++i)
        {
            if (check[i] == 0)
            {
                team_link.push_back(i);
            }
        }

        int res = abs(calc_stat(team_start) - calc_stat(team_link));

        if (res < min_res)
        {
            min_res = res;
        }
    }
    else
    {
        for (int i = (team_start.size() == 0) ? 0 : team_start.back(); i < n; ++i)
        {
            if (check[i] == 0)
            {
                team_start.push_back(i);
                check[i] = 1;

                search();

                team_start.pop_back();
                check[i] = 0;
            }
            else
            {
                continue;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> stat[i][j];
        }
    }

    search();

    cout << min_res;

    return 0;
}