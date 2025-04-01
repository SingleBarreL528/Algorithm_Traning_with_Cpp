#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

int n;
int temp;
int total_cost = 0;

int road_end_idx;
vector<int>::iterator gas_end_iter;

vector<int> road;
vector<int> gas;

void find_cost()
{
    while (road_end_idx != 0)
    {
        auto gas_least_iter = min_element(gas.begin(), gas_end_iter);
        int gas_cost = *gas_least_iter;
        int road_start_idx = distance(gas.begin(), gas_least_iter);

        for (int i = road_start_idx; i < road_end_idx; ++i)
        {
            total_cost += gas_cost * road[i];
        }

        road_end_idx = road_start_idx;
        gas_end_iter = gas_least_iter;
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

    find_cost();
    cout << total_cost;

    return 0;
}