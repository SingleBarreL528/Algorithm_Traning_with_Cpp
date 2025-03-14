#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> coin_vec;
    int count = 0;
    int N, K;
    cin >> N >> K;

    while (N--)
    {
        int coin;
        cin >> coin;
        coin_vec.push_back(coin);
    }

    for (auto iter = coin_vec.rbegin(); iter != coin_vec.rend(); iter++)
    {
        if (K / *iter > 0)
        {
            count += K / *iter;
            K = K % *iter;
        }
    }

    cout << count << endl;

    return 0;
}