#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int data_arr[129][129] = {0};
char temp[65];

void comp_data(int row, int col, int len)
{
    int val = data_arr[row][col];

    for (int i = row; i < row + len; ++i)
    {
        for (int j = col; j < col + len; ++j)
        {
            if (data_arr[i][j] != val)
            {
                len /= 2;

                cout << "(";
                comp_data(row, col, len);
                comp_data(row, col + len, len);
                comp_data(row + len, col, len);
                comp_data(row + len, col + len, len);
                cout << ")";

                return;
            }
        }
    }

    if (val == 1)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int row = 1; row <= n; ++row)
    {
        cin >> temp;
        for (int col = 1; col <= n; ++col)
        {
            data_arr[row][col] = (temp[col - 1] - '0');
        }
    }

    comp_data(1, 1, n);

    return 0;
}