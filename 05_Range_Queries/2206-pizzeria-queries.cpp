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
    vi st;
public:
    SegmentTree(int _n) : n(_n), st(2 * _n) {}

    SegmentTree(const vi& a) : n(a.size()), st(2 * a.size()) {
        for (int i = 0; i < n; i++)
            st[i + n] = a[i];
        for (int i = n - 1; i > 0; i--)
            st[i] = min(st[i << 1], st[i << 1 | 1]);
    }

    int query(int l, int r) {
        int res = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = min(res, st[l++]);
            if (r & 1)
                res = min(res, st[--r]);
        }
        return res;
    }

    void update(int i, int x) {
        for (st[i += n] = x; i > 1; i >>= 1)
            st[i >> 1] = min(st[i], st[i ^ 1]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n), a1(n), a2(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a1[i] = a[i] + i;
        a2[i] = a[i] - i;
    }
    SegmentTree st1(a1);
    SegmentTree st2(a2);

    while (q--) {
        int t, i;
        cin >> t >> i;
        i--;

        if (t == 1) {
            int x;
            cin >> x;
            a[i] = x;
            a1[i] = a[i] + i;
            a2[i] = a[i] - i;
            st1.update(i, a1[i]);
            st2.update(i, a2[i]);
        } else {
            int result = min(st1.query(i, n) - i, st2.query(0, i + 1) + i);
            cout << result << "\n";
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
