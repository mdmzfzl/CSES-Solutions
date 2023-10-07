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

const ll N = 1e5 + 5;

vector<pll> adj[N];
priority_queue<ll> dist[N];

void dijkstra(ll start, size_t k) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    dist[start].push(0);
    pq.push({0LL, start});

    while (!pq.empty()) {
        const auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u].top()) continue;

        for (const auto &[v, w] : adj[u]) {
            ll to = d + w;

            if (dist[v].size() < k) {
                dist[v].push(to);
                pq.push({to, v});
            } else if (dist[v].top() > to) {
                dist[v].push(to);
                while (dist[v].size() > k) dist[v].pop();
                pq.push({to, v});
            }
        }
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        ll from, to, cost;
        cin >> from >> to >> cost;
        adj[from].pb({to, cost});
    }

    dijkstra(1, k);

    vl result;
    while (dist[n].size()) {
        result.pb(dist[n].top());
        dist[n].pop();
    }

    reverse(all(result));
    for (ll i : result) {
        cout << i << " ";
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
