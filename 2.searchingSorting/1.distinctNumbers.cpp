#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    int cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] != arr[i])
            cnt++;
    }
    cout << cnt;

    return 0;
}