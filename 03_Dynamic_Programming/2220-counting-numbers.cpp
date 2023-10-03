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

ll dp[20][10][2][2];

ll countValidNums(string s, size_t pos, int prev, bool smaller, bool non_zero) {
    if (pos == s.length()) {
        return non_zero ? 1 : 0;
    }
    
    if (dp[pos][prev][smaller][non_zero] != -1) {
        return dp[pos][prev][smaller][non_zero];
    }

    int limit = smaller ? 9 : s[pos] - '0';
    ll count = 0;

    for (int digit = 0; digit <= limit; digit++) {
        bool new_smaller = smaller || (digit < limit);
        bool new_non_zero = non_zero || (digit > 0);
        
        if (digit != prev || (digit == 0 && !new_non_zero)) {
            count += countValidNums(s, pos + 1, digit, new_smaller, new_non_zero);
        }
    }

    return dp[pos][prev][smaller][non_zero] = count;
}

ll countNumsInRange(ll a, ll b) {
    if (a > b) {
        return 0;
    }

    string strA = to_string(a - 1);
    string strB = to_string(b);

    memset(dp, -1, sizeof(dp));
    ll countB = countValidNums(strB, 0, 0, false, false);

    if (a == 0) {
        return countB + 1;
    }

    memset(dp, -1, sizeof(dp));
    ll countA = countValidNums(strA, 0, 0, false, false);

    return countB - countA;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    cout << countNumsInRange(a, b) << "\n";
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
