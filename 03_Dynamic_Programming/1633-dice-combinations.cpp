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

    vi dp(n + 1, 0);

    dp[0] = 1;

    for (int sum = 1; sum <= n; sum++) {
        for (int roll = 1; roll <= 6; roll++) {
            if (roll <= sum) {
                dp[sum] = (dp[sum] + dp[sum - roll]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";
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
