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

const ll inf = 1LL << 60;
using Graph = vector<vl>;

Graph multiply(const Graph& a, const Graph& b) {
    int n = a.size();
    Graph result(n, vl(n, inf));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                result[i][j] = min(result[i][j], a[i][k] + b[k][j]);

    return result;
}

Graph power(Graph x, ll y) {
    int n = x.size();
    Graph result(n, vl(n));

    int f = 0;
    while (y > 0) {
        if (y & 1) {
            if (f) result = multiply(result, x);
            else result = x, f = 1;
        }
        y >>= 1;
        Graph temp = x;
        x = multiply(temp, temp);
    }
    return result;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    Graph adj(n, vl(n, inf));

    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        adj[x][y] = min(adj[x][y], (ll)c);
    }

    adj = power(adj, k);

    cout << (adj[0][n - 1] < inf ? adj[0][n - 1] : -1);
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
