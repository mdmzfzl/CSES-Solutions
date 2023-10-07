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

struct Flight {
    int to;
    ll discount;
    Flight(int _to, ll _discount) : to(_to), discount(_discount) {}
};

void dijkstra(vector<vector<Flight>>& graph, vector<vl>& dist, vector<bool>& vis) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    dist[0][0] = 0;

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (vis[p.second]) continue;
        vis[p.second] = true;

        for (auto &f : graph[p.second]) {
            int to = f.to;
            ll discount = f.discount;
            if (p.first + discount < dist[to][0]) {
                dist[to][0] = p.first + discount;
                pq.push({dist[to][0], to});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<Flight>> graph(n);

    for (int i = 0; i < m; ++i) {
        int from, to;
        ll discount;
        cin >> from >> to >> discount;
        from--, to--;
        graph[from].pb(Flight(to, discount));
    }

    vector<vl> dist(n, vector<ll>(2, LLINF));
    vector<bool> vis(n), vis_ret(n);

    dijkstra(graph, dist, vis);

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    dist[0][1] = 0;

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (vis_ret[p.second]) continue;
        vis_ret[p.second] = true;

        for (auto &f : graph[p.second]) {
            int to = f.to;
            ll discount = f.discount;
            ll owc = discount / 2 + dist[p.second][0];
            ll rtc = discount + dist[p.second][1];
            owc = min(owc, rtc);

            if (owc < dist[to][1]) {
                dist[to][1] = owc;
                pq.push({dist[to][1], to});
            }
        }
    }

    cout << min(dist[n - 1][0], dist[n - 1][1]) << endl;
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
