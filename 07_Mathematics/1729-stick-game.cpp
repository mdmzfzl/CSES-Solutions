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
    int n, k;
    cin >> n >> k;

    vi p(k + 1);
    vector<bool> dp(n + 1, false);

    for (int i = 1; i <= k; i++) {
        cin >> p[i];
        dp[p[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        cout << (dp[i] ? "W" : "L");

        if (!dp[i]) {
            for_each(p.begin() + 1, p.end(), [&](int j) {
                if (i + j <= n) {
                    dp[i + j] = true;
                }
            });
        }
    }
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
