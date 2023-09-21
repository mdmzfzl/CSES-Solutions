#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    ll n;
    cin >> n;

    for (ll k = 1; k <= n; k++) {
        ll total_positions = k * k;
        ll attacking_positions = 4 * (k - 1) * (k - 2);

        if (k == 1) {
            cout << 0 << "\n";
        } else if (k == 2) {
            cout << 6 << "\n";
        } else {
            cout << total_positions * (total_positions - 1) / 2 - attacking_positions << "\n";
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