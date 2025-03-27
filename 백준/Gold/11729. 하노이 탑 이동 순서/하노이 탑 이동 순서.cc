#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int n;

int pow_cal(int base, int n)
{
    if (n == 1)
    {
        return base;
    }
    else
    {
        return base * pow_cal(base, n - 1);
    }
}

void hanoi(int from, int to, int oth, int plate)
{
    if (plate == 1)
    {
        cout << from << " " << to << "\n";
    }
    else
    {
        hanoi(from, oth, to, plate - 1);
        cout << from << " " << to << "\n";
        hanoi(oth, to, from, plate - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout << pow_cal(2, n) - 1 << "\n";
    hanoi(1, 3, 2, n);

    return 0;
}