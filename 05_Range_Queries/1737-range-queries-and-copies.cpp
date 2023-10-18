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
    struct Node {
        Node* left = nullptr;
        Node* right = nullptr;
        ll sum;

        Node() : sum(0) {}
        Node(ll x) : sum(x) {}
        Node(Node* ln, Node* rn, ll x) : left(ln), right(rn), sum(x) {}
        Node(const Node& l, const Node& r) : sum(l.sum + r.sum) {}
    };

public:
    int n, ver;
    vector<Node*> st;

    SegmentTree(int _n) : n(_n), ver(0), st(1, new Node()) {}

    void build(vector<int>& a, Node* node, int start, int end) {
        if (start == end) {
            *node = Node(a[start]);
            return;
        }
        node->left = new Node();
        node->right = new Node();
        int mid = (start + end) / 2;
        build(a, node->left, start, mid);
        build(a, node->right, mid + 1, end);
        node->sum = node->left->sum + node->right->sum;
    }

    void update(Node* node, int start, int end, int i, ll x) {
        if (start == end) {
            node->sum = x;
            return;
        }
        int mid = (start + end) / 2;
        if (i <= mid) {
            node->left = new Node(*node->left);
            update(node->left, start, mid, i, x);
        } else {
            node->right = new Node(*node->right);
            update(node->right, mid + 1, end, i, x);
        }
        node->sum = node->left->sum + node->right->sum;
    }

    Node query(Node* node, int start, int end, int l, int r) {
        if (r < start || end < l) return Node();
        if (l <= start && end <= r) return *node;
        int mid = (start + end) / 2;
        return Node(query(node->left, start, mid, l, r), query(node->right, mid + 1, end, l, r));
    }

    void update(int k, int i, ll x) { update(st[k], 0, n - 1, i, x); }
    Node query(int k, int l, int r) { return query(st[k], 0, n - 1, l, r); }
    void copy(int k) { st.push_back(new Node(*st[k])); }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    SegmentTree st(n);
    st.build(a, st.st[0], 0, a.size() - 1);
    
    while (q--) {
        int t, k;
        cin >> t >> k;
        k--;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            st.update(k, i, x);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.query(k, l, r).sum << "\n";
        } else {
            st.copy(k);
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
