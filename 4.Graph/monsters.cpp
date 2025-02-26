#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) cin >> grid[i];

    queue<pair<int, int>> q;
    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') q.push({ i,j });
            else if (grid[i][j] == 'A') start = { i,j };
        }
    }
    q.push(start);

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();

        // UP
        if (r - 1 >= 0 && grid[r - 1][c] == '.') {
            q.push({ r - 1,c });
            grid[r - 1][c] = (grid[r][c] == 'M') ? 'M' : 'U';
        }
        // RIGHT
        if (c + 1 < m && grid[r][c + 1] == '.') {
            q.push({ r ,c + 1 });
            grid[r][c + 1] = (grid[r][c] == 'M') ? 'M' : 'R';
        }
        // DOWN
        if (r + 1 < n && grid[r + 1][c] == '.') {
            q.push({ r + 1,c });
            grid[r + 1][c] = (grid[r][c] == 'M') ? 'M' : 'D';
        }
        // LEFT
        if (c - 1 >= 0 && grid[r][c - 1] == '.') {
            q.push({ r ,c - 1 });
            grid[r][c - 1] = (grid[r][c] == 'M') ? 'M' : 'L';
        }

    }
    // for (auto s : grid) cout << s << endl;

    pair<int, int> escapePt = { -1,-1 };
    // vertical boundaries
    for (int i = 0; i < n; i++) {
        if (grid[i][0] != 'M' && grid[i][0] != '.' && grid[i][0] != '#') {
            escapePt = { i,0 };
        }
        else if (grid[i][m - 1] != 'M' && grid[i][m - 1] != '.' && grid[i][m - 1] != '#') {
            escapePt = { i,m - 1 };
        }
    }
    // horizontal boundaries
    for (int j = 0; j < m; j++) {
        if (grid[0][j] != 'M' && grid[0][j] != '.' && grid[0][j] != '#') {
            escapePt = { 0,j };
        }
        else if (grid[n - 1][j] != 'M' && grid[n - 1][j] != '.' && grid[n - 1][j] != '#') {
            escapePt = { n - 1,j };
        }
    }

    if (escapePt.first == -1 && escapePt.second == -1) {
        cout << "NO\n";
        return 0;
    }

    // ========== PRINTING PATH ==========

    cout << "YES\n";
    string path;
    auto [r, c] = escapePt;
    while (grid[r][c] != 'A') {
        path += grid[r][c];
        if (grid[r][c] == 'L') c += 1;
        else if (grid[r][c] == 'R') c -= 1;
        else if (grid[r][c] == 'U') r += 1;
        else if (grid[r][c] == 'D') r -= 1;
    }
    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--) cout << path[i];

    return 0;
}