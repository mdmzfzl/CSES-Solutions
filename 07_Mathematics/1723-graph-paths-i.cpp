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

using Graph = vector<vl>;

Graph multiply(const Graph& a, const Graph& b) {
    ll n = a.size();
    ll m = b[0].size();
    ll p = b.size();
    
    Graph result(n, vl(m, 0));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            for (ll k = 0; k < p; ++k) {
                result[i][j] = (result[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }

    return result;
}

Graph power(const Graph& base, ll exp) {
    ll n = base.size();
    Graph result(n, vl(n, 0));

    for (ll i = 0; i < n; ++i) {
        result[i][i] = 1; 
    }

    Graph temp = base;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, temp);
        }
        temp = multiply(temp, temp);
        exp /= 2;
    }

    return result;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    Graph adj(n, vl(n));

    for (ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x - 1][y - 1]++;
    }

    Graph result = power(adj, k);

    cout << result[0][n - 1];
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
