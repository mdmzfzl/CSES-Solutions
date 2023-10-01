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
    int n, x;
    cin >> n >> x;

    vi coins(n);
    vi dp(x + 1, MOD);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 0;

    for (int sum = 1; sum <= x; sum++) {
        for (int coin : coins) {
            if (sum - coin >= 0) {
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
            }
        }
    }

    int result = (dp[x] == MOD) ? -1 : dp[x];
    cout << result << "\n";
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
