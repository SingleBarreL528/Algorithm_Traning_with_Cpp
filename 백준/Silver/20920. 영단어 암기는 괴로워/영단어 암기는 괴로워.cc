#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool comp(pair<string, int> &a, pair<string, int> &b)
{
    if (a.second != b.second)
    {
        return a.second >= b.second;
    }
    else
    {
        if (a.first.length() != b.first.length())
        {
            return a.first.length() > b.first.length();
        }
        else
        {
            return a.first < b.first;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string word;
    map<string, int> word_list_map;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> word;
        if (word.length() >= m)
        {
            word_list_map[word]++;
        }
    }

    vector<pair<string, int>> word_list_vec(word_list_map.begin(), word_list_map.end());
    sort(word_list_vec.begin(), word_list_vec.end(), comp);

    for (auto iter = word_list_vec.begin(); iter != word_list_vec.end(); ++iter)
    {
        cout << (*iter).first << "\n";
    }

    return 0;
}