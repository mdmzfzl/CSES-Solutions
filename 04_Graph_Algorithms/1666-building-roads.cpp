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

vector<vi> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    visited.assign(n, false);

    vector<pii> roads;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        roads.pb({a, b});
    }

    vector<pii> new_roads;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (i > 0) {
                new_roads.pb({i - 1, i});
            }
            dfs(i);
        }
    }

    cout << new_roads.size() << "\n";
    for (auto road : new_roads) {
        cout << road.first + 1 << " " << road.second + 1 << "\n"; 
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
