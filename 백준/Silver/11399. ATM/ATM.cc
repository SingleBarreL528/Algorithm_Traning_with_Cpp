#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    vector<int> cus_list;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        cus_list.push_back(temp);
    }

    sort(cus_list.begin(), cus_list.end());
    for (int i = 0; i < n; ++i)
    {
        sum += cus_list[i] * (n - i);
    }

    cout << sum;

    return 0;
}