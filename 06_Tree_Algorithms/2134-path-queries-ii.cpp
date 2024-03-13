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

class SegmentTree {
private:
    int n;
    vi tree;

public:
    SegmentTree(int _n) : n(_n), tree(2 * _n) {}

    SegmentTree(const vi& array) : n(array.size()), tree(2 * array.size()) {
        copy(all(array), tree.begin() + n);
        for (int i = n - 1; i > 0; --i)
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }

    int query(int left, int right) {
        int result = INT_MIN;
        for (left += n, right += n; left < right; left >>= 1, right >>= 1) {
            if (left & 1)
                result = max(result, tree[left++]);
            if (right & 1)
                result = max(result, tree[--right]);
        }
        return result;
    }

    void update(int index, int value) {
        for (tree[index += n] = value; index > 1; index >>= 1)
            tree[index >> 1] = max(tree[index], tree[index ^ 1]);
    }
};

class HeavyLightDecomposition {
private:
    int n, ti;
    vector<vi> adj;
    vi parent, tin, head, depth, sub_size;
    SegmentTree st;

    void dfs(int u) {
        sub_size[u] = 1;
        for (int& v : adj[u]) {
            auto it = find(all(adj[v]), u);
            adj[v].erase(it);
            parent[v] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
            sub_size[u] += sub_size[v];
            if (sub_size[v] > sub_size[adj[u][0]])
                swap(v, adj[u][0]);
        }
    }

    void decompose(int u) {
        tin[u] = ti++;
        for (int v : adj[u]) {
            head[v] = (v == adj[u][0] ? head[u] : v);
            decompose(v);
        }
    }

public:
    HeavyLightDecomposition(int _n) : n(_n), ti(0), adj(_n), parent(_n), tin(_n), head(_n), depth(_n), sub_size(_n), st(_n) {}

    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    void initialize(int root = 0) {
        parent[root] = depth[root] = ti = 0;
        head[root] = root;
        dfs(root);
        decompose(root);
    }

    void updateNode(int u, int value) {
        st.update(tin[u], value);
    }

    template <class Operation>
    void processPath(int u, int v, Operation op) {
        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);
            op(tin[head[u]], tin[u]);
            u = parent[head[u]];
        }
        if (depth[u] > depth[v])
            swap(u, v);
        op(tin[u], tin[v]);
    }

    int queryPath(int u, int v) {
        int result = INT_MIN;
        processPath(u, v, [this, &result](int left, int right) { result = max(result, st.query(left, right + 1)); });
        return result;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int& value : a) cin >> value;
    
    HeavyLightDecomposition hld(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        hld.addEdge(u, v);
    }
    hld.initialize(0);

    for (int i = 0; i < n; ++i)
        hld.updateNode(i, a[i]);
    while (q--) {
        int queryType;
        cin >> queryType;
        if (queryType == 1) {
            int u, x;
            cin >> u >> x;
            hld.updateNode(u - 1, x);
        } else {
            int u, v;
            cin >> u >> v;
            --u; --v;
            cout << hld.queryPath(u, v) << " ";
        }
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
