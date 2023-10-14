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

const int MAX_N = 501;

int n, m, mch[MAX_N];
int vis[MAX_N], t = 0;
vi adj[MAX_N];

bool matching(int u) {
    if (vis[u] != t) 
        vis[u] = t;
    else 
        return false;

    for (int v : adj[u]) {
        if (!mch[v] || matching(mch[v])) {
            mch[v] = u;
            return true;
        }
    }

    return false;
}

void solve() {
    int k;
    cin >> n >> m >> k;

    while (k--) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        ++t;
        cnt += matching(i);
    }

    cout << cnt << '\n';
    
    for (int i = 1; i <= m; ++i) {
        if (mch[i]) {
            cout << mch[i] << ' ' << i << '\n';
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
