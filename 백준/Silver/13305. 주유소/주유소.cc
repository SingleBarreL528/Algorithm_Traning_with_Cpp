#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int n;
int temp;
int visited_cost = 1000000001;
long long total_cost = 0;

int road_end_idx;
vector<int>::iterator gas_end_iter;

vector<int> road;
vector<int> gas;

void find_cost()
{
    total_cost += (long long)gas[0] * road[0];
    visited_cost = gas[0];
    for (int i = 1; i < n - 1; ++i)
    {
        if (gas[i] < visited_cost)
        {
            visited_cost = gas[i];
        }
        total_cost += (long long)visited_cost * road[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> temp;
        road.push_back(temp);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        gas.push_back(temp);
    }

    road_end_idx = n - 1;
    gas_end_iter = gas.end();

    // auto iter = min_element(gas.begin(), gas.end());
    // cout << *iter << endl;
    // cout << distance(gas.begin(), iter) << endl;

    find_cost();
    cout << total_cost;

    return 0;
}