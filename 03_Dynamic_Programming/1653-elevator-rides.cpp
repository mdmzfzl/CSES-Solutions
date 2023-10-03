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
const int INF = 1e9;
const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vi weights(n);
    for (int &weight : weights) cin >> weight;

    vector<pii> dp(1 << n, {INF, INF});
    dp[0] = {0, 0};

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;

            int new_mask = mask | (1 << i);
            if (dp[mask].second + weights[i] > m) {
                dp[new_mask] = min(dp[new_mask], {dp[mask].first + 1, weights[i]});
            } else {
                dp[new_mask] = min(dp[new_mask], {dp[mask].first, dp[mask].second + weights[i]});
            }
        }
    }

    auto [ans, cur] = dp.back();
    if (cur > 0) ans++;
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
