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

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll maxSum = LLONG_MIN; // Initialize with the smallest possible value
    ll currentSum = 0;

    for (int i = 0; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]); // Choose between starting a new subarray or extending the current one
        maxSum = max(maxSum, currentSum); // Update the maximum sum found so far
    }

    cout << maxSum << "\n";
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
