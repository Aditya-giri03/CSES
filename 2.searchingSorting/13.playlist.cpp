#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> songs(n);
    for (int &s : songs)
    {
        cin >> s;
    }
    // sliding window
    // unordered_set<int> st;
    vector<bool> visitedSet(1e9 + 1, false); // using vector instead of set to optimize
    int i = 0, j = 0;
    int longest = 0;
    while (j < n)
    {
        if (visitedSet[songs[j]])
        {
            while (songs[i] != songs[j])
            {
                visitedSet[songs[i]] = false;
                i++;
            }
            i++;
        }
        else
        {
            visitedSet[songs[j]] = true;
            longest = max(longest, j - i + 1);
        }
        j++;
    }
    cout << longest << endl;
    return 0;
}