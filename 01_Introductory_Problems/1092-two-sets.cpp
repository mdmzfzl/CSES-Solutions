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
    ll n;
    cin >> n;

    ll total_sum = n * (n + 1) / 2;

    if (total_sum % 2 == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        vector<ll> set1, set2;
        ll target_sum = total_sum / 2;
        vector<bool> chosen(n + 1, false);

        for (ll i = n; i >= 1; i--) {
            if (i <= target_sum) {
                set1.pb(i);
                chosen[i] = true;
                target_sum -= i;
            } else {
                set2.pb(i);
            }
        }

        cout << set1.size() << "\n";
        for (ll num : set1) {
            cout << num << " ";
        }
        cout << "\n";

        cout << set2.size() << "\n";
        for (ll num : set2) {
            cout << num << " ";
        }
        cout << "\n";
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