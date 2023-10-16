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
public:
    SegmentTree(int _n) : n(_n), st(4 * _n, LLONG_MIN) {}

    SegmentTree(const vi& arr) : n(arr.size()), st(4 * n, LLONG_MIN) {
        build(arr, 1, 0, n - 1);
    }

    void update(int i, ll x) {
        update(1, 0, n - 1, i, x);
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    int find(ll x) {
        return find(1, 0, n - 1, x);
    }

private:
    int n;
    vector<ll> st;

    void build(const vi& arr, int node, int start, int end) {
        if (start == end) {
            st[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        st[node] = max(st[2 * node], st[2 * node + 1]);
    }

    void update(int node, int start, int end, int i, ll x) {
        if (start == end) {
            st[node] += x;
            return;
        }
        int mid = (start + end) / 2;
        if (i <= mid) {
            update(2 * node, start, mid, i, x);
        } else {
            update(2 * node + 1, mid + 1, end, i, x);
        }
        st[node] = max(st[2 * node], st[2 * node + 1]);
    }

    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return LLONG_MIN;
        if (l <= start && end <= r) return st[node];
        int mid = (start + end) / 2;
        ll left = query(2 * node, start, mid, l, r);
        ll right = query(2 * node + 1, mid + 1, end, l, r);
        return max(left, right);
    }

    int find(int node, int start, int end, ll x) {
        if (start == end) return st[node] < x ? -1 : start;
        int mid = (start + end) / 2;
        if (st[2 * node] < x) return find(2 * node + 1, mid + 1, end, x);
        else return find(2 * node, start, mid, x);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for (int &x : arr) cin >> x;

    SegmentTree st(arr);

    while (q--) {
        ll x;
        cin >> x;
        int i = st.find(x);
        if (i != -1) {
            st.update(i, -x);
        }
        cout << i + 1 << " ";
    }
    cout << "\n";
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
