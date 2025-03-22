#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    int q;
    char a;
    int l, r;
    int arr[26][2000];

    cin >> s;

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < s.length(); ++j)
        {
            if (j > 0)
            {
                arr[i][j] = arr[i][j - 1];
            }
            if (s.at(j) == 'a' + i)
            {
                ++arr[i][j];
            }
        }
    }

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> a >> l >> r;
        cout << arr[a - 'a'][r] - arr[a - 'a'][l - 1] << "\n";
    }

    return 0;
}