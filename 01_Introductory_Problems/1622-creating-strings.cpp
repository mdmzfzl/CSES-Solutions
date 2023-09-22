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
    string s;
    cin >> s;

    // Sort the characters in the string to generate all permutations.
    sort(s.begin(), s.end());

    vector<string> permutations;
    do {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << permutations.size() << "\n";
    for (string perm : permutations) {
        cout << perm << "\n";
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
