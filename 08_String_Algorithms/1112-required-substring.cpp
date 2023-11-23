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

void KMP(const string &s, vi &kmp) {
    kmp[0] = 0;
    for (size_t i = 1; i < s.size(); i++) {
        int trymatch = kmp[i - 1];
        while (trymatch > 0 && s[trymatch] != s[i]) {
            trymatch = kmp[trymatch - 1];
        }
        kmp[i] = (s[trymatch] == s[i]) ? trymatch + 1 : 0;
    }
}

ll calc(int i, int n, int j, const string &s, const vi &kmp) {
    static vector<vl> dp(1001, vl(101, -1));
    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == n)
        return dp[i][j] = (j == (int)s.size()) ? 1 : 0;

    if (j == (int)s.size())
        return dp[i][j] = (26 * calc(i + 1, n, j, s, kmp)) % MOD;

    ll ans = 0;
    for (int k = 0; k < 26; k++) {
        int t = j;
        while (t > 0 && k != s[t] - 'A') {
            t = kmp[t - 1];
        }
        t += (k == s[t] - 'A') ? 1 : 0;
        ans += calc(i + 1, n, t, s, kmp);
        ans %= MOD;
    }
    return dp[i][j] = ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi kmp(n);
    KMP(s, kmp);
    cout << calc(0, n, 0, s, kmp) << '\n';
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
