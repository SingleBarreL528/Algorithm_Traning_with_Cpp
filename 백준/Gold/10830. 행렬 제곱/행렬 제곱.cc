#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int N;
long long B;
int A[5][5] = {0};
int A_1[5][5] = {0};

void mul_matrix(int a[5][5], int b[5][5])
{
    int temp[5][5] = {0};

    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                temp[i][k] += a[i][j] * b[j][k];
            }
            temp[i][k] %= 1000;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            a[i][j] = temp[i][j];
        }
    }
}

void pow_matrix(int a[5][5], long long exp, int n)
{
    if (exp == 1)
    {
        return;
    }
    else
    {
        pow_matrix(a, exp / 2, n);

        mul_matrix(a, a);
        if (exp % 2 == 1)
        {
            mul_matrix(a, A_1);
        }
    }
}

int main()
{

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

    pow_matrix(A, B, N);

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
