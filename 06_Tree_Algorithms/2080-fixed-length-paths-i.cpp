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

class Tree {
public:
    Tree(int nodes, int depth) : n(nodes), k(depth) {
        adj.resize(n + 1);
        height.resize(n + 1);
        sub_size.resize(n + 1);
        time_in.resize(n + 1);
        time_out.resize(n + 1);
        id.resize(n + 1);
        count.resize(n + 1);
        dfs_time = 0;
        result = 0;
    }

    void addEdge(int u, int v) {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll solve() {
        height[1] = 1;
        prepare(1);
        dfs(1, 0);
        return result;
    }

private:
    int n, k;
    vector<vi> adj;
    vi height, sub_size, time_in, time_out, id, count;
    int dfs_time;
    ll result;

    void prepare(int u, int pr = 0) {
        time_in[u] = ++dfs_time;
        id[dfs_time] = u;
        sub_size[u] = 1;
        for (int v : adj[u]) {
            if (v == pr) continue;
            height[v] = height[u] + 1;
            prepare(v, u);
            sub_size[u] += sub_size[v];
        }
        time_out[u] = dfs_time;
    }

    void dfs(int u, int pr = 0) {
        int heavy = 0;
        for (int v : adj[u]) {
            if (v == pr) continue;
            if (!heavy || sub_size[v] > sub_size[heavy]) {
                heavy = v;
            }
        }

        for (int v : adj[u]) {
            if (v == pr || v == heavy) continue;
            dfs(v, u);
            for (int i = time_in[v]; i <= time_out[v]; i++) {
                count[height[id[i]]]--;
            }
        }

        if (heavy) {
            dfs(heavy, u);
        }
        count[height[u]]++;

        for (int v : adj[u]) {
            if (v == pr || v == heavy) continue;
            for (int i = time_in[v]; i <= time_out[v]; i++) {
                if (height[id[i]] - height[u] < k && k - height[id[i]] + 2 * height[u] <= n) {
                    result += count[k - height[id[i]] + 2 * height[u]];
                }
            }
            for (int i = time_in[v]; i <= time_out[v]; i++) {
                count[height[id[i]]]++;
            }
        }
        if (height[u] + k <= n) {
            result += count[height[u] + k];
        }
    }
};

void solve() {
    int n, k;
    cin >> n >> k;;

    Tree tree(n, k);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v);
    }

    cout << tree.solve();
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

// class CentroidDecomposition {
// private:
//     vi sub_size, par, vis, count;
//     vector<vi> adj;
//     int k;
//     ll result;

// public:
//     CentroidDecomposition(int n, int _k) : sub_size(n), par(n), vis(n), count(n), adj(n), k(_k), result(0) {}

//     void addEdge(int u, int v) {
//         adj[u].pb(v);
//         adj[v].pb(u);
//     }

//     void build(int u = 0, int p = -1) {
//         u = findCentroid(u, p, calculateSubtreeSize(u, p));
//         par[u] = p;
//         vis[u] = 1;
//         count[0] = 1;
//         int mx = 0;
//         for (int v : adj[u]) {
//             if (!vis[v]) {
//                 solve(v, u, 1, true, mx);
//                 solve(v, u, 1, false, mx);
//             }
//         }
//         memset(&count[0], 0, (mx + 1) * sizeof(int));
//         for (int v : adj[u])
//             if (!vis[v])
//                 build(v, u);
//     }

//     void solve(int u, int p, int d, bool flag, int &mx) {
//         if (d > k) return;
//         mx = max(mx, d);
//         if (flag) result += count[k - d];
//         else count[d]++;
//         for (int v : adj[u]) {
//             if (vis[v] || v == p) continue;
//             solve(v, u, d + 1, flag, mx);
//         }
//     }

//     int calculateSubtreeSize(int u, int p) {
//         sub_size[u] = 1;
//         for (int v : adj[u])
//             if (v != p && !vis[v])
//                 sub_size[u] += calculateSubtreeSize(v, u);
//         return sub_size[u];
//     }

//     int findCentroid(int u, int p, int nn) {
//         for (int v : adj[u])
//             if (v != p && !vis[v] && sub_size[v] > nn / 2)
//                 return findCentroid(v, u, nn);
//         return u;
//     }

//     int operator[](int i) const {
//         return par[i];
//     }

//     void printResult() {
//         cout << result << '\n';
//     }
// };

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     CentroidDecomposition cd(n, k);
//     for (int i = 0; i < n - 1; i++) {
//         int u, v;
//         cin >> u >> v;
//         u--; v--;
//         cd.addEdge(u, v);
//     }
//     cd.build();
//     cd.printResult();
// }

// class CentroidDecomposition {
// public:
//     CentroidDecomposition(int n, int k) : n(n), k(k), adj(n), removed{}, depth{}, count{}, sub_size{} {}

//     void addEdge(int a, int b) {
//         a--, b--;
//         adj[a].pb(b);
//         adj[b].pb(a);
//     }

//     ll solve() {
//         if (k == 1) {
//             return n - 1;
//         }
//         return centroidDecomposition(0);
//     }

// private:
//     int n, k;
//     vector<vi> adj;
//     bool removed[MAX_N];
//     int depth[MAX_N];
//     int count[MAX_N];
//     int sub_size[MAX_N];

//     void dfs(int x, int banned = -1) {
//         sub_size[x] = 1;
//         for (auto u : adj[x]) {
//             if (!removed[u] && u != banned) {
//                 dfs(u, x);
//                 sub_size[x] += sub_size[u];
//             }
//         }
//     }

//     int findCentroid(int x, int n) {
//         for (auto u : adj[x]) {
//             if (!removed[u] && sub_size[u] < sub_size[x] && sub_size[u] > n / 2) {
//                 return findCentroid(u, n);
//             }
//         }
//         return x;
//     }

//     void getNodes(int x, int banned, vi &nodes) {
//         count[depth[x]]++;
//         nodes.pb(x);
//         for (auto u : adj[x]) {
//             if (u != banned && !removed[u]) {
//                 depth[u] = depth[x] + 1;
//                 getNodes(u, x, nodes);
//             }
//         }
//     }

//     ll centroidDecomposition(int x) {
//         int orig_x = x;
//         dfs(x, -1);
//         x = findCentroid(x, sub_size[x]);

//         ll res = 0;

//         if (sub_size[orig_x] >= k + 1) {
//             depth[x] = 0;
//             vector<vi> nodes;

//             for (auto u : adj[x])
//                 if (!removed[u]) {
//                     nodes.emplace_back();
//                     depth[u] = 1;
//                     getNodes(u, x, *nodes.rbegin());
//                 }

//             for (int i = 0; i < nodes.size(); i++) {
//                 for (auto u : nodes[i]) count[depth[u]]--;
//                 for (auto u : nodes[i])
//                     if (k - depth[u] >= 0) res += count[k - depth[u]];
//                 for (auto u : nodes[i]) count[depth[u]]++;
//             }

//             res /= 2;
//             res += count[k];
//             for (int i = 0; i < k + 1; i++) count[i] = 0;

//             removed[x] = true;
//             for (auto u : adj[x])
//                 if (!removed[u]) {
//                     res += centroidDecomposition(u);
//                 }
//         }

//         return res;
//     }
// };

// void solve() {
//     int n, k;
//     cin >> n >> k;

//     CentroidDecomposition cd(n, k);

//     for (int i = 0; i < n - 1; i++) {
//         int a, b;
//         cin >> a >> b;
//         cd.addEdge(a, b);
//     }

//     cout << cd.solve();
// }
