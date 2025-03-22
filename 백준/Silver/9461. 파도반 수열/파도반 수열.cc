#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int N;
    long long arr[101] = {0};
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;
    int floor = 5;

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> N;

        if (N <= floor)
        {
            cout << arr[N] << "\n";
        }
        else
        {
            floor = N;
            for (int j = 6; j <= N; ++j)
            {
                arr[j] = arr[j - 1] + arr[j - 5];
            }
            cout << arr[N] << "\n";
        }
    }

    return 0;
}