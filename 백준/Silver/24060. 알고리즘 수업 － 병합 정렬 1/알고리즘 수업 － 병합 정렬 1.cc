#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void counting(int num);
void merge_sort(vector<int> &A, vector<int> &B, int p, int r);
void merge(vector<int> &A, vector<int> &B, int p, int q, int r);

int n, k;
int cnt = 0;
int answer = -1;

void counting(int num)
{
    ++cnt;
    if (cnt == k)
    {
        answer = num;
    }
}

void merge_sort(vector<int> &A, vector<int> &B, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, B, p, q);
        merge_sort(A, B, q + 1, r);
        merge(A, B, p, q, r);
    }
}

void merge(vector<int> &A, vector<int> &B, int p, int q, int r)
{
    int i = p;
    int j = q + 1;
    int t = p;

    for (int i = p; i <= r; ++i)
    {
        B[i] = A[i];
    }

    while ((i <= q) && (j <= r))
    {
        if (B[i] <= B[j])
        {
            A[t] = B[i++];
            counting(A[t++]);
        }
        else
        {
            A[t] = B[j++];
            counting(A[t++]);
        }
    }

    while (i <= q)
    {
        A[t] = B[i++];
        counting(A[t++]);
    }
    while (j <= r)
    {
        A[t] = B[j++];
        counting(A[t++]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<int> A;
    vector<int> B(n, 0);

    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    merge_sort(A, B, 0, n - 1);
    cout << answer;

    return 0;
}