/*
Solvable using Greedy Approach
*/
#include <bits/stdc++.h>
using namespace std;

int findMaxDig(int n) {
    int dig = -1;
    while (n > 0)
    {
        int d = n % 10;
        n = n / 10;
        dig = max(dig, d);
    }
    return dig;
}

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    while (n > 0)
    {
        int maxDig = findMaxDig(n);
        n -= maxDig;
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}