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
const int MAX_L = 30;

int parent[MAX_N][MAX_L];
int depth[MAX_N], cycle[MAX_N];

void dfs(int u, int d = 0) {
    cycle[u] = --d;
    int parentPlanet = parent[u][0];
    if (cycle[parentPlanet] == 0) {
        dfs(parentPlanet, d);
    }
    if (cycle[parentPlanet] < 0) {
        cycle[u] = cycle[parentPlanet] - cycle[u] + 1;
        depth[u] = 0;
    } else {
        cycle[u] = cycle[parentPlanet];
        depth[u] = depth[parentPlanet] + 1;
    }
}

int jump(int a, int k) {
    for (int i = 0; i < MAX_L; i++) {
        if (k & (1 << i)) {
            a = parent[a][i];
        }
    }
    return a;
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> parent[i][0];
    }
    for (int i = 1; i < MAX_L; i++) {
        for (int planet = 1; planet <= n; planet++) {
            parent[planet][i] = parent[parent[planet][i - 1]][i - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cycle[i] == 0) {
            dfs(i);
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (depth[a] >= depth[b] && jump(a, depth[a] - depth[b]) == b) {
            cout << depth[a] - depth[b] << "\n";
        } else if (depth[a] + cycle[a] >= depth[b] && jump(a, depth[a] + cycle[a] - depth[b]) == b) {
            cout << depth[a] + cycle[a] - depth[b] << "\n";
        } else {
            cout << -1 << "\n";
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
