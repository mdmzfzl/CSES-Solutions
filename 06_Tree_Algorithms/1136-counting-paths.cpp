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

vi adj[MAX_N];
vi prefix(MAX_N, 0);
int jump[21][MAX_N];
int level[MAX_N];

void dfs(int u, int p, int l) {
    jump[0][u] = p;
    level[u] = l;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, l + 1);
        }
    }
}

void preprocessLCA(int n) {
    dfs(1, 0, 0);

    for (int i = 1; (1 << i) <= n; i++) {
        for (int j = 1; j <= n; j++) {
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
        }
    }
}

int findLCA(int p, int q) {
    if (level[p] < level[q]) {
        swap(p, q);
    }

    int diff = level[p] - level[q];

    for (int i = 20; i >= 0; i--) {
        if (diff & (1 << i)) {
            p = jump[i][p];
        }
    }

    if (p == q) {
        return p;
    }

    for (int i = 20; i >= 0; i--) {
        if (jump[i][p] != jump[i][q]) {
            p = jump[i][p];
            q = jump[i][q];
        }
    }
    return jump[0][p];
}

void dfsPrefixSum(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            dfsPrefixSum(v, u);
            prefix[u] += prefix[v];
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    preprocessLCA(n);

    while (m--) {
        int u, v;
        cin >> u >> v;
        prefix[u]++;
        prefix[v]++;
        int lca = findLCA(u, v);
        prefix[lca]--;
        prefix[jump[0][lca]]--;
    }

    dfsPrefixSum(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << prefix[i] << " ";
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
