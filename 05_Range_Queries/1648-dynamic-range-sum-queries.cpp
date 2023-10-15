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

struct FenwickTree {
    vl tree;

    FenwickTree(int n) {
        tree.assign(n + 1, 0);
    }

    void update(int idx, ll delta) {
        for (++idx; idx < (int)tree.size(); idx += (idx & -idx)) {
            tree[idx] += delta;
        }
    }

    ll query(int idx) {
        ll sum = 0;
        for (++idx; idx > 0; idx -= (idx & -idx)) {
            sum += tree[idx];
        }
        return sum;
    }

    ll query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vl initial_values(n);
    for (int i = 0; i < n; i++) {
        cin >> initial_values[i];
    }

    FenwickTree fenwick_tree(n);
    for (int i = 0; i < n; i++) {
        fenwick_tree.update(i, initial_values[i]);
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, x;
            cin >> k >> x;
            k--; 
            ll delta = x - initial_values[k];
            initial_values[k] = x;
            fenwick_tree.update(k, delta);
        } else {
            int a, b;
            cin >> a >> b;
            a--; b--; 
            ll result = fenwick_tree.query(a, b);
            cout << result << '\n';
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
