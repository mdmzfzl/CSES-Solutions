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
    
    vi dp(n), next_node(n, -1);
    vector<bool> visited(n);
    
    function<void(int)> dfs = [&](int u) {
        dp[u] = (u == n - 1) ? 1 : -1e9;
        visited[u] = true;
        
        for (int v : adj[u]) {
            if (!visited[v]) dfs(v);
            if (dp[u] < dp[v] + 1) {
                dp[u] = dp[v] + 1;
                next_node[u] = v;
            }
        }
    };
    
    dfs(0);

    if (dp[0] > 0) {
        cout << dp[0] << "\n";
        for (int u = 0; u != -1; u = next_node[u]) {
            cout << u + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
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
