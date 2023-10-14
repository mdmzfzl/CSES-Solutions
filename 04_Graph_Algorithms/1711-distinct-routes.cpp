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

const int MAX_N = 501;

int n, m, match_count, flows[MAX_N][MAX_N];
bool visited[MAX_N], alt_edges[MAX_N][MAX_N];
vi cycle;

bool dfs(int node) {
    if (node == n) {
        return true;
    }
    
    visited[node] = true;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && flows[node][i]) {
            if (dfs(i)) {
                alt_edges[node][i] = !alt_edges[node][i];
                alt_edges[i][node] = !alt_edges[i][node];
                flows[node][i]--;
                flows[i][node]++;
                return true;
            }
        }
    }
    
    return false;
}

void inverseDfs(int node) {
    cycle.pb(node);
    
    for (int i = 1; i <= n; i++) {
        if (flows[i][node] && alt_edges[node][i]) {
            flows[i][node] = alt_edges[node][i] = alt_edges[i][node] = 0;
            inverseDfs(i);
            return;
        }
    }
}

void solve() {
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        flows[a][b]++;
    }
    
    while (dfs(1)) {
        match_count++;
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
        }
    }
    
    cout << match_count << "\n";
    
    for (int i = 1; i <= match_count; i++) {
        inverseDfs(1);
        cout << cycle.size() << "\n";
        
        for (int j : cycle) {
            cout << j << " ";
        }
        cout << "\n";
        
        cycle.clear();
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
