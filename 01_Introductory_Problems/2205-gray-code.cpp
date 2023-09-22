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

    // Calculate the total number of Gray codes.
    ll totalCodes = 1LL << n;

    // Generate and print the Gray codes.
    for (ll i = 0; i < totalCodes; i++) {
        ll grayCode = i ^ (i >> 1);
        bitset<20> binary(grayCode);
        string grayString = binary.to_string().substr(20 - n);
        cout << grayString << "\n";
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
