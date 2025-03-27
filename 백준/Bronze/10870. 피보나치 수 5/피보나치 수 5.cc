#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int n;
array<int, 21> a = {0};

int fibo(int num)
{
    if ((num == 1) || (num == 0))
    {
        return num;
    }
    else
    {
        return fibo(num - 1) + fibo(num - 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout << fibo(n);

    return 0;
}