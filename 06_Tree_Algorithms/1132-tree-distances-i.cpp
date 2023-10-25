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

int n;
vi adj[MAX_N];
vi result(MAX_N, -1);

int bfs(int src) {
    queue<int> q;
    vi d(n + 1, -1);
    d[src] = 0;
    result[src] = max(result[src], d[src]);
    q.push(src);

    int top = src;
    while (!q.empty()) {
        top = q.front();
        q.pop();

        for (int v : adj[top]) {
            if (d[v] == -1) {
                q.push(v);
                d[v] = d[top] + 1;
                result[v] = max(result[v], d[v]);
            }
        }
    }
    return top;
}

void solve() {
    int u, v;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int de1 = bfs(1);
    int de2 = bfs(de1);
    bfs(de2);

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << '\n';
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
