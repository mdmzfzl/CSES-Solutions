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

const int MAX_N = 2e5 +5;

void solve() {
    int n;
    cin >> n;

    vl adj[MAX_N];
    vl in(MAX_N, 0);
    vl out(MAX_N, 0);
    vl sub_size(MAX_N, 0);

    function<void(int, int)> dfs_in = [&](int u, int p) {
        sub_size[u] = 1;

        for (int v : adj[u]) {
            if (v != p) {
                dfs_in(v, u);
                sub_size[u] += sub_size[v];
                in[u] += in[v] + sub_size[v];
            }
        }
    };

    function<void(int, int)> dfs_out = [&](int u, int p) {
        ll store = 0;
        for (int v : adj[u]) {
            if (v != p)
                store += in[v] + sub_size[v] * 2;
        }

        for (int v : adj[u]) {
            if (v != p) {
                out[v] = (out[u] + 1 * (n - sub_size[u] + 1)) + (store - (in[v] + sub_size[v] * 2));
                dfs_out(v, u);
            }
        }
    };

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs_in(1, 0);
    dfs_out(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << in[i] + out[i] << " ";
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
