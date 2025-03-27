#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int n;

unsigned long long factorial(int num)
{
    if ((num == 1) || (num == 0))
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout << factorial(n);

    return 0;
}