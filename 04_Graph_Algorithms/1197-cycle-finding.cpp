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

struct Edge {
    int a, b, cost;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.pb({a - 1, b - 1, c});
    }

    vl dist(n);
    vi prev(n, -1);
    int start;

    for (int i = 0; i < n; ++i) {
        start = -1;
        for (Edge e : edges) {
            if (dist[e.a] + e.cost < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.cost;
                prev[e.b] = e.a;
                start = e.b;
            }
        }
    }

    if (start == -1) {
        cout << "NO";
    } else {
        for (int i = 0; i < n; ++i) {
            start = prev[start];
        }

        vi cycle;
        for (int v = start;; v = prev[v]) {
            cycle.pb(v);
            if (v == start && cycle.size() > 1)
                break;
        }
        reverse(all(cycle));

        cout << "YES\n";
        for (int v : cycle) {
            cout << v + 1 << ' ';
        }
        cout << "\n";
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
