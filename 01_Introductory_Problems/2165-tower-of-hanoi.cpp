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
    int n;
    cin >> n;

    // Lambda function to move a stack of n disks from source to target using auxiliary.
    function<void(int, char, char, char)> hanoi = [&](int n, char source, char auxiliary, char target) {
        if (n == 1) {
            cout << source << " " << target << "\n";
            return;
        }

        hanoi(n - 1, source, target, auxiliary);
        cout << source << " " << target << "\n";
        hanoi(n - 1, auxiliary, source, target);
    };

    ll moves = (1LL << n) - 1; // Total moves for n disks.

    cout << moves << "\n";
    hanoi(n, '1', '2', '3');
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
