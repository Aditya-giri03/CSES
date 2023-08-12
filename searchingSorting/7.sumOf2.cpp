#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, target;
    cin >> n >> target;
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back({val, i + 1});
    }

    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    while (i < j)
    {
        int sum = arr[i].first + arr[j].first;
        if (sum == target)
        {
            cout << arr[i].second << " " << arr[j].second;
            break;
        }
        else if (sum < target)
            i++;

        else
            j--;
    }
    if (j <= i)
        cout << "IMPOSSIBLE";

    return 0;
}