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

const int N = 2e5 + 5;

void solve(int test_case = 0) {
    int n, m;
    cin >> n >> m;
    
    vector<int> element(N), position(N);
    
    for (int i = 1; i <= n; i++) {
        cin >> element[i];
        position[element[i]] = i;
    }

    int answer = 1;

    for (int i = 2; i <= n; i++) {
        answer += (position[i] < position[i - 1]);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        
        set<pair<int, int>> swaps;

        if (element[l] + 1 <= n) swaps.insert({element[l], element[l] + 1});
        if (element[l] - 1 >= 1) swaps.insert({element[l] - 1, element[l]});
        if (element[r] + 1 <= n) swaps.insert({element[r], element[r] + 1});
        if (element[r] - 1 >= 1) swaps.insert({element[r] - 1, element[r]});

        for (auto p : swaps) {
            answer -= (position[p.first] > position[p.second]);
        }

        swap(element[l], element[r]);
        position[element[l]] = l;
        position[element[r]] = r;

        for (auto p : swaps) {
            answer += (position[p.first] > position[p.second]);
        }

        cout << answer << '\n';
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
