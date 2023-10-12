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

void dfs(int node, vi& path, vector<vector<pii>>& adj, vi& visited) {
    for (auto [nbr, idx] : adj[node]) {
        if (visited[idx]) continue;
        visited[idx] = true;
        dfs(nbr, path, adj, visited);
    }
    path.pb(node);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);
    vi visited(m, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    for (int i = 0; i < n; i++) {
        if (adj[i].size() & 1) {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    vi path;
    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int curr = st.top();
        if (adj[curr].empty()) {
            path.pb(curr);
            st.pop();
        } else {
            auto [nbrNode, idx] = adj[curr].back();
            adj[curr].pop_back();
            if (visited[idx]) continue;
            visited[idx] = true;
            st.push(nbrNode);
        }
    }

    if (int(path.size()) == m + 1) {
        for (auto it : path) cout << it + 1 << " ";
    } else {
        cout << "IMPOSSIBLE";
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
