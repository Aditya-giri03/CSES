#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> desiredSize(n);
    vector<int> size(m);
    for (int i = 0; i < n; i++)
    {

        cin >> desiredSize[i];
    }
    for (int i = 0; i < m; i++)
    {

        cin >> size[i];
    }
    sort(desiredSize.begin(), desiredSize.end());
    sort(size.begin(), size.end());

    int i = 0, j = 0;

    int asigned = 0;

    while (i < n && j < m)
    {
        if (size[j] >= desiredSize[i] - k && size[j] <= desiredSize[i] + k)
        {
            asigned++;
            i++;
            j++;
        }
        else if (size[j] < desiredSize[i] - k)
        {
            j++;
        }
        else if (size[j] > desiredSize[i] + k)
        {
            i++;
        }
    }
    cout << asigned;
    return 0;
}