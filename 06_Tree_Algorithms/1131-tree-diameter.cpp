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

const int N = 2e5 + 5;
vi tree[N];
int maxDepth, farthestNode;

void dfs(int node, int parent, int depth) {
    if (depth > maxDepth) {
        maxDepth = depth;
        farthestNode = node;
    }

    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node, depth + 1);
        }
    }
}

pii treeDiameter() {
    maxDepth = -1;
    dfs(1, 0, 0); 
    int node1 = farthestNode;

    maxDepth = -1;
    dfs(node1, 0, 0);
    int node2 = farthestNode;

    return mp(node1, node2);
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    pii endpoints = treeDiameter();
    cout << maxDepth << '\n';
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
