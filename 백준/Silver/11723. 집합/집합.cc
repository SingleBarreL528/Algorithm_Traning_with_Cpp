#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void operate_command(string &command, int &operand, vector<bool> &v)
{
    if (command == "add")
    {
        v[operand] = 1;
    }
    else if (command == "remove")
    {
        v[operand] = 0;
    }
    else if (command == "check")
    {
        cout << v[operand] << "\n";
    }
    else if (command == "toggle")
    {
        v[operand] = 1 - v[operand];
    }
    else if (command == "all")
    {
        for (int i = 1; i <= 20; ++i)
        {
            v[i] = 1;
        }
    }
    else if (command == "empty")
    {
        for (int i = 1; i <= 20; ++i)
        {
            v[i] = 0;
        }
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
    vector<bool> v(21);

    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> command;
        if (command != "all" && command != "empty")
        {
            cin >> operand;
        }
        operate_command(command, operand, v);
    }

    return 0;
}