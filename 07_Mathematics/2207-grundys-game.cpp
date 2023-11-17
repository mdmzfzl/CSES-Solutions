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

const int MAX_N = 2000;
vi grundy(MAX_N, 0);

int mex(const vi& vals) {
    set<int> unique_vals(begin(vals), end(vals));
    for (int i = 0; i < MAX_N; i++) {
        if (!unique_vals.count(i)) {
            return i;
        }
    }
    return MAX_N;
}

void precompute() {
    for (int pos = 3; pos < MAX_N; pos++) {
        vi opts;
        for (int mv = 1; pos - mv > mv; mv++) {
            opts.pb(grundy[mv] ^ grundy[pos - mv]);
        }
        grundy[pos] = mex(opts);
    }
}

void solve() {
    int n;
    cin >> n;
    cout << (n >= MAX_N ? "first" : (grundy[n] > 0 ? "first" : "second")) << '\n';
}

int main() {
    fastio

    int tc = 1; // Number of test cases
    cin >> tc;

    precompute();
    while (tc--) {
        solve();
    }

    return 0;
}
