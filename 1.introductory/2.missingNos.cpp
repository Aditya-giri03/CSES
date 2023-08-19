#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int xorVal = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int val;
        cin >> val;
        xorVal ^= val;
    }
    for (int i = 1; i <= n; i++)
    {
        xorVal ^= i;
    }
    cout << xorVal << endl;

    return 0;
}