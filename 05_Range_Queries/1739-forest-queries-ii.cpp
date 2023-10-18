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

template <typename T>
struct Fenwick2D {
    int rows, cols;
    vector<vector<T>> tree;

    Fenwick2D(int _rows, int _cols) : rows(_rows), cols(_cols), tree(_rows + 1, vector<T>(_cols + 1)) {}

    void update(int x, int y, T val) {
        for (int tx = x; tx <= rows; tx += tx & -tx)
            for (int ty = y; ty <= cols; ty += ty & -ty)
                tree[tx][ty] += val;
    }

    T query(int x, int y) {
        T result = 0;
        for (int tx = x; tx; tx -= tx & -tx)
            for (int ty = y; ty; ty -= ty & -ty)
                result += tree[tx][ty];
        return result;
    }

    T query(int x1, int y1, int x2, int y2) {
        return (x1 <= x2 && y1 <= y2) ? query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1) : 0;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Fenwick2D<ll> fenwick(n, n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '*') fenwick.update(i, j, 1);
        }
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            fenwick.update(i, j, (fenwick.query(i, j, i, j) ? -1 : 1));
        } else {
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            cout << fenwick.query(i1, j1, i2, j2) << '\n';
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
