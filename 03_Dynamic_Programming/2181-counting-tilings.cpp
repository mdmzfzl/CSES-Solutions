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

void calculate(int i, int j, int mask, int new_mask, vector<vi> &dp, int n) {
    if (j == n) {
        dp[i + 1][new_mask] += dp[i][mask];
        if (dp[i + 1][new_mask] >= MOD) dp[i + 1][new_mask] -= MOD;
        return;
    }

    if (mask & (1 << j)) {
        calculate(i, j + 1, mask, new_mask, dp, n);
    } else {
        if (j < n - 1 && !(mask & (1 << (j + 1)))) {
            calculate(i, j + 2, mask, new_mask, dp, n);
        }
        calculate(i, j + 1, mask, new_mask | (1 << j), dp, n);
    }
}

void solve(int tc = 0) {
    int n, m;
    cin >> n >> m;

    vector<vi> dp(m + 1, vi(1 << n));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            calculate(i, 0, mask, 0, dp, n);
        }
    }
    cout << dp[m][0] << "\n";
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
