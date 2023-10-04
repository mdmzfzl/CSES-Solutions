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

vector<vi> adj;
vi parent;

bool bfs(int source, int target) {
    int n = adj.size();
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    return visited[target];
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    parent.resize(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; 
        b--; 
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int source = 0;    
    int target = n - 1;  
    vi path;

    if (!bfs(source, target)) {
        cout << "IMPOSSIBLE\n";
    } else {
        int cur = target;
        while (cur != source) {
            path.pb(cur);
            cur = parent[cur];
        }
        path.pb(source);
        reverse(all(path));

        cout << path.size() << "\n";
        for (int node : path) {
            cout << node + 1 << " ";
        }
        cout << "\n";
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
