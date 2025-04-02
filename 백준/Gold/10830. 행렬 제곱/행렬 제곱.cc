#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

typedef array<array<int, 5>, 5> matrix_t;

void mul_matrix(matrix_t &a, matrix_t &b, int n)
{
    matrix_t temp = {0};

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temp[i][k] += a[i][j] * b[j][k];
            }
            temp[i][k] %= 1000;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            a[i][j] = temp[i][j];
        }
    }
}

void pow_matrix(matrix_t &a, matrix_t &a_1, long long exp, int n)
{
    if (exp == 1)
    {
        return;
    }
    else
    {
        pow_matrix(a, a_1, exp / 2, n);

        mul_matrix(a, a, n);
        if (exp % 2 == 1)
        {
            mul_matrix(a, a_1, n);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    long long B;
    matrix_t A = {0};
    matrix_t A_1 = {0};

    cin >> N >> B;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
            A[i][j] %= 1000;
            A_1[i][j] = A[i][j];
        }
    }

    pow_matrix(A, A_1, B, N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
