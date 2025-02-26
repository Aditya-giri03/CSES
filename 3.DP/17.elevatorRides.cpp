#include <bits/stdc++.h>
using namespace std;
# define ll long long
const int mod = 1000000007;

int main() {
    int n, x; cin >> n >> x;
    vector<int> wt(n); for (int& i : wt) cin >> i;
    vector<pair<int, int>> dp(1 << n, { 1e9,1e9 });
    //  dp[mask] = {min no of rides to take set bit mask people, weight used in last ride}
    dp[0] = { 1,0 };

    for (int bitMask = 1; bitMask < (1 << n); bitMask++) {
        // considering each person as last to take ride
        for (int i = 0; i < n; i++) {
            if (bitMask & (1 << i)) {
                int remainingState = (bitMask ^ (1 << i));
                int rides = dp[remainingState].first;
                int lastRideWeight = dp[remainingState].second;
                if (lastRideWeight + wt[i] <= x) {
                    dp[bitMask] = min(dp[bitMask], { rides, lastRideWeight + wt[i] });
                }
                else dp[bitMask] = min(dp[bitMask], { rides + 1, wt[i] });
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;
    return 0;
}