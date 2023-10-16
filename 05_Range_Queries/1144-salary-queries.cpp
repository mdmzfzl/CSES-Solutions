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

const int MAX_N = 1e6 + 5;

void update(int i, int x, vi& bit) {
    while (i <= MAX_N) {
        bit[i] += x;
        i += i & -i;
    }
}

int get(int i, const vi& bit) {
    int t = 0;
    while (i) {
        t += bit[i];
        i -= i & -i;
    }
    return t;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi p(n + 1);
    vi bit(MAX_N);
    vector<tuple<char, int, int>> queries(q);

    vi bit_map;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        bit_map.pb(p[i]);
    }

    for (auto& [type, a, b] : queries) {
        cin >> type >> a >> b;
        bit_map.pb(b);
        if (type == '?') {
            bit_map.pb(a);
        }
    }

    sort(all(bit_map));

    for (int i = 1; i <= n; ++i) {
        p[i] = lower_bound(all(bit_map), p[i]) - bit_map.begin() + 1;
    }

    for (auto& [type, a, b] : queries) {
        if (type == '?') {
            a = lower_bound(all(bit_map), a) - bit_map.begin() + 1;
        }
        b = lower_bound(all(bit_map), b) - bit_map.begin() + 1;
    }

    for (int i = 1; i <= n; ++i) {
        update(p[i], 1, bit);
    }

    for (auto& [type, u, v] : queries) {
        if (type == '?') {
            cout << get(v, bit) - get(u - 1, bit) << '\n';
        } else {
            update(p[u], -1, bit);
            update(v, 1, bit);
            p[u] = v;
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
