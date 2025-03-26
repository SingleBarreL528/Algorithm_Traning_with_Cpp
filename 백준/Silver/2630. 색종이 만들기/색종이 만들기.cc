#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int white_paper = 0;
int blue_paper = 0;
int paper[129][129] = {0};

void make_paper(int row, int col, int len)
{
    int val = paper[row][col];

    for (int i = row; i < row + len; ++i)
    {
        for (int j = col; j < col + len; ++j)
        {
            if (paper[i][j] != val)
            {
                len /= 2;
                make_paper(row, col, len);
                make_paper(row + len, col, len);
                make_paper(row, col + len, len);
                make_paper(row + len, col + len, len);

                return;
            }
        }
    }

    switch (val)
    {
    case 1:
        ++blue_paper;
        break;
    case 0:
        ++white_paper;
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int row = 1; row <= n; ++row)
    {
        for (int col = 1; col <= n; ++col)
        {
            cin >> paper[row][col];
        }
    }

    make_paper(1, 1, n);

    cout << white_paper << "\n" << blue_paper;

    return 0;
}