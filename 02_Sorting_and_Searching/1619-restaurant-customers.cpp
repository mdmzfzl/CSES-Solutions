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

    vector<pii> events; // Each event is a pair (time, type), type=0 for exiting, type=1 for entering

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        events.pb({a, 1});
        events.pb({b, 0});
    }

    sort(events.begin(), events.end());

    int maxCustomers = 0, currentCustomers = 0;

    for (auto event : events) {
        if (event.second == 1) {
            currentCustomers++;
            maxCustomers = max(maxCustomers, currentCustomers);
        } else {
            currentCustomers--;
        }
    }

    cout << maxCustomers << "\n";
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
