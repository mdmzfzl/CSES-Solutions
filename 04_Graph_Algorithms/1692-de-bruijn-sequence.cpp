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

const int MAX_N = 1 << 16;

vi result;
int vis[MAX_N];
vector<pii> adj[MAX_N];

void dfs(int u) {
    while (!adj[u].empty()) {
        auto [v, i] = adj[u].back();
        adj[u].pop_back();
        if (vis[i]) continue;
        vis[i] = 1;
        dfs(v);
        result.pb(i);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int u = i >> 1, v = i & ((1 << (n - 1)) - 1);
        adj[u].pb({v, i});
    }
    dfs(0);
    reverse(all(result));
    for (int i = 0; i < n - 1; i++) cout << 0;
    for (int x : result) {
        cout << x % 2;
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
