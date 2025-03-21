#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int temp;
    int max = 2;
    int min = 1000000;

    cin >> n;
    while (n--)
    {
        cin >> temp;
        if (max < temp)
        {
            max = temp;
        }
        if (min > temp)
        {
            min = temp;
        }
    }

    cout << max * min;
}