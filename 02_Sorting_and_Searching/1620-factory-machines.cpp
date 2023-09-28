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

bool canAchieve(const vi& a, ll m, ll mid) {
    ll total = 0;
    for (int x : a) {
        total += mid / x;
        if (total >= m) return true;
    }
    return false;
}

ll binarySearch(const vi& a, ll m) {
    ll lo = 0, hi = LLINF;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (canAchieve(a, m, mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int& x : a) cin >> x;

    ll minTime = binarySearch(a, m);
    cout << minTime << "\n";
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
