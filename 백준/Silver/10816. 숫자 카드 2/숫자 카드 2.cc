#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int M;
    int temp;
    unordered_map<int, int> um;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        um[temp]++;
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> temp;
        auto iter = um.find(temp);
        if (iter != um.end())
        {
            cout << iter->second << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }

    return 0;
}

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     int N;
//     int M;
//     int temp;
//     vector<int> v;

//     cin >> N;
//     for (int i = 0; i < N; ++i)
//     {
//         cin >> temp;
//         v.push_back(temp);
//     }
//     sort(v.begin(), v.end());

//     cin >> M;
//     for (int i = 0; i < M; ++i)
//     {
//         cin >> temp;
//         cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << " ";
//     }

//     return 0;
// }
