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

void solve() {
    string S;
    cin >> S;

    vl hvals(S.size(), 0);
    ll R = 9973, P = 1;
    for (size_t i = 0; i < S.size(); i++) {
        hvals[i] = ((i == 0 ? 0 : hvals[i - 1]) * R + (ll)S[i]) % MOD;
    }

    for (size_t k = 1; k < S.size(); k++) {
        P = (P * R) % MOD;
        ll sufhash = (hvals.back() - (P * hvals[S.size() - k - 1]) % MOD + MOD) % MOD;
        if (hvals[k - 1] == sufhash) {
            cout << k << ' ';
        }
    }

    cout << '\n';
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
