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
vi col(MAX_N);
vi result(MAX_N);

set<int> dfs(int u, int p) {
    set<int> unique_colors;
    unique_colors.insert(col[u]);

    for (int v : adj[u]) {
        if (v != p) {
            set<int> child_colors = dfs(v, u);
            if (child_colors.size() > unique_colors.size()) {
                swap(child_colors, unique_colors);
            }
            for (int color : child_colors) {
                unique_colors.insert(color);
            }
        }
    }
    result[u] = unique_colors.size();
    return unique_colors;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
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
