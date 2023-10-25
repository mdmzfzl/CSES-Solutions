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
const int MAX_LOG = 21;

int n;
int level[MAX_N]; 
vi adj[MAX_N];
int jump[MAX_LOG][MAX_N];

void dfs(int u, int p, int l) {
    jump[0][u] = p;
    level[u] = l;

    for (int v : adj[u])
        if (v != p)
            dfs(v, u, l + 1);
}

int findLCA(int p, int q) {
    if (level[p] < level[q])
        swap(p, q);

    int diff = level[p] - level[q];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        if (diff & (1 << i))
            p = jump[i][p];

    if (p == q)
        return p;

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (jump[i][p] != jump[i][q]) {
            p = jump[i][p];
            q = jump[i][q];
        }
    }
    return jump[0][p];
}

void preprocessLCA() {
    dfs(1, -1, 0);

    for (int i = 1; 1 << i <= n; i++)
        for (int j = 1; j <= n; j++)
            jump[i][j] = jump[i - 1][jump[i - 1][j]];
}

void solve() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    preprocessLCA();

    while (q--) {
        int a, b;
        cin >> a >> b;
        int lca = findLCA(a, b);
        cout << level[a] + level[b] - 2 * level[lca] << '\n';
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
