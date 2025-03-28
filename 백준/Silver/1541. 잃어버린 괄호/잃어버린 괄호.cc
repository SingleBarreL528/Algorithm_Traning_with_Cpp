#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string question;
int idx;

int extract_num(int &idx)
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

int calc(int &idx)
{
    int num = extract_num(idx);

    while (idx <= question.length() - 1)
    {
        if (question[idx] == '-')
        {
            int num_temp = extract_num(++idx);

            while (question[idx] == '+')
            {
                num_temp += extract_num(++idx);
            }
            num -= num_temp;
        }
        else if (question[idx] == '+')
        {
            num += extract_num(++idx);
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

    cout << calc(idx);

    return 0;
}