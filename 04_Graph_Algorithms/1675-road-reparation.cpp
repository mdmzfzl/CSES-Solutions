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

const int MAX_N = 1e5 + 1;

struct Edge {
    int u, v, w;
};

int parent[MAX_N];

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(all(edges), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    ll result = 0;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int num_edges = 0;
    for (const auto& edge : edges) {
        int u = Find(edge.u);
        int v = Find(edge.v);
        if (u != v) {
            result += edge.w;
            parent[v] = u;
            ++num_edges;
            if (num_edges == n - 1) {
                break; // Minimum spanning tree formed
            }
        }
    }

    if (num_edges != n - 1) {
        cout << "IMPOSSIBLE";
    } else {
        cout << result;
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
