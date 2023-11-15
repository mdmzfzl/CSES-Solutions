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

ll power(ll a, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b & 1)
            ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}

ll inverse(ll a) {
    return power(a, MOD - 2);
}

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

void solve() {
    ll n;
    cin >> n;

    ll deg0 = power(2, n * n);
    ll deg90 = power(2, (n % 2) ? (n * n - 1) / 4 + 1 : n * n / 4);
    ll deg180 = power(2, (n % 2) ? (n * n - 1) / 2 + 1 : n * n / 2);
    ll deg270 = power(2, (n % 2) ? (n * n - 1) / 4 + 1 : n * n / 4);
    
    ll result = add(deg0, add(deg90, add(deg180, deg270)));
    result = (result * inverse(4)) % MOD;

    cout << result << '\n';
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
