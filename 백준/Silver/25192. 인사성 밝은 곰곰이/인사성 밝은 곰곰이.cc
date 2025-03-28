#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// unordered set -> 시간 초과 발생 O(n)
// set 사용하기

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cnt = 0;
    string user_name;
    set<string> user_set;

    cin >> n;

    // code 1
    // while (n--)
    // {
    //     cin >> user_name;

    //     if (user_name == "ENTER")
    //     {
    //         user_set.clear();
    //         continue;
    //     }

    //     if (user_set.find(user_name) == user_set.end())
    //     {
    //         ++cnt;
    //         user_set.insert(user_name);
    //     }
    // }

    // code 2
    while (n--)
    {
        cin >> user_name;

        if (user_name == "ENTER")
        {
            cnt += user_set.size();
            user_set.clear();
            continue;
        }

        user_set.insert(user_name);
    }
    cnt += user_set.size();

    cout << cnt;

    return 0;
}