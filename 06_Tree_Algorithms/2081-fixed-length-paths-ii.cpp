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
    Tree(int n, int k1, int k2) : n(n), k1(k1), k2(k2), result(0) {
        adj.resize(n + 1);
        height.assign(n + 1, 0);
        sub_size.assign(n + 1, 0);
        time_in.assign(n + 1, 0);
        time_out.assign(n + 1, 0);
        id.assign(n + 1, 0);
        BIT.assign(n + 1, 0);
        dfs_time = 0;
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
    int n, k1, k2;
    vector<vi> adj;
    vi height, sub_size, time_in, time_out, id, BIT;
    int dfs_time;
    ll result;

    void update(int id, int val) {
        while (id <= n) {
            BIT[id] += val;
            id += id & -id;
        }
    }

    int get(int id) {
        int res = 0;
        while (id > 0) {
            res += BIT[id];
            id -= id & -id;
        }
        return res;
    }

    void prepare(int u, int parent = 0) {
        time_in[u] = ++dfs_time;
        id[dfs_time] = u;
        sub_size[u] = 1;
        for (int v : adj[u]) {
            if (v == parent) continue;
            height[v] = height[u] + 1;
            prepare(v, u);
            sub_size[u] += sub_size[v];
        }
        time_out[u] = dfs_time;
    }

    void dfs(int u, int parent = 0) {
        int heavy = 0;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!heavy || sub_size[v] > sub_size[heavy]) {
                heavy = v;
            }
        }

        for (int v : adj[u]) {
            if (v == parent || v == heavy) continue;
            dfs(v, u);
            for (int i = time_in[v]; i <= time_out[v]; i++) {
                update(height[id[i]], -1);
            }
        }

        if (heavy) {
            dfs(heavy, u);
        }

        for (int v : adj[u]) {
            if (v == parent || v == heavy) continue;
            for (int i = time_in[v]; i <= time_out[v]; i++) {
                if (height[id[i]] - height[u] <= k2 && k1 - height[id[i]] + 2 * height[u] <= n) {
                    result += get(min(n, k2 - height[id[i]] + 2 * height[u])) - get(max(1, k1 - height[id[i]] + 2 * height[u]) - 1);
                }
            }
            for (int i = time_in[v]; i <= time_out[v]; i++) {
                update(height[id[i]], 1);
            }
        }
        update(height[u], 1);
        if (height[u] + k1 <= n) {
            result += get(min(n, height[u] + k2)) - get(max(1, height[u] + k1) - 1);
        }
    }
};

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    Tree tree(n, k1, k2);

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
