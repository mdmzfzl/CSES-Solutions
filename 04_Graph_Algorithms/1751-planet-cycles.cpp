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

const int MAX_N = 2e5 + 5;
int parent[MAX_N], depth[MAX_N], cycle[MAX_N];

void dfs(int u, int d = 0) {
    cycle[u] = --d;
    int v = parent[u];
    if (cycle[v] == 0) {
        dfs(v, d);
    }
    if (cycle[v] < 0) {
        cycle[u] = cycle[v] - cycle[u] + 1;
        depth[u] = cycle[u];
        while (v != u) {
            depth[v] = cycle[v] = cycle[u];
            v = parent[v];
        }
    } else if (cycle[u] != cycle[v]) {
        cycle[u] = cycle[v];
        depth[u] = depth[v] + 1;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
    }

    for (int i = 1; i <= n; i++) {
        if (cycle[i] == 0) {
            dfs(i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << depth[i] << " ";
    }
    cout << "\n";
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
