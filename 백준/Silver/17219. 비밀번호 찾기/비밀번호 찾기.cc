#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string site, password;
    unordered_map<string, string> memo;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> site >> password;
        memo[site] = password;
    }
    for (int j = 0; j < m; ++j)
    {
        cin >> site;
        cout << memo[site] << "\n";
    }

    return 0;
}