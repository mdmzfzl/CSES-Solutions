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
    int n;
    cin >> n;

    vi r(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }

    ld result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (r[i] <= r[j]) {
                result += static_cast<ld>(r[i] - 1) / (2 * r[j]);
            } else {
                result += (r[i] - static_cast<ld>(r[j] + 1) / 2) / r[i];
            }
        }
    }

    cout << fixed << setprecision(6) << static_cast<double>(result) << '\n';
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

// ld calc(int a, int b) {
//     int less = min(a, b);
//     ld p = static_cast<ld>(less * (less - 1)) / static_cast<ld>(2);

//     if (a > b) {
//         p += static_cast<ld>((a - b) * b);
//     }

//     return p / static_cast<ld>(a * b);
// }

// void solve(int tc = 0) {
//     int n;
//     cin >> n;

//     vi a(n);
//     for (int &x : a) cin >> x;

//     ld result = 0;

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             result += calc(a[i], a[j]);
//         }
//     }

//     cout << fixed << setprecision(6) << double(result) << "\n";
// }
