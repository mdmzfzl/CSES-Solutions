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

const int MAX_N = 1e6 + 5;

void solve() {
    int n;
    cin >> n;

    vi count(MAX_N, 0);
    while (n--) {
        int x;
        cin >> x;
        count[x]++;
    }

    for (int i = MAX_N - 1; i > 0; --i) {
        int cur = 0;
        for (int j = i; j < MAX_N; j += i) {
            cur += count[j];
        }

        if (cur >= 2) {
            cout << i << '\n';
            return;
        }
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
