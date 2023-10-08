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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
    }

    vi dp(n);
    vector<bool> vis(n);
    function<void(int)> dfs = [&](int u) {
        dp[u] = (u == n - 1) ? 1 : 0;
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) 
                dfs(v);
            dp[u] += dp[v];
            if (dp[u] >= MOD) 
                dp[u] -= MOD;
        }
    };
    dfs(0);
    
    cout << dp[0] << "\n";
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
