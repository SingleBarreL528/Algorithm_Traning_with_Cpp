#include <algorithm>
#include <iostream>

int n;
int cnt = 0;
int board[15] = {0};

using namespace std;

bool check(int check_idx)
{
    for (int i = 1; i <= n; ++i)
    {
        // 체크 idx 본인을 제외한, 퀸이 놓여있는 col을 대상으로
        if ((board[i] != 0) && (i != check_idx))
        {
            // 대각선 중복 체크
            if (abs(i - check_idx) == abs(board[i] - board[check_idx]))
            {
                return false;
            }
        }
    }
    return true;
}

void search(int row)
{
    if (row > n)
    {
        ++cnt;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (board[i] == 0)
            {
                board[i] = row;

                if (check(i) == true)
                {
                    // 다음 row로 이동 -> row 중복 발생 X
                    search(row + 1);
                }

                board[i] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    search(1);

    cout << cnt;

    return 0;
}