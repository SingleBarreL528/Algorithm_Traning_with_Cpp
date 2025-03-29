#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int a, b, c;

long long power_nat(int a, int b, int c)
{
    if (b == 1)
    {
        return a % c;
    }
    else if (b % 2 == 0)
    {
        return ((power_nat(a, b / 2, c)) * power_nat(a, b / 2, c)) % c;
    }
    else
    {
        return ((power_nat(a, b / 2, c)) * power_nat(a, b / 2 + 1, c)) % c;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << power_nat(a, b, c);

    return 0;
}