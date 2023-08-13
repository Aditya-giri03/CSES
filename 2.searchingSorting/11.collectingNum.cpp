#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
    {
        cin >> i;
    }
    vector<bool> taken(n, false);
    int cnt = 0, rounds = 0;
    while (cnt < n)
    {
        int prev = -1;
        for (int i = 0; i < n; i++)
        {
            if (!taken[i] && arr[i] > prev)
            {
                taken[i] = 1;
                cnt++;
                prev = arr[i];
            }
        }
        rounds++;
    }
    cout << rounds << endl;
    return 0;
}