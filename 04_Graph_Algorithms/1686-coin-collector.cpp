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

const int N = 1e5 + 5;

int nc = 0;
int k[N], u[N], c[N];
vector<int> adj[N], adjc[N], s;
ll dp[N];

void dfs(int i) {
    s.pb(i);
    u[i] = s.size();
    for (int j : adj[i]) {
        if (!c[j] && !u[j]) dfs(j);
        if (!c[j] && u[j]) u[i] = min(u[i], u[j]);
    }
    if (s[u[i] - 1] == i) {
        int j;
        nc++;
        do {
            j = s.back();
            c[j] = nc;
            dp[nc] += k[j];
            s.pop_back();
        } while (j != i);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> k[i];

    while (m--) {
        int i, j;
        cin >> i >> j;
        adj[i].pb(j);
    }

    for (int i = 1; i <= n; i++) {
        if (!c[i]) dfs(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            adjc[c[i]].pb(c[j]);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= nc; i++) {
        ll b = 0;
        for (int j : adjc[i])
            if (j != i)
                b = max(b, dp[j]);
        dp[i] += b;
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
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
