#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, x;
    cin >> n >> x;
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    sort(wt.begin(), wt.end());
    int i = 0, j = n - 1;
    int pairCnt = 0;
    while (i < j)
    {
        if (wt[i] + wt[j] <= x)
        {
            pairCnt++;
            i++;
            j--;
        }
        else if (wt[i] + wt[j] > x)
            j--;

        else
            i++;
    }
    cout << n - pairCnt;

    return 0;
}