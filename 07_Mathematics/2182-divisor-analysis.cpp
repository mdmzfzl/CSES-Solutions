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

ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;

    ll counts[3] = {1, 1, 1};
    int flag = 0;
    ll sq = 1, num = 1, d = 1;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        counts[0] = (counts[0] * (y + 1)) % MOD;

        ll gsum = (modPow(x, y + 1, MOD) - 1 + MOD) % MOD * modPow(x - 1, MOD - 2, MOD) % MOD;
        counts[1] = (counts[1] * gsum) % MOD;

        sq = (sq * modPow(x, y / 2, MOD)) % MOD;
        num = (num * modPow(x, y, MOD)) % MOD;

        if ((y & 1) && flag == 0) {
            d = (d * ((y + 1) / 2)) % (MOD - 1);
            flag = 1;
        } else {
            d = (d * (y + 1)) % (MOD - 1);
        }
    }

    counts[2] = (flag == 1) ? modPow(num, d, MOD) : modPow(sq, d, MOD);

    cout << counts[0] << ' ' << counts[1] << ' ' << counts[2] << '\n';
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
