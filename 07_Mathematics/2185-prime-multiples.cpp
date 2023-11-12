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

ll calc(ll n, int k, const vl &a) {
    ll result = 0;

    for (int mask = 1; mask < (1 << k); ++mask) {
        long double product = 1;
        int sign = -1;

        for (int i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                if (product > (n + a[i] - 1) / a[i]) {
                    product = -1;
                    break;
                }
                product *= a[i];
                sign *= -1;
            }
        }

        if (product != -1) {
            result += n / static_cast<ll>(product) * sign;
        }
    }

    return result;
}

void solve() {
    ll n;
    int k;
    cin >> n >> k;

    vl a(k);
    for (ll &x : a) cin >> x;

    ll result = calc(n, k, a);
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
