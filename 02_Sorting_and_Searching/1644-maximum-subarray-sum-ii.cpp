#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
 
    vl prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> prefix[i];
        prefix[i] += prefix[i - 1];
    }
 
    ll result = numeric_limits<ll>::min();
    multiset<ll> window;
 
    for (int j = a; j <= n; j++) {
        window.insert(prefix[j - a]);
        if (j > b) {
            window.erase(window.find(prefix[j - b - 1]));
        }
 
        ll current_max = prefix[j] - *window.begin();
        result = max(result, current_max);
    }
 
    cout << result << '\n';
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
