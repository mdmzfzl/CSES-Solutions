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
    int n, m;
    cin >> n >> m;
    
    vector<pii> a(n);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = {x, i + 1};
    }
    
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = m - a[i].first - a[j].first;
            
            for (int l = j + 1, r = n - 1; l < r;) {
                if (a[l].first + a[r].first == sum) {
                    cout << a[i].second << " " << a[j].second << " " << a[l].second << " " << a[r].second << "\n";
                    return;
                } else if (a[l].first + a[r].first < sum) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    
    cout << "IMPOSSIBLE\n";
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
