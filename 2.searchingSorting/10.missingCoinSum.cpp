#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int &i : coins)
    {
        cin >> i;
    }
    sort(coins.begin(), coins.end());
    // int target = 0 + 1;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] > sum + 1)
        {
            break;
        }
        sum += coins[i];
    }
    cout << sum + 1 << endl;

    return 0;
}
/*
Explanation
coins: 2 9 1 2 7
sort ->
1 2 2 7 9
consider sum till idx 2
1 2 2|7 9
sum till now = 5
next element can be anywhere b/w 1 - (5+1)
bcoz we have subsets that make sum of 1,2,3,4,5 so if we get next elem as 6, sum of whole will
be 5 + 6 = 11, we can subtract 1,2,3,4,5 from 11 to get 10,9,8,7,6 resp.
if we had got next elem as 12(>11) we couldn't have made 6 (12-5=7)
*/