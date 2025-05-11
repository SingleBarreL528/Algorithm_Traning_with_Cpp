#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct word_st
{
    int cnt;
    string s;

    bool operator<(const word_st &other) const
    {
        if (cnt != other.cnt) return cnt > other.cnt;
        if (s.length() != other.s.length()) return s.length() > other.s.length();
        return s < other.s;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string str;
    unordered_map<string, int> word_frep;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        if (str.length() >= m)
        {
            word_frep[str]++;
        }
    }

    vector<word_st> word_list;
    for (auto i : word_frep)
    {
        word_st word;
        word.s = i.first;
        word.cnt = i.second;
        word_list.push_back(word);
    }
    sort(word_list.begin(), word_list.end());

    for (auto i : word_list)
    {
        cout << i.s << "\n";
    }

    return 0;
}