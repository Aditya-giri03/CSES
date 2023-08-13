#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int &i : arr)
    {
        cin >> i;
    }
    sort(arr.begin(), arr.end());

    int mid = arr[n / 2];
    ll cost = 0;

    for (int &i : arr)
    {
        cost += abs(i - mid);
    }
    cout << cost;

    return 0;
}
/*
5
2 3 1 5 2

1 2 2 3 5
median is 2
cost = 1 + 0 + 0 + 1 + 3 = 5

case 2
4
1 5 8 9
can take either median
*/