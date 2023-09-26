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
    int a = 1, b = 0;
 
    while (n > 0) {
        for (int i = 2; i <= n; i += 2) {
            cout << (a * i + b) << ' ';
        }
 
        if (n & 1) {
            cout << (a + b) << ' ';
            b += a;
        } else {
            b -= a;
        }
 
        a <<= 1;
        n >>= 1;
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
