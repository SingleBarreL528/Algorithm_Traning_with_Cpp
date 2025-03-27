#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string question;
int idx;

int return_num()
{
    int num = 0;
    while ((isdigit(question[idx])) && (idx <= question.length() - 1))
    {
        num *= 10;
        num += (question[idx] - '0');
        ++idx;
    }

    return num;
}

int calc()
{
    int num = 0;

    num = return_num();
    while (idx <= question.length() - 1)
    {
        if (question[idx] == '-')
        {
            ++idx;
            int temp = return_num();
            while (question[idx] == '+')
            {
                ++idx;
                temp += return_num();
            }
            num -= temp;
        }
        else
        {
            ++idx;
            num += return_num();
        }
    }

    return num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> question;
    idx = 0;

    cout << calc();

    return 0;
}