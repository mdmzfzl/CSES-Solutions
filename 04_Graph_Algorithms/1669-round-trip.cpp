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

vi parent;
vector<vi> adj;
vector<bool> visited;
int start_node, end_node;

bool dfs(int v, int p) {
    visited[v] = true;
    parent[v] = p;

    for (int u : adj[v]) {
        if (!visited[u]) {
            if (dfs(u, v)) {
                return true;
            }
        } else if (u != p) {
            start_node = u;
            end_node = v;
            return true;
        }
    }

    return false;
}

void find_cycle() {
    visited.assign(adj.size(), false);
    parent.assign(adj.size(), -1);
    start_node = -1;
    end_node = -1;

    for (size_t i = 1; i < adj.size(); i++) {
        if (!visited[i] && dfs(i, -1)) {
            return;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    find_cycle();

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vi cycle;
        cycle.pb(start_node);

        int node = end_node;
        while (node != start_node) {
            cycle.pb(node);
            node = parent[node];
        }

        cycle.pb(start_node);

        cout << cycle.size() << "\n";
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << "\n";
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
