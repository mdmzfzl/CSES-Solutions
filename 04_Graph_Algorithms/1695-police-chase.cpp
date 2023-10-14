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

vi adj[MAX_N];
ll mat[MAX_N][MAX_N];
int parent[MAX_N];
int n, m;
ll result;

bool bfs() {
    fill(parent, parent + n + 1, 0);
    queue<int> q;
    q.push(1);
    parent[1] = -1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i : adj[x]) {
            if (parent[i] == 0 && mat[x][i]) {
                parent[i] = x;
                q.push(i);
            }
        }
    }

    if (parent[n] == 0) return false;

    ll mn = LLINF;
    int curr = n;

    while (curr != 1) {
        mn = min(mn, mat[parent[curr]][curr]);
        curr = parent[curr];
    }

    curr = n;

    while (curr != 1) {
        mat[parent[curr]][curr] -= mn;
        mat[curr][parent[curr]] += mn;
        curr = parent[curr];
    }

    result += mn;
    return true;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        mat[a][b]++;
        mat[b][a]++;
    }

    while (bfs());
    cout << result << "\n";

    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (parent[j] && !parent[i]) {
                cout << i << " " << j << "\n";
            }
        }
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
