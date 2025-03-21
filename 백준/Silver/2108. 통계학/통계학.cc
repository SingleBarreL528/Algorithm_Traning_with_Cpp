#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// ceil() : 올림 ->  ceil(N - 0.5) : 반올림
// floor() : 내림 -> floor(N + 0.5) : 반올림
// round() : 반올림
// trunc() : 버림

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    double sum = 0;
    double mean = 0;
    int median = 0;
    int mode = 0;
    vector<int> arr;
    int count_arr[8001] = {0};

    int temp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        count_arr[temp + 4000]++;
        arr.push_back(temp);
        sum += temp;
    }

    sort(arr.begin(), arr.end());

    mean = round(sum / n);
    if (mean == -0)
    {
        mean = 0;
    }

    median = arr.at(n / 2);

    int count_max = 0;
    int count_flag = 0;
    for (int i = 0; i < 8001; ++i)
    {
        if (count_arr[i] > count_max)
        {
            count_max = count_arr[i];
            count_flag = 0;
            mode = i - 4000;
        }
        else if ((count_arr[i] == count_max) && (count_flag == 0))
        {
            count_max = count_arr[i];
            count_flag = 1;
            mode = i - 4000;
        }
    }

    cout << mean << "\n";
    cout << median << "\n";
    cout << mode << "\n";
    cout << arr.back() - arr.front() << "\n";

    return 0;
}