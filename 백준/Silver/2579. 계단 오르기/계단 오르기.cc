#include <iostream>

using namespace std;

int n;
int num;
int point_dp[301][3] = {0};
int point_max[301] = {0};

int comp(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cin >> point_dp[1][1];
    point_max[1] = point_dp[1][1];
    for (int i = 2; i <= n; ++i)
    {
        cin >> num;
        point_dp[i][1] = point_max[i - 2] + num;
        point_dp[i][2] = point_dp[i - 1][1] + num;
        point_max[i] = comp(point_dp[i][1], point_dp[i][2]);
    }

    cout << point_max[n];

    return 0;
}