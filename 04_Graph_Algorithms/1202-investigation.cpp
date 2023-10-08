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

const int MAX_N = 1e5 + 5;

vector<pii> adj[MAX_N];
long long dist[MAX_N];
int ways[MAX_N], min_stops[MAX_N], max_stops[MAX_N];

void dijkstra(int s) {
    fill(dist, dist + MAX_N, LLINF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({dist[s] = 0, s});
    ways[0] = 1;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                ways[v] = ways[u];
                min_stops[v] = min_stops[u] + 1;
                max_stops[v] = max_stops[u] + 1;
            } else if (dist[v] == dist[u] + w) {
                ways[v] += ways[u];
                if (ways[v] >= MOD) ways[v] -= MOD;
                min_stops[v] = min(min_stops[v], min_stops[u] + 1);
                max_stops[v] = max(max_stops[v], max_stops[u] + 1);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        from--; to--;
        adj[from].pb({to, price});
    }
    dijkstra(0);

    cout << dist[n - 1] << " " << ways[n - 1] << " " << min_stops[n - 1] << " " << max_stops[n - 1] << "\n";
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
