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
    SegmentTree(vi& arr) : n(arr.size()), arr(arr), tree(4 * n, 1) {
        build(1, 1, n);
    }

    int query(int pos) {
        return query(1, 1, n, pos);
    }

private:
    int n;
    vi &arr;
    vi tree;

    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = 1;
        } else {
            int mid = (left + right) / 2;
            build(node * 2, left, mid);
            build(node * 2 + 1, mid + 1, right);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    int query(int node, int left, int right, int pos) {
        if (left == right) {
            tree[node] = 0;
            return arr[left - 1];
        } else {
            int mid = (left + right) / 2;
            int result;
            if (tree[node * 2] >= pos) {
                result = query(node * 2, left, mid, pos);
            } else {
                result = query(node * 2 + 1, mid + 1, right, pos - tree[node * 2]);
            }
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
            return result;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    for(int &x : arr) cin >> x;

    SegmentTree st(arr);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        cout << st.query(p) << ' ';
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
