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

vi tree[MAX_N];
int up[MAX_N][20];

void binaryLifting(int src, int par) {
    up[src][0] = par;
    for (int i = 1; i < 20; ++i) {
        if (up[src][i - 1] != -1)
            up[src][i] = up[up[src][i - 1]][i - 1];
        else
            up[src][i] = -1;
    }

    for (int child : tree[src]) {
        if (child != par)
            binaryLifting(child, src);
    }
}

int query(int node, int jumps) {
    if (node == -1 || jumps == 0)
        return node;

    for (int i = 19; i >= 0; --i) {
        if (jumps >= (1 << i)) {
            return query(up[node][i], jumps - (1 << i));
        }
    }
    return -1; 
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        tree[x].pb(i);
        tree[i].pb(x);
    }

    memset(up, -1, sizeof(up));
    binaryLifting(1, -1);

    while (q--) {
        int node, k;
        cin >> node >> k;
        cout << query(node, k) << '\n';
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
