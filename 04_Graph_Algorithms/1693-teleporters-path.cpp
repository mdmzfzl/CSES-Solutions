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

void dfs(int x, vector<vi> &v, vi &result) {
    while (v[x].size()) {
        int j = v[x][v[x].size() - 1];
        v[x].pop_back();
        dfs(j, v, result);
    }
    result.pb(x + 1);
    return;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int vis[n] = {0};
    vector<vi> v(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].pb(b);
        vis[a]++; vis[b]--;
    }

    if (vis[0] != 1 || vis[n - 1] != (-1)) {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        if (vis[i] != 0) {
            cout << "IMPOSSIBLE";
            return;
        }
    }

    vi result;
    dfs(0, v, result);

    if (int(result.size()) != m + 1) {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";
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
