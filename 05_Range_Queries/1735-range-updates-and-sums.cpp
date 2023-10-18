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
    SegmentTree(const vi& data) {
        size = data.size();
        tree.resize(4 * size);
        build(data, 1, 0, size - 1);
    }

    void updateAdd(int left, int right, ll value) {
        updateAdd(1, 0, size - 1, left, right, value);
    }

    void updateSet(int left, int right, ll value) {
        updateSet(1, 0, size - 1, left, right, value);
    }

    ll query(int left, int right) {
        return query(1, 0, size - 1, left, right).totalSum;
    }

private:
    struct Node {
        ll totalSum, addValue, setValue;
        Node() : totalSum(0), addValue(0), setValue(LLINF) {}
        Node(ll x) : totalSum(x), addValue(0), setValue(LLINF) {}
        Node(const Node& leftNode, const Node& rightNode) {
            totalSum = leftNode.totalSum + rightNode.totalSum;
            addValue = 0;
            setValue = LLINF;
        }
    };

    int size;
    vector<Node> tree;

    void build(const vi& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = Node(data[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(data, 2 * node, start, mid);
        build(data, 2 * node + 1, mid + 1, end);
        tree[node] = Node(tree[2 * node], tree[2 * node + 1]);
    }

    void updateAdd(int node, int start, int end, int left, int right, ll value) {
        pushDown(node, start, end);
        if (right < start || end < left) return;
        if (left <= start && end <= right) {
            tree[node].totalSum += value * (end - start + 1);
            tree[node].addValue += value;
            return;
        }
        int mid = (start + end) / 2;
        updateAdd(2 * node, start, mid, left, right, value);
        updateAdd(2 * node + 1, mid + 1, end, left, right, value);
        tree[node] = Node(tree[2 * node], tree[2 * node + 1]);
    }

    void updateSet(int node, int start, int end, int left, int right, ll value) {
        pushDown(node, start, end);
        if (right < start || end < left) return;
        if (left <= start && end <= right) {
            tree[node].totalSum = value * (end - start + 1);
            tree[node].setValue = value;
            tree[node].addValue = 0;
            return;
        }
        int mid = (start + end) / 2;
        updateSet(2 * node, start, mid, left, right, value);
        updateSet(2 * node + 1, mid + 1, end, left, right, value);
        tree[node] = Node(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int start, int end, int left, int right) {
        pushDown(node, start, end);
        if (right < start || end < left) return Node();
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) / 2;
        return Node(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
    }

    void pushDown(int node, int start, int end) {
        if (start == end) return;
        int mid = (start + end) / 2;
        applySet(2 * node, start, mid, tree[node].setValue);
        applySet(2 * node + 1, mid + 1, end, tree[node].setValue);
        applyAdd(2 * node, start, mid, tree[node].addValue);
        applyAdd(2 * node + 1, mid + 1, end, tree[node].addValue);
        tree[node].addValue = 0;
        tree[node].setValue = LLINF;
    }

    void applyAdd(int node, int start, int end, ll value) {
        if (value == 0) return;
        tree[node].totalSum += value * (end - start + 1);
        tree[node].addValue += value;
    }

    void applySet(int node, int start, int end, ll value) {
        if (value == LLINF) return;
        tree[node].totalSum = value * (end - start + 1);
        tree[node].setValue = value;
        tree[node].addValue = 0;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int &x : a) cin >> x;
    SegmentTree st(a);

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        l--; r--;
        
        if (t == 1) {
            int x;
            cin >> x;
            st.updateAdd(l, r, x);
        } else if (t == 2) {
            int x;
            cin >> x;
            st.updateSet(l, r, x);
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
