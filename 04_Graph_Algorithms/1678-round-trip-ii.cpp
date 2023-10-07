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

const int N = 1e5 + 1;

int start, finish, parent[N], visited[N];
vi result, graph[N];

void dfs(int u) {
    visited[u] = 1;
    for (int v : graph[u]) {
        if (visited[v] == 0) {
            parent[v] = u;
            dfs(v);
            if (start)
                return;
        } else if (visited[v] == 1) {
            finish = u;
            start = v;
            return;
        }
    }
    visited[u] = 2;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].pb(to);
    }

    for (int i = 1; i <= n && !start; i++)
        if (visited[i] == 0)
            dfs(i);

    if (!start) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    result.pb(start);
    for (int u = finish; u != start; u = parent[u])
        result.pb(u);
    result.pb(start);
    reverse(all(result));

    int k = (int)result.size();
    cout << k << "\n";
    for (int i = 0; i < k; i++)
        cout << result[i] << (" \n")[i == k - 1];
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
