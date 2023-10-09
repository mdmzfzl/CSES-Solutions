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

vector<vi> adj, adj_rev;
vector<bool> used;
vi order, component;

void dfs1(int v) {
    used[v] = true;
    for (int u : adj[v])
        if (!used[u])
            dfs1(u);
    order.pb(v);
}

void dfs2(int v, int id, vi& kingdom) {
    used[v] = true;
    kingdom[v] = id;
    component.pb(v);
    for (int u : adj_rev[v])
        if (!used[u])
            dfs2(u, id, kingdom);
}

void solve() {
    int n, m, a, b;
    cin >> n >> m;
    adj.resize(n);
    adj_rev.resize(n);

    while (m--) {
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj_rev[b - 1].pb(a - 1);
    }

    used.assign(n, false);
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i);

    used.assign(n, false);
    reverse(all(order));

    int id = 1;
    vi kingdom(n);

    for (int v : order) {
        if (!used[v]) {
            dfs2(v, id, kingdom);
            ++id;
            component.clear();
        }
    }

    cout << id - 1 << '\n';
    for (int i = 0; i < n; i++)
        cout << kingdom[i] << ' ';
    cout << '\n';
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
