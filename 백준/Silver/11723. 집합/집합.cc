#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void operate_command(string &command, int &operand, int &bit_mask)
{
    if (command == "add")
    {
        bit_mask |= (1 << operand);
    }
    else if (command == "remove")
    {
        bit_mask &= ~(1 << operand);
    }
    else if (command == "check")
    {
        cout << ((bit_mask & (1 << operand)) ? 1 : 0) << "\n";
    }
    else if (command == "toggle")
    {
        bit_mask ^= (1 << operand);
    }
    else if (command == "all")
    {
        bit_mask = (1 << 21) - 1;
    }
    else if (command == "empty")
    {
        bit_mask = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    int operand;
    string command;
    int bit_mask = 0;

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> command;
        if (command != "all" && command != "empty")
        {
            cin >> operand;
        }
        operate_command(command, operand, bit_mask);
    }

    return 0;
}