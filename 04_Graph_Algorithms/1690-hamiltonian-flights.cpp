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

void solve(int tc = 0) {
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
    }
    
    vector<vi> dp(n, vi(1 << n));
    dp[0][1] = 1;
    for (int mask = 1; mask < (1 << n); mask += 2) {
        if (mask & (1 << (n - 1)) && mask != (1 << n) - 1) continue;
        for (int u = 0; u < n; u++) {
            if (mask & (1 << u)) {
                for (int v : adj[u]) {
                    if (mask & (1 << v)) continue;
                    int nmask = mask ^ (1 << v);
                    dp[v][nmask] += dp[u][mask];
                    if (dp[v][nmask] >= MOD) dp[v][nmask] -= MOD;
                }
            }
        }
    }
    cout << dp[n - 1].back() << "\n";
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
