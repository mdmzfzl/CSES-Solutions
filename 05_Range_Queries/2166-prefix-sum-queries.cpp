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

struct Node {
    ll sum = 0;
    ll pre = 0;

    Node() = default;
    Node(ll x) : sum(x), pre(max(0ll, x)) {}
    Node(const Node& l, const Node& r) : sum(l.sum + r.sum), pre(max(l.pre, l.sum + r.pre)) {}
};

class SegmentTree {
public:
    SegmentTree(const vl& a) : n(a.size()), st(4 * n) {
        build(a, 1, 0, n - 1);
    }

    void update(int i, ll x) {
        update(1, 0, n - 1, i, x);
    }

    Node query(int l, int r) const {
        return query(1, 0, n - 1, l, r);
    }

private:
    int n;
    vector<Node> st;

    int leftChild(int node) const {
        return 2 * node;
    }

    int rightChild(int node) const {
        return 2 * node + 1;
    }

    void build(const vl& a, int node, int start, int end) {
        if (start == end) {
            st[node] = Node(a[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(a, leftChild(node), start, mid);
        build(a, rightChild(node), mid + 1, end);
        st[node] = Node(st[leftChild(node)], st[rightChild(node)]);
    }

    void update(int node, int start, int end, int i, ll x) {
        if (start == end) {
            st[node] = Node(x);
            return;
        }
        int mid = (start + end) / 2;
        if (i <= mid) {
            update(leftChild(node), start, mid, i, x);
        } else {
            update(rightChild(node), mid + 1, end, i, x);
        }
        st[node] = Node(st[leftChild(node)], st[rightChild(node)]);
    }

    Node query(int node, int start, int end, int l, int r) const {
        if (r < start || end < l) return Node();
        if (l <= start && end <= r) return st[node];
        int mid = (start + end) / 2;
        return Node(query(leftChild(node), start, mid, l, r), query(rightChild(node), mid + 1, end, l, r));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vl a(n);
    for(auto &x: a) cin >> x;
    SegmentTree st(a);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            st.update(i, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << st.query(l, r).pre << "\n";
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
