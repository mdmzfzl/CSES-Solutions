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

const int MAX_N = 501;

int n, m;
ll adj[MAX_N][MAX_N];
bool vis[MAX_N] = {false};
ll max_speed = 0;

bool dfs(int nod, ll c) {
    if (vis[nod]) return false;
    vis[nod] = true;

    if (nod == n) {
        max_speed += c;
        return true;
    }

    bool v = false;
    for (int i = 1; !v && i <= n; i++) {
        if (adj[nod][i] >= c && dfs(i, c)) {
            v = true;
            adj[nod][i] -= c;
            adj[i][nod] += c;
        }
    }
    return v;
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] += c;
    }

    ll c = INF;
    while (c > 0) {
        memset(vis, false, sizeof(vis));
        if (!dfs(1, c)) {
            c >>= 1;
        }
    }

    cout << max_speed;
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
