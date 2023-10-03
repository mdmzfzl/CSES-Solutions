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

    vi a(n);
    for (int &x : a) cin >> x;

    vl dp(n);
    ll sum = 0;

    for (int i = n - 1; i >= 0; i--) {
        sum += a[i]; 
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[j] = a[i];
            } else {
                dp[j] = max(a[i] - dp[j], a[j] - dp[j - 1]);
            }
        }
    }

    cout << (sum + dp[n - 1]) / 2 << "\n";
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
