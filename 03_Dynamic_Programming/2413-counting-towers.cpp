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

const int N = 1e6 + 1;
vector<vi> dp(N, vi(2));

void preprocess() {
    dp[1] = {1, 1};
    for (int i = 2; i < N; ++i) {
        dp[i][0] = (4LL * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (2LL * dp[i - 1][1] + dp[i - 1][0]) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;

    cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
}

int main() {
    fastio

    int tc = 1; // Number of test cases
    cin >> tc;

    preprocess();
    while (tc--) {
        solve();
    }

    return 0;
}
