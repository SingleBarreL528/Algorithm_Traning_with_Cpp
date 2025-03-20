#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int cnt_code1 = 0;
int cnt_code2 = 0;
vector<int> arr(41, 1);

int fibo_code1(int n)
{
    if (n == 1 || n == 2)
    {
        ++cnt_code1;
        return 1;
    }
    else
    {
        return fibo_code1(n - 1) + fibo_code1(n - 2);
    }
}

int fibo_code2(int n)
{
    for (int i = 3; i <= n; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        ++cnt_code2;
    }
    return arr[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    fibo_code1(n);
    fibo_code2(n);
    // cout << fibo_code1(n) << " " << fibo_code2(n) << endl;
    cout << cnt_code1 << " " << cnt_code2;

    return 0;
}