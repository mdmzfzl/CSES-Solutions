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

class CentroidDecomposition {
private:
    vi sub_size, par, vis;
    vector<vi> adj;

public:
    CentroidDecomposition(int n) : sub_size(n), par(n), vis(n), adj(n) {}

    void addEdge(int u, int v) {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    void build(int u = 0, int p = -1) {
        u = findCentroid(u, p, calculateSubtreeSize(u, p));
        par[u] = p;
        vis[u] = 1;
        for (int v : adj[u])
            if (!vis[v])
                build(v, u);
    }

    int calculateSubtreeSize(int u, int p) {
        sub_size[u] = 1;
        for (int v : adj[u])
            if (v != p && !vis[v])
                sub_size[u] += calculateSubtreeSize(v, u);
        return sub_size[u];
    }

    int findCentroid(int u, int p, int nn) {
        for (int v : adj[u])
            if (v != p && !vis[v] && sub_size[v] > nn / 2)
                return findCentroid(v, u, nn);
        return u;
    }

    int operator[](int i) const {
        return par[i];
    }
};

void solve() {
    int n;
    cin >> n;
    CentroidDecomposition cd(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        cd.addEdge(u, v);
    }
    cout << cd.findCentroid(0, -1, cd.calculateSubtreeSize(0, -1)) + 1 << '\n';
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
