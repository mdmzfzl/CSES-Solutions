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

const int MAX_N = 2e5 + 5;
const int LOG = 20;

vi adj[MAX_N];
int level[MAX_N], parent[MAX_N][LOG];

void dfs(int u, int p) {
    parent[u][0] = p;
    for (int i = 1; i < LOG; ++i)
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    for (auto &v : adj[u]) {
        level[v] = level[u] + 1;
        dfs(v, u);
    }
}

int findLCA(int u, int v) {
    if (level[u] > level[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; --i) {
        if (level[parent[v][i]] >= level[u]) v = parent[v][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int u;
        cin >> u;
        adj[u].pb(i);
    }
    dfs(1, 1);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << findLCA(u, v) << '\n';
    }
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
