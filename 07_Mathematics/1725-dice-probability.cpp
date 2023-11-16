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

using vld = vector<long double>;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<vld> dp(n + 1, vld(6 * n + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 6 * i; j > 0; --j) {
            for (int k = 1; k <= 6 && j - k >= 0; ++k) {
                dp[i][j] += dp[i - 1][j - k] / 6;
            }
        }
    }

    long double result = 0;
    for (int i = a; i <= b; ++i) {
        result += dp[n][i];
    }

    cout << fixed << setprecision(6) << result << '\n';
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
