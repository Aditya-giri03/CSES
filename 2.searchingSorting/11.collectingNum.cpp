#include <bits/stdc++.h>
using namespace std;

// O(n) approach: count num of inversions in position array
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
    {
        cin >> i;
    }
    vector<int> pos(n + 1); // pos arr tells where ith elents pos/idx is

    for (int i = 0; i < n; i++)
    {
        pos[arr[i]] = i + 1;
    }

    int rounds = 0;
    for (int i = 1; i < n; i++)
    {
        if (pos[i + 1] < pos[i])
            rounds++;
    }

    cout << rounds + 1 << endl;
    return 0;
}

//  ----O(n2) TLE---
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int &i : arr)
//     {
//         cin >> i;
//     }
//     vector<bool> taken(n, false);
//     int cnt = 0, rounds = 0;
//     while (cnt < n)
//     {
//         int prev = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (!taken[i] && arr[i] > prev)
//             {
//                 taken[i] = 1;
//                 cnt++;
//                 prev = arr[i];
//             }
//         }
//         rounds++;
//     }
//     cout << rounds << endl;
//     return 0;
// }