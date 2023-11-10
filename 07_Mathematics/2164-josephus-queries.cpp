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

int josephusQuery(int n, int k) {
    if (n == 1) {
        return 1;
    }

    int mid = (n + 1) / 2;
    if (k <= mid) {
        if (2 * k > n) {
            return 2 * k % n;
        } else {
            return 2 * k;
        }
    }

    int offset = k - mid;
    int sub = josephusQuery(n >> 1, offset);

    if (n & 1) {
        return 2 * sub + 1;
    } else {
        return 2 * sub - 1;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    cout << josephusQuery(n, k) << '\n';
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
