#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
    string s;
    cin >> s;

    int max_repetitions = 0;
    int current_repetitions = 1;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            current_repetitions++;
        } else {
            max_repetitions = max(max_repetitions, current_repetitions);
            current_repetitions = 1;
        }
    }

    max_repetitions = max(max_repetitions, current_repetitions);
    cout << max_repetitions << "\n";
}

int main() {
    fastio;

    int tc = 1; // Number of test cases
    // cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}