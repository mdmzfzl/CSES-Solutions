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
    int n, k;
    cin >> n >> k;

    vector<pii> tasks(n);
    multiset<int> timeslots;

    for (int i = 0; i < k; i++) {
        timeslots.insert(0);
    }

    for (int i = 0; i < n; i++) {
        cin >> tasks[i].se >> tasks[i].fi;
    }

    sort(tasks.begin(), tasks.end());

    int count = 0;

    for (int i = 0; i < n; i++) {
        auto it = timeslots.upper_bound(tasks[i].second);
        if (it != timeslots.begin()) {
            timeslots.erase(--it);
            timeslots.emplace(tasks[i].first);
            count++;
        }
    }

    cout << count << '\n';
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
