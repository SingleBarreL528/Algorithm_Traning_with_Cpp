#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
typedef array<array<long long, 2>, 2> matrix_t;

matrix_t mul_matrix(matrix_t &a, matrix_t &b)
{
    matrix_t c = {};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= 1000000007;
            }
        }
    }

    return c;
}

matrix_t pow_matrix(matrix_t &a, long long exp)
{
    matrix_t res = {{{1, 0}, {0, 1}}};
    matrix_t base = a;

    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            res = mul_matrix(res, base);
        }
        base = mul_matrix(base, base);
        exp /= 2;
    }

    return res;
}

int cal_fibo(long long n)
{
    matrix_t a = {{{1, 1}, {1, 0}}};
    matrix_t res = pow_matrix(a, n - 1);

    return res[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    cout << cal_fibo(N);

    return 0;
}