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

void solve(int tc = 0) {
    ll row, col;
    cin >> row >> col;

    ll result;
    if (row > col) {
        if (row % 2 == 1) {
            result = (row - 1) * (row - 1) + col;
        } else {
            result = row * row - col + 1;
        }
    } else {
        if (col % 2 == 1) {
            result = col * col - row + 1;
        } else {
            result = (col - 1) * (col - 1) + row;
        }
    }

    cout << result << "\n";
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
