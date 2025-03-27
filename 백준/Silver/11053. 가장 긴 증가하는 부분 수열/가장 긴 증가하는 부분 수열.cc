#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int val[1001] = {0};
int cnt[1001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> val[i];
        for (int j = i - 1; j >= 1; --j)
        {
            if (val[i] > val[j])
            {
                cnt[i] = max(cnt[i], cnt[j]);
            }
        }
        cnt[i]++;
    }

    cout << *max_element(cnt, cnt + n + 1);

    return 0;
}