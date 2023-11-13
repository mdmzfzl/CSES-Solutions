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

const int MAX = 2e6 + 5;

vl fact(MAX), inv_fact(MAX);

ll modInv(ll a) {
    ll result = 1, exp = MOD - 2;
    while (exp > 0) {
        if (exp & 1) 
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        exp >>= 1;
    }
    return result;
}

ll nCk(int n, int k) {
    if (k < 0 || n < k) 
        return 0;

    ll numerator = fact[n];
    ll denominator = (inv_fact[k] * inv_fact[n - k]) % MOD;

    return (numerator * denominator) % MOD;
}

void preprocess() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) 
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact[MAX - 1] = modInv(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--) 
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << nCk(n + m - 1, m) << '\n';
}

int main() {
    fastio

    int tc = 1; // Number of test cases
    // cin >> tc;

    preprocess();
    while (tc--) {
        solve();
    }

    return 0;
}
