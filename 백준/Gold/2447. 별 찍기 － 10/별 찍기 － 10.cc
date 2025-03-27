#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int n;
array<array<char, 6562>, 6562> arr = {};

void recur(int row, int col, int len, char c)
{
    if (len == 1)
    {
        arr[row][col] = c;
    }
    else
    {
        len = len / 3;

        recur(row, col, len, c);
        recur(row, col + len, len, c);
        recur(row, col + len * 2, len, c);

        recur(row + len, col, len, c);
        recur(row + len, col + len, len, ' ');
        recur(row + len, col + len * 2, len, c);

        recur(row + len * 2, col, len, c);
        recur(row + len * 2, col + len, len, c);
        recur(row + len * 2, col + len * 2, len, c);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    recur(1, 1, n, '*');

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << arr[i][j];
        }
        cout << "\n";
    }

    return 0;
}