#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
int time_end = 0;
vector<pair<int, int>> schedule;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int s, e;
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> e;
        schedule.push_back(make_pair(s, e));
    }

    sort(schedule.begin(), schedule.end(), cmp);

    for (int i = 0; i < n; ++i)
    {
        if (time_end <= schedule[i].first)
        {
            time_end = schedule[i].second;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}