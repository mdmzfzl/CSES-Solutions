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
    int n, m;
    cin >> n >> m;
    vi x(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<vi> dp(n, vi(m + 1, 0));

    for (int i = 1; i <= m; ++i) {
        if (x[0] == 0 || x[0] == i) {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == 0 || x[i] == j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    int result = 0;

    for (int i = 1; i <= m; ++i) {
        result = (result + dp[n - 1][i]) % MOD;
    }

    cout << result << '\n';
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
