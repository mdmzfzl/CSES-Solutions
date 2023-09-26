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

    vi songs(n);

    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    int maxLength = 0;
    multiset<int> uniqueSongs;
    int start = 0;

    for (int end = 0; end < n; end++) {
        while (uniqueSongs.count(songs[end])) {
            uniqueSongs.erase(uniqueSongs.find(songs[start]));
            start++;
        }
        maxLength = max(maxLength, end - start + 1);
        uniqueSongs.insert(songs[end]);
    }

    cout << maxLength << "\n";
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
