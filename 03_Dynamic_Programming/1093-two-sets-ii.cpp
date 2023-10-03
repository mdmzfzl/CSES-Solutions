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
    int n;
    cin >> n;

    const ll total_sum = (1LL * n * (n + 1)) / 2;

    if (total_sum % 2 != 0) {
        cout << "0\n";
        return;
    }

    vector<vl> dp(n + 1, vl(total_sum / 2 + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= total_sum / 2; j++) {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if (left >= 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][left]) % MOD;
            }
        }
    }

    cout << (dp[n][total_sum / 2] * ((MOD + 1) / 2)) % MOD << "\n";
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
