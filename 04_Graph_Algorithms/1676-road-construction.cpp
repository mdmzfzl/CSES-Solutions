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

const int MAX_N = 1e5 + 1;

vi parent(MAX_N), rank_(MAX_N);
int comp_count, comp_size;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int u = Find(x);
    int v = Find(y);
    if (u == v) return;

    if (rank_[u] < rank_[v]) {
        swap(u, v);
    }

    parent[v] = u;
    rank_[u] += rank_[v];

    comp_count--;
    comp_size = max(comp_size, rank_[u]);
}

void solve() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    rank_.resize(n + 1);

    comp_count = n;
    comp_size = 1;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_[i] = 1;
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
        cout << comp_count << " " << comp_size << '\n';
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
