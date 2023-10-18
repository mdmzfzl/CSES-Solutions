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
    SegmentTree(const vi& arr) {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 1, 0, size - 1);
    }

    void update(int left, int right) {
        update(1, 0, size - 1, left, right);
    }

    ll query(int left, int right) {
        return query(1, 0, size - 1, left, right).sum;
    }

private:
    struct Node {
        ll sum, lazyC, lazyD;
        Node() : sum(0), lazyC(0), lazyD(0) {}
        Node(ll x) : sum(x), lazyC(0), lazyD(0) {}
        Node(const Node& left, const Node& right) {
            sum = left.sum + right.sum;
            lazyC = 0;
            lazyD = 0;
        }
    };

    int size;
    vector<Node> tree;

    void apply(int node, int start, int end, ll constant, ll delta) {
        ll length = end - start + 1;
        ll apSum = length * (length + 1) / 2;
        tree[node].sum += length * constant + apSum * delta;
        tree[node].lazyC += constant;
        tree[node].lazyD += delta;
    }

    void propagate(int node, int start, int end) {
        if (start == end) return;
        int mid = (start + end) / 2;
        apply(2 * node, start, mid, tree[node].lazyC, tree[node].lazyD);
        apply(2 * node + 1, mid + 1, end, tree[node].lazyC + tree[node].lazyD * (mid + 1 - start), tree[node].lazyD);
        tree[node].lazyC = 0;
        tree[node].lazyD = 0;
    }

    void build(const vi& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = Node(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int left, int right) {
        propagate(node, start, end);
        if (right < start || end < left) return;
        if (left <= start && end <= right) {
            apply(node, start, end, start - left, 1);
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, left, right);
        update(2 * node + 1, mid + 1, end, left, right);
        tree[node] = Node(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int left, int right) {
        propagate(node, start, end);
        if (right < start || end < left) return Node();
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return Node(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for (int &x : arr) cin >> x;
    SegmentTree st(arr);

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--; r--;
        if (t == 1) {
            st.update(l, r);
        } else {
            cout << st.query(l, r) << "\n";
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
