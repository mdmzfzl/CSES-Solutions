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
    int n, q;
    cin >> n >> q;

    vector<vi> forest(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            forest[i][j] = (c == '*');
        }
    }

    vector<vi> prefix_sum(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefix_sum[i][j] = forest[i][j];
            if (i > 0) {
                prefix_sum[i][j] += prefix_sum[i - 1][j];
            }
            if (j > 0) {
                prefix_sum[i][j] += prefix_sum[i][j - 1];
            }
            if (i > 0 && j > 0) {
                prefix_sum[i][j] -= prefix_sum[i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        x2--; y2--;

        int trees_in_subgrid = prefix_sum[x2][y2];
        if (x1 > 0) {
            trees_in_subgrid -= prefix_sum[x1 - 1][y2];
        }
        if (y1 > 0) {
            trees_in_subgrid -= prefix_sum[x2][y1 - 1];
        }
        if (x1 > 0 && y1 > 0) {
            trees_in_subgrid += prefix_sum[x1 - 1][y1 - 1];
        }

        cout << trees_in_subgrid << '\n';
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
