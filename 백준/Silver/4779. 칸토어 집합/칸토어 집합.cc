#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pow(int n)
{
    int temp = 1;
    for (int i = 0; i < n; ++i)
    {
        temp *= 3;
    }
    return temp;
}

void recursive(vector<char> &set, int start, int end)
{
    int len = end - start;

    if (len >= 3)
    {
        int blank_start = start + len / 3;
        int blank_end = end - len / 3;

        for (int i = blank_start; i < blank_end; ++i)
        {
            set.at(i) = ' ';
        }

        recursive(set, start, blank_start);
        recursive(set, blank_end, end);
    }
}

int main()
{
    int N;

    while (cin >> N)
    {
        vector<char> cantor_set(pow(N), '-');

        recursive(cantor_set, 0, cantor_set.size());

        for (auto iter = cantor_set.begin(); iter != cantor_set.end(); ++iter)
        {
            cout << *iter;
        }
        cout << endl;
    }

    return 0;
}