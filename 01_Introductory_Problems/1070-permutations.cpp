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
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return;
    }

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return;
    }

    vi even, odd;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            even.pb(i);
        } else {
            odd.pb(i);
        }
    }

    for (int num : even) {
        cout << num << " ";
    }
    for (int num : odd) {
        cout << num << " ";
    }
    cout << "\n";
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
