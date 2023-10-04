#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define umap unordered_map
#define uset unordered_set

#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair

const long long LLINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;

vector<char> path;
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

bool bfs(int &sr, int &sc, vector<vector<char>> &grid, vector<vector<char>> &dirs, vector<vector<bool>> &vis) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pii> q;
    q.push({sr, sc});
    vis[sr][sc] = true;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        if (grid[r][c] == 'B') {
            while (1) {
                path.pb(dirs[r][c]);
                r += (path.back() == 'U') - (path.back() == 'D');
                c += (path.back() == 'L') - (path.back() == 'R');
                if (r == sr && c == sc) break;
            }
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != '#') {
                q.push({nr, nc});
                vis[nr][nc] = true;
                dirs[nr][nc] = "UDLR"[i];
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int sr, sc;
    vector<vector<char>> dirs(n, vector<char>(m));
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sr = i;
                sc = j;
            }
        }
    }

    if (bfs(sr, sc, grid, dirs, vis)) {
        cout << "YES\n";
        cout << path.size() << "\n";
        while (!path.empty()) {
            cout << path.back();
            path.pop_back();
        }
    } else {
        cout << "NO";
    }
    cout << "\n";
}

int main() {
    fastio

    int tc = 1; // Number of test cases
    // cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
