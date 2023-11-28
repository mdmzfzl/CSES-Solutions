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
    const int MAX_C = 26;

    string input;
    cin >> input;

    vector<int> charCount(MAX_C, 0);

    for (char c : input) {
        charCount[c - 'A']++;
    }

    int oddChar = -1;

    for (int i = 0; i < MAX_C; i++) {
        if (charCount[i] % 2) {
            if (oddChar != -1) {
                cout << "NO SOLUTION\n";
                return;
            } else {
                oddChar = i;
                charCount[i]--;
            }
        }
    }

    string firstHalf;

    for (int i = 0; i < MAX_C; i++) {
        firstHalf += string(charCount[i] / 2, 'A' + i);
    }

    string secondHalf(firstHalf.rbegin(), firstHalf.rend());

    if (oddChar != -1) {
        firstHalf += static_cast<char>('A' + oddChar);
    }

    cout << firstHalf + secondHalf << "\n";
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
