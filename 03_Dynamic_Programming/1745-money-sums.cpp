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
    int n;
    cin >> n;

    vi coins(n);
    for (int &coin: coins) cin >> coin;

    set<int> possible_sums;
    possible_sums.insert(0);

    for (int coin: coins) {
        vi new_sums;
        for (int sum: possible_sums) {
            new_sums.push_back(sum + coin);
        }
        for (int sum: new_sums) {
            possible_sums.insert(sum);
        }
    }

    int distinct_sums = possible_sums.size() - 1; 
    cout << distinct_sums << "\n";
    for (int sum: possible_sums) {
        if (sum != 0) {
            cout << sum << " ";
        }
    }
    cout << "\n";
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
