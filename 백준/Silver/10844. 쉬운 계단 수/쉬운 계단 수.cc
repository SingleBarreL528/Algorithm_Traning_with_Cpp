#include <algorithm>
#include <iostream>

using namespace std;

int n;
int res = 0;
int arr[10][101] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= 9; ++i)
    {
        arr[i][1] = 1;
    }
    for (int col = 2; col <= n; ++col)
    {
        arr[0][col] = arr[1][col - 1];
        for (int row = 1; row <= 8; ++row)
        {
            arr[row][col] = ((arr[row - 1][col - 1]) + (arr[row + 1][col - 1])) % 1000000000;
        }
        arr[9][col] = arr[8][col - 1];
    }
    
    for (int row = 0; row <= 9; ++row)
    {
        res += arr[row][n];
        res %= 1000000000;
    }
    cout << res;

    return 0;
}