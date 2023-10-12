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

const int N = 1e6 + 6;

vi g[N], rg[N];
int component[N];

void topoSort(int u, vi& topoOrder, bool visited[]) {
    visited[u] = true;
    for (int v : g[u])
        if (!visited[v])
            topoSort(v, topoOrder, visited);
    topoOrder.pb(u);
}

void dfs(int u, int val) {
    component[u] = val;
    for (int v : rg[u])
        if (!component[v])
            dfs(v, val);
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        char x, y;
        int a, b, na, nb;
        cin >> x >> a >> y >> b;
        a = (a * 2) ^ (x == '-');
        b = (b * 2) ^ (y == '-');
        na = a ^ 1;
        nb = b ^ 1;

        g[na].pb(b);
        g[nb].pb(a);
        rg[a].pb(nb);
        rg[b].pb(na);
    }

    vi topoOrder;
    bool visited[N] = {false};
    for (int i = 2; i <= m * 2 + 1; i++)
        if (!visited[i])
            topoSort(i, topoOrder, visited);
    reverse(all(topoOrder));

    for (size_t i = 0, cnt = 1; i < topoOrder.size(); i++) {
        int u = topoOrder[i];
        if (!component[u])
            dfs(u, cnt++);
    }

    char result[N];
    for (int i = 2; i <= 2 * m; i += 2) {
        if (component[i] == component[i + 1]) {
            cout << "IMPOSSIBLE";
            return;
        }
        result[i / 2] = (component[i] > component[i + 1] ? '+' : '-');
    }

    for (int i = 1; i <= m; i++)
        cout << result[i] << ' ';
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
