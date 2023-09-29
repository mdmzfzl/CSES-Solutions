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
    ll targetSum;
    cin >> n >> targetSum;

    vector<ll> prefixSum(n + 1, 0);
    map<ll, int> frequency;
    ll count = 0;

    for (int i = 1; i <= n; i++) {
        ll num;
        cin >> num;

        prefixSum[i] = prefixSum[i - 1] + num;

        if (prefixSum[i] == targetSum) {
            count++;
        }

        if (frequency.count(prefixSum[i] - targetSum)) {
            count += frequency[prefixSum[i] - targetSum];
        }

        frequency[prefixSum[i]]++;
    }

    cout << count << "\n";
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
