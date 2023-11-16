#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define umap unordered_map
#define uset unordered_set

#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair

const long long LLINF = LLONG_MAX;
const int INF = INT_MAX;
const int MOD = 1e9 + 7;

using ld = long double;

void solve() {
    int n, k; 
    cin >> n >> k;
    
    ld result = 0.0;
    ld step = 1.0 / k;

    for (int i = 1; i <= k; ++i) {
        ld left = pow((ld)(i - 1) * step, n);
        ld right = pow((ld)i * step, n);
        result += (right - left) * i;
    }

    cout << fixed << setprecision(6) << result << '\n';
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
