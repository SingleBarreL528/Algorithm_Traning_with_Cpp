#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string s;
int q;
char a;
int l, r;
int arr[26][200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < 26; ++i)
    {
        arr[i][0] = 0;
        for (int j = 1; j <= s.length(); ++j)
        {
            arr[i][j] = arr[i][j - 1];
            if (s.at(j - 1) == 'a' + i)
            {
                ++arr[i][j];
            }
        }
    }

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        cin >> a >> l >> r;
        cout << arr[a - 'a'][r + 1] - arr[a - 'a'][l] << "\n";
    }

    return 0;
}