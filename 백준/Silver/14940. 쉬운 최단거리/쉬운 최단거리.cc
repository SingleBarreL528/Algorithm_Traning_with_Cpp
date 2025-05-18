#include <algorithm>
#include <array>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;
typedef array<array<int, 1000>, 1000> array_2d;

array_2d map;
array_2d route = {};

void search_route(pair<int, int> state, int n, int m)
{
    deque<pair<int, int>> queue_state;
    queue_state.push_back(state);
    while (queue_state.size() != 0)
    {
        pair<int, int> top = queue_state.front();
        queue_state.pop_front();
        if ((top.first + 1 < n) && (route[top.first + 1][top.second] == -1) && (map[top.first + 1][top.second] != 0))
        {
            route[top.first + 1][top.second] = route[top.first][top.second] + 1;
            queue_state.push_back(make_pair(top.first + 1, top.second));
        }
        if ((top.second + 1 < m) && (route[top.first][top.second + 1] == -1) && (map[top.first][top.second + 1] != 0))
        {
            route[top.first][top.second + 1] = route[top.first][top.second] + 1;
            queue_state.push_back(make_pair(top.first, top.second + 1));
        }
        if ((top.first - 1 >= 0) && (route[top.first - 1][top.second] == -1) && (map[top.first - 1][top.second] != 0))
        {
            route[top.first - 1][top.second] = route[top.first][top.second] + 1;
            queue_state.push_back(make_pair(top.first - 1, top.second));
        }
        if ((top.second - 1 >= 0) && (route[top.first][top.second - 1] == -1) && (map[top.first][top.second - 1] != 0))
        {
            route[top.first][top.second - 1] = route[top.first][top.second] + 1;
            queue_state.push_back(make_pair(top.first, top.second - 1));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    pair<int, int> first_state;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> map[i][j];
            route[i][j] = -1;
            if (map[i][j] == 2)
            {
                first_state = make_pair(i, j);
                route[i][j] = 0;
            }
            else if (map[i][j] == 0)
            {
                route[i][j] = 0;
            }
        }
    }

    search_route(first_state, n, m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << route[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}