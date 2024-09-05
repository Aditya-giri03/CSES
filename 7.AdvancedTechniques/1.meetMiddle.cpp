#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    // 1. Div arr into 2 parts 
    int n1 = n / 2;
    int n2 = n - n1;


    unordered_map<int, int> sums1; // sum -> freq of this sum encountered

    // 2. Generating all subset sum possible for fisrt half(n1) elements & storing in map
    for (int mask = 0; mask < (1 << n1); mask++) {
        int sum = 0, curMask = mask, idx = 0;
        while (curMask > 0) {
            if ((curMask & 1) != 0) sum += arr[idx];
            idx++;
            curMask >>= 1;
        }
        sums1[sum]++;
    }

    // Iterating over left other half & forming subset & checking if requirement can be fulfilled using 1st half by finding in map 
    int res = 0;
    for (int mask = 0; mask < (1 << n2); mask++) {
        int sum = 0, curMask = mask, idx = n1;
        while (curMask > 0) {
            if ((curMask & 1) != 0) sum += arr[idx];
            idx++;
            curMask >>= 1;
        }
        if (sums1.find(x - sum) != sums1.end()) {
            res += sums1[x - sum];
        }
    }

    cout << res << endl;
    return 0;
}