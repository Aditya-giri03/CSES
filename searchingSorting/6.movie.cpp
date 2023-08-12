#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> movies;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        movies.push_back({s, e});
    }
    sort(movies.begin(), movies.end());
    int overlap = 0;

    int end = movies[0].second;

    for (int i = 1; i < n; i++)
    {
        if (movies[i].first < end)
        {
            overlap++;
            end = min(end, movies[i].second);
        }
        else
        {
            end = movies[i].second;
        }
    }
    cout << n - overlap << endl;

    return 0;
}