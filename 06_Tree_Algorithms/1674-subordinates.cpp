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
vi adj[MAX_N];
int subordinates[MAX_N];

void dfs(int node, int parent) {
    subordinates[node] = 1;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            subordinates[node] += subordinates[child];
        }
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int manager;
        cin >> manager;
        adj[manager].pb(i);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] - 1 << " ";
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
