#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> price;

    vector<int> maxPrice(m);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        price.insert(val);
    }
    for (int &i : maxPrice)
    {
        cin >> i;
    }

    for (int priceByCustomer : maxPrice)
    {
        auto it = price.upper_bound(priceByCustomer);
        if (it == price.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--it) << endl;
            price.erase(it);
        }
    }
}
