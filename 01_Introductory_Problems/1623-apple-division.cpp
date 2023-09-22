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

ll best_division = LLONG_MAX;

void divide_apples(const vector<ll>& apples, int index, ll sum1, ll sum2) {
    if (index == apples.size()) {
        ll diff = abs(sum1 - sum2);
        best_division = min(best_division, diff);
        return;
    }

    // Include the current apple in the first pile.
    divide_apples(apples, index + 1, sum1 + apples[index], sum2);

    // Include the current apple in the second pile.
    divide_apples(apples, index + 1, sum1, sum2 + apples[index]);
}

void solve() {
    int n;
    cin >> n;

    vector<ll> apples(n);
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
    }

    divide_apples(apples, 0, 0, 0);

    cout << best_division << "\n";
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
