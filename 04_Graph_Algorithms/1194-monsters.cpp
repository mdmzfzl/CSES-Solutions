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

const int N = 1e3 + 5;
const int D = 4;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const string DS = "RDLU";

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(N, vector<char>(N));
    int pre[N][N];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    auto is_valid = [&](int i, int j) -> bool {
        return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == '.' && pre[i][j] == -1;
    };

    auto is_edge = [&](int i, int j) -> bool {
        return grid[i][j] == 'A' && (i == 0 || j == 0 || i == n - 1 || j == m - 1);
    };

    pii start;
    queue<pii> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') q.push({i, j});
            if (grid[i][j] == 'A') start = {i, j};
        }
    }

    q.push(start);
    memset(pre, -1, sizeof pre);

    while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        if (is_edge(i, j)) {
            string ans;
            while (pii{i, j} != start) {
                int direction_index = pre[i][j];
                ans += DS[direction_index];
                i -= dx[direction_index];
                j -= dy[direction_index];
            }
            reverse(all(ans));
            cout << "YES\n" << ans.size() << "\n" << ans << "\n";
            return;
        }

        for (int k = 0; k < D; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (is_valid(ni, nj)) {
                q.push({ni, nj});
                pre[ni][nj] = k;
                grid[ni][nj] = grid[i][j];
            }
        }
    }

    cout << "NO\n";
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
