#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int factorial(int n)
{
    return (n == 0 || n == 1) ? (1) : (factorial(n - 1) * n);
}

int main()
{
    int n, k;
    cin >> n >> k;

    cout << factorial(n) / (factorial(n - k) * factorial(k)) << endl;

    return 0;
}