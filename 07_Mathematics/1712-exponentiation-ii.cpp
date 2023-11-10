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

ll mod_pow(ll a, ll b, ll m) {
    ll result = 1;
    a = a % m;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }

        a = (a * a) % m;
        b /= 2;
    }

    return result;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll exp = mod_pow(b, c, MOD - 1);
    ll result = mod_pow(a, exp, MOD);

    cout << result << '\n';
}

int main() {
    fastio

    int tc = 1; // Number of test cases
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}
