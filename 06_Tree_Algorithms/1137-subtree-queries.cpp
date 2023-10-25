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

int n, q, t = -1;
int inTime[MAX_N], outTime[MAX_N], a[MAX_N];
vi adj[MAX_N];

void dfs(int u, int p = -1) {
    inTime[u] = ++t;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    outTime[u] = t;
}

template <typename T>
struct FenwickTree {
    int n;
    vector<T> ft;

    FenwickTree(int _n) : n(_n), ft(_n) {}

    void update(int x, T v) {
        for (; x < n; x |= x + 1) {
            ft[x] += v;
        }
    }

    T query(int x) {
        T res = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1) {
            res += ft[x];
        }
        return res;
    }

    T query(int l, int r) {
        return (l <= r) ? query(r) - (l > 0 ? query(l - 1) : 0) : 0;
    }
};

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    dfs(0);
    FenwickTree<ll> ft(n);
    
    for (int i = 0; i < n; i++) {
        ft.update(inTime[i], a[i]);
    }
    
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, x;
            cin >> u >> x;
            u--;
            ft.update(inTime[u], x - a[u]);
            a[u] = x;
        } else {
            int u;
            cin >> u;
            u--;
            cout << ft.query(inTime[u], outTime[u]) << "\n";
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
