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

const int MAX_N = 2501;

struct Edge {
    int u, v;
    ll w;
};

vector<Edge> edges;
vi forward_adj[MAX_N], reverse_adj[MAX_N];
bool visited_forward[MAX_N], visited_reverse[MAX_N];

void dfs(int node, bool* visited, vector<int>* adj) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, adj);
        }
    }
}

ll shortestPath(int n, int m) {
    vl dist(n + 1, LLINF);
    dist[1] = 0;

    for (int i = 0; i < n; i++) {
        for (const Edge& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            ll w = edge.w;

            if (dist[u] != LLINF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;

                if (i == n - 1 && visited_forward[v] && visited_reverse[v]) {
                    return -1;
                }
            }
        }
    }

    return -dist[n];
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.pb({u, v, -w});
        forward_adj[u].pb(v);
        reverse_adj[v].pb(u);
    }

    dfs(1, visited_forward, forward_adj);
    dfs(n, visited_reverse, reverse_adj);

    ll result = shortestPath(n, m);
    cout << result << "\n";
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
