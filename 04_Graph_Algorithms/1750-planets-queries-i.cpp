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

const int MAX_N = 2e5 + 5;
const int MAX_D = 30;

int solve() {
    int n, q;
    cin >> n >> q;
    
    int parent[MAX_N][MAX_D];
    
    for (int i = 1; i <= n; i++) {
        cin >> parent[i][0];
    }

    for (int d = 1; d < MAX_D; d++) {
        for (int i = 1; i <= n; i++) {
            parent[i][d] = parent[parent[i][d - 1]][d - 1];
        }
    }

    auto jump = [&](int a, int d) {
        for (int i = 0; i < MAX_D; i++)
            if (d & (1 << i)) a = parent[a][i];
        return a;
    };

    while (q--) {
        int a, d;
        cin >> a >> d;
        cout << jump(a, d) << '\n';
    }

    return 0;
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
