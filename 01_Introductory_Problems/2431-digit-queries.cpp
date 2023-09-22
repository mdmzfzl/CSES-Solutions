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

ll findDigit(ll k) {
    ll digitCount = 1;

    while (digitCount * ((ll)pow(10, digitCount - 1)) * 9 < k) {
        k = k - digitCount * ((ll)pow(10, digitCount - 1)) * 9;
        digitCount++;
    }

    ll number = (ll)pow(10, digitCount - 1) + (k - 1) / digitCount;
    string numberStr = to_string(number);
    ll result = (ll)(numberStr[(k - 1) % digitCount] - '0');
    
    return result;
}

void solve() {
    ll k;
    cin >> k;
    cout << findDigit(k) << "\n";
}

int main() {
    fastio

    int tc = 1; // Number of test cases
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
