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
    int x, n;
    cin >> x >> n;

    set<int> lights;
    multiset<int> intervals;

    lights.insert(0); 
    lights.insert(x);

    intervals.insert(x); 

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        auto it = lights.upper_bound(a);

        int right = *it; 
        --it;
        int left = *it;

        intervals.erase(intervals.find(right - left));

        intervals.insert(a - left);
        intervals.insert(right - a);

        lights.insert(a);

        cout << *intervals.rbegin() << " ";
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
