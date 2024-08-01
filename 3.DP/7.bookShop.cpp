#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> pages(n);
    for (int& i : price) {
        cin >> i;
    }
    for (int& i : pages) {
        cin >> i;
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int amt = 1; amt <= x; amt++) {
            int ntake = dp[idx + 1][amt];

            // take
            int take = INT_MIN;
            if (amt >= price[idx])
                take = pages[idx] + dp[idx + 1][amt - price[idx]];

            dp[idx][amt] = max(take, ntake);
        }
    }
    cout << dp[0][x];

    return 0;
}