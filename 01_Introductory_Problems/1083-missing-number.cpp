#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
    int n;
    cin >> n;
    ll expected_sum = (ll)n * (n + 1) / 2;
    ll actual_sum = 0;

    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        actual_sum += num;
    }

    cout << expected_sum - actual_sum << "\n";
}

int main() {
    fastio;

    int tc = 1; // Number of test cases
    // cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
