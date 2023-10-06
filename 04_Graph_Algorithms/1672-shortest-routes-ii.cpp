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

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vl> dist(n + 1, vl(n + 1, LLINF));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w);
        dist[b][a] = min(dist[b][a], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != LLINF && dist[k][j] != LLINF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        ll ans = (dist[a][b] == LLINF) ? -1 : dist[a][b];
        cout << ans << "\n";
    }
}

int main() {
    fastio

    int tc = 1;

    while (tc--) {
        solve();
    }

    return 0;
}
