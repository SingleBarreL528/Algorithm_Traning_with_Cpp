#include <iostream>
#include <string>
#include <vector>

using namespace std;

int is_palindrome(string &S, int &cnt, int left_idx, int right_idx)
{
    if (left_idx >= right_idx)
    {
        return 1;
    }
    else
    {
        if (S.at(left_idx) == S.at(right_idx))
        {
            return is_palindrome(S, ++cnt, ++left_idx, --right_idx);
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int result;
    int cnt;
    string S;

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> S;

        cnt = 1;
        result = is_palindrome(S, cnt, 0, S.length() - 1);

        cout << result << " " << cnt << "\n";
    }

    return 0;
}