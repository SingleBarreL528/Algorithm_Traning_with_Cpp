#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string name;
    vector<string> no_heard;
    vector<string> no_seen;
    vector<string> no_heard_seen;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        no_heard.emplace_back();
        cin >> no_heard.back();
    }
    for (int i = 0; i < m; ++i)
    {
        no_seen.emplace_back();
        cin >> no_seen.back();
    }

    sort(no_heard.begin(), no_heard.end());
    sort(no_seen.begin(), no_seen.end());

    auto iter_heard = no_heard.begin();
    auto iter_seen = no_seen.begin();

    while ((iter_heard != no_heard.end()) && (iter_seen != no_seen.end()))
    {
        if (*iter_heard == *iter_seen)
        {
            no_heard_seen.push_back(*iter_heard);
            ++iter_heard;
        }
        else
        {
            if (*iter_heard < *iter_seen)
            {
                ++iter_heard;
            }
            else
            {
                ++iter_seen;
            }
        }
    }

    cout << no_heard_seen.size() << "\n";
    for (auto s : no_heard_seen)
    {
        cout << s << "\n";
    }

    return 0;
}