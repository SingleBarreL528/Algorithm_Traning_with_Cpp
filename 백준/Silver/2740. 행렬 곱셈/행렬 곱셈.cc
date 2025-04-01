#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int A[100][100] = {0};
int B[100][100] = {0};
int C[100][100] = {0};

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> A[i][j];
        }
    }

    cin >> M >> K;
    for (int j = 0; j < M; ++j)
    {
        for (int k = 0; k < K; ++k)
        {
            cin >> B[j][k];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            for (int k = 0; k < K; ++k)
            {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}