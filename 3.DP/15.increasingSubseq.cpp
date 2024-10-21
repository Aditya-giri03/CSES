#include <bits/stdc++.h>
using namespace std;
# define ll long long
const int mod = 1000000007;

int main() {

    int n; cin >> n;
    vector<int> arr(n);
    for (int& i : arr) {
        cin >> i;
    }
    vector<int> lis;
    lis.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] > lis.back()) {
            lis.push_back(arr[i]);
        }
        else {
            int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[idx] = arr[i];
        }
    }

    cout << lis.size() << endl;
    return 0;
}