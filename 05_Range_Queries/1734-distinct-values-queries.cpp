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

template <typename T>
struct FenwickTree {
    int n;
    vector<T> fenwick;

    FenwickTree(int size) : n(size), fenwick(size, 0) {}

    void update(int x, T v) {
        for (; x < n; x |= (x + 1))
            fenwick[x] += v;
    }

    void update(int l, int r, T v) {
        update(l, v);
        update(r + 1, -v);
    }

    T query(int x) {
        T res = 0;
        for (; x >= 0; x = (x & (x + 1)) - 1)
            res += fenwick[x];
        return res;
    }

    T query(int l, int r) {
        return (l <= r) ? query(r) - query(l - 1) : 0;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int &x : a) cin >> x;

    vector<vector<pii>> queries(n);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries[r].emplace_back(l, i);
    }

    FenwickTree<ll> tree(n);
    umap<int, int> last_occ;
    vi ans(q);

    for (int r = 0; r < n; r++) {
        if (last_occ.count(a[r]))
            tree.update(last_occ[a[r]], -1);
        last_occ[a[r]] = r;
        tree.update(r, 1);

        for (auto [l, i] : queries[r]) {
            ans[i] = tree.query(l, r);
        }
    }

    for (int x : ans)
        cout << x << "\n";
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
