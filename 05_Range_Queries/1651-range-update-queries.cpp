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
    ll value;
    ll lazy; 

    Node() : value(0), lazy(0) {}
};

class SegmentTree {
private:
    vector<Node> tree;
    int size;

    void push(int idx, int left, int right) {
        if (tree[idx].lazy != 0) {
            tree[idx].value += (right - left + 1) * tree[idx].lazy;

            if (left != right) {
                tree[2 * idx].lazy += tree[idx].lazy;
                tree[2 * idx + 1].lazy += tree[idx].lazy;
            }

            tree[idx].lazy = 0;
        }
    }

    void updateRange(int idx, int left, int right, int queryLeft, int queryRight, int value) {
        push(idx, left, right);

        if (queryLeft > right || queryRight < left) {
            return;
        }

        if (queryLeft <= left && queryRight >= right) {
            tree[idx].lazy += value;
            push(idx, left, right);
        } else {
            int mid = (left + right) / 2;
            updateRange(2 * idx, left, mid, queryLeft, queryRight, value);
            updateRange(2 * idx + 1, mid + 1, right, queryLeft, queryRight, value);
            tree[idx].value = tree[2 * idx].value + tree[2 * idx + 1].value;
        }
    }

    ll query(int idx, int left, int right, int queryLeft, int queryRight) {
        push(idx, left, right);

        if (queryLeft > right || queryRight < left) {
            return 0;
        }

        if (queryLeft <= left && queryRight >= right) {
            return tree[idx].value;
        }

        int mid = (left + right) / 2;
        return query(2 * idx, left, mid, queryLeft, queryRight) +
               query(2 * idx + 1, mid + 1, right, queryLeft, queryRight);
    }

public:
    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n);
    }

    void updateRange(int left, int right, int value) {
        updateRange(1, 0, size - 1, left, right, value);
    }

    ll query(int left, int right) {
        return query(1, 0, size - 1, left, right);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    SegmentTree segmentTree(n);

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        segmentTree.updateRange(i, i, num);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            segmentTree.updateRange(a - 1, b - 1, u);
        } else {
            int k;
            cin >> k;
            cout << segmentTree.query(k - 1, k - 1) << '\n';
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
