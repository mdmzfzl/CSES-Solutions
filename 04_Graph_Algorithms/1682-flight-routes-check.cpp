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

void solve() {
    int n, m, a, b;
    cin >> n >> m;

    vector<vi> adj1(n + 1), adj2(n + 1);
    vector<bool> vis1(n + 1), vis2(n + 1);
    stack<int> s;

    while (m--) {
        cin >> a >> b;
        adj1[a].pb(b);
        adj2[b].pb(a);
    }

    auto dfs = [](const vector<vi>& g, vector<bool>& visited, stack<int>& s) {
        s.push(1);
        while (!s.empty()) {
            int num = s.top();
            s.pop();
            visited[num] = true;
            for (int i : g[num]) {
                if (!visited[i]) {
                    s.push(i);
                }
            }
        }
    };

    dfs(adj1, vis1, s);
    dfs(adj2, vis2, s);

    for (int i = 2; i <= n; i++) {
        if (!vis1[i]) {
            if (vis2[i]) {
                cout << "NO\n1 " << i;
            } else {
                cout << "NO\n1 " << i;
            }
            return;
        } else if (!vis2[i]) {
            cout << "NO\n" << i << " 1";
            return;
        }
    }

    cout << "YES";
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
