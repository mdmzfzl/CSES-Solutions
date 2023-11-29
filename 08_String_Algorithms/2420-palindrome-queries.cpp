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

const ll HASH = 257;

class HashTree {
private:
    int N;
    vl segtree;
    vl powh;

public:
    HashTree(int size) : N(size), segtree(2 * N, 0), powh(N, 1) {
        for (int i = 1; i < N; i++) {
            powh[i] = (powh[i - 1] * HASH) % MOD;
        }
    }

    void update(int i, ll v) {
        for (segtree[i += N] = v; i > 1; i >>= 1) {
            segtree[i >> 1] = (segtree[i] + segtree[i ^ 1]) % MOD;
        }
    }

    ll query(int l, int r) const {
        ll res = 0;
        for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = (res + segtree[l++]) % MOD;
            if (r & 1) res = (res + segtree[--r]) % MOD;
        }
        return res;
    }

    ll getPower(int i) const {
        return powh[i];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    HashTree fhash(n);
    HashTree bhash(n);

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        fhash.update(i, fhash.getPower(i) * (ll)(c) % MOD);
        bhash.update(i, bhash.getPower(n - i - 1) * (ll)(c) % MOD);
    }

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k;
            char c;
            cin >> k >> c;
            k--;
            fhash.update(k, fhash.getPower(k) * (ll)(c) % MOD);
            bhash.update(k, bhash.getPower(n - k - 1) * (ll)(c) % MOD);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            ll forward = fhash.query(l, r);
            forward = (forward * fhash.getPower(n - 1 - r)) % MOD;
            ll backward = bhash.query(l, r);
            backward = (backward * bhash.getPower(l)) % MOD;
            cout << (forward == backward ? "YES\n" : "NO\n");
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
