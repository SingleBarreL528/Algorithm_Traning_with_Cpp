#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
int min_res = 0x7fffffff;
int max_res = 0x80000000;
int plus_cnt, minus_cnt, mul_cnt, div_cnt;
vector<int> operand_t;

void search(int idx, int res, int plus, int minus, int mul, int div)
{
    if (idx == n)
    {
        min_res = min(res, min_res);
        max_res = max(res, max_res);
    }
    else
    {
        if (plus > 0)
        {
            search(idx + 1, res + operand_t[idx], plus - 1, minus, mul, div);
        }
        if (minus > 0)
        {
            search(idx + 1, res - operand_t[idx], plus, minus - 1, mul, div);
        }
        if (mul > 0)
        {
            search(idx + 1, res * operand_t[idx], plus, minus, mul - 1, div);
        }
        if (div > 0)
        {
            search(idx + 1, res / operand_t[idx], plus, minus, mul, div - 1);
        }
    }
}

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        operand_t.emplace_back();
        cin >> operand_t.back();
    }
    cin >> plus_cnt >> minus_cnt >> mul_cnt >> div_cnt;

    search(1, operand_t[0], plus_cnt, minus_cnt, mul_cnt, div_cnt);

    cout << max_res << "\n" << min_res;

    return 0;
}