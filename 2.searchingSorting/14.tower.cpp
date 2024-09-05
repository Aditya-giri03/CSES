#include <bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> tower;
    int n;
    cin >> n;
    vector<int> cubes;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        cubes.push_back(val);
    }

    for (int cube : cubes)
    {
        auto it = tower.upper_bound(cube);
        if (it != tower.end())
        {
            tower.erase(it);
            tower.insert(cube);
        }
        else
        {
            tower.insert(cube);
        }
    }

    cout << tower.size() << endl;
    return 0;
}
/*
5
3 8 2 1 5

need to maintain top of towers
first i have towers: 3 8
now when i encounter 2 I have 2 option to put it on top of tower1 or tower2
putting on top of 3 would be benefecial insted of 8 as 3 is just upper_bound of 2.
*/