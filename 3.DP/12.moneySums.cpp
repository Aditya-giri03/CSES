#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int main() {
    int n; cin >> n;
    vector<int> value(n);
    for (int& i : value) cin >> i;
    vector<int> dp(1e5 + 1, 0);
    vector<int> sums;

    dp[0] = 1;
    for (int v : value) { // iterating thru all values & using it to  make new sums from existing possible sums
        for (int s = 1e5; s > 0; s--) { // iterating in rev bcox we want to consider only existing sums, not the sums marked possible now only due to v (would count contribution of v twice in this way)
            if (s - v >= 0 && dp[s - v] == 1) {
                dp[s] = 1;
            }
        }
    }
    for (int i = 1; i <= 1e5; i++) {
        if (dp[i] == 1) sums.push_back(i);
    }
    cout << sums.size() << endl;
    for (int res : sums) cout << res << " ";
    cout << endl;

}