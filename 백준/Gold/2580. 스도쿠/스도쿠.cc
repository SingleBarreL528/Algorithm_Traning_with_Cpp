#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
int sudoku[9][9] = {0};
bool flag = false;
vector<pair<int, int>> zero_coords;

void print()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}

bool check(int row, int col)
{
    for (int i = 0; i < 9; ++i)
    {
        if ((sudoku[row][i] == sudoku[row][col]) && (i != col))
        {
            return false;
        }
        if ((sudoku[i][col] == sudoku[row][col]) && (i != row))
        {
            return false;
        }
    }

    int row_t = row - row % 3;
    int col_t = col - col % 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if ((sudoku[row_t + i][col_t + j] == sudoku[row][col]) && (row_t + i != row) && (col_t + j != col))
            {
                return false;
            }
        }
    }

    return true;
}

void solve_sudoku(int cnt)
{
    if (cnt == zero_coords.size())
    {
        print();
        flag = true;
        return;
    }

    pair<int, int> coord = zero_coords[cnt];

    for (int i = 1; i <= 9; ++i)
    {
        sudoku[coord.first][coord.second] = i;

        if (check(coord.first, coord.second) == true)
        {
            solve_sudoku(cnt + 1);
        }

        if (flag == true)
        {
            return;
        }
    }

    sudoku[coord.first][coord.second] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> sudoku[i][j];
            cnt++;
            if (sudoku[i][j] == 0)
            {
                zero_coords.push_back(make_pair(i, j));
            }
        }
    }

    n = 0;
    solve_sudoku(n);

    return 0;
}