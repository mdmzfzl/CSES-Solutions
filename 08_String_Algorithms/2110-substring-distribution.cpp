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

struct Node {
    int len, link;
    map<char, int> next;
};

class SuffixAutomaton {
private:
    vector<Node> nodes;
    vector<bool> vis;
    vi dist;
    vl result;
    int N, size, last;

    void extend(char c) {
        int cur = size++;
        nodes[cur].len = nodes[last].len + 1;
        int p = last;
        while (p != -1 && !nodes[p].next.count(c)) {
            nodes[p].next[c] = cur;
            p = nodes[p].link;
        }
        if (p == -1) {
            nodes[cur].link = 0;
        } else {
            int q = nodes[p].next[c];
            if (nodes[p].len + 1 == nodes[q].len) {
                nodes[cur].link = q;
            } else {
                int clone = size++;
                nodes[clone].len = nodes[p].len + 1;
                nodes[clone].next = nodes[q].next;
                nodes[clone].link = nodes[q].link;
                while (p != -1 && nodes[p].next[c] == q) {
                    nodes[p].next[c] = clone;
                    p = nodes[p].link;
                }
                nodes[q].link = nodes[cur].link = clone;
            }
        }
        last = cur;
    }

    void init() {
        nodes[0].len = 0;
        nodes[0].link = -1;
        size = 1;
        last = 0;
    }

    void bfs(int s = 0) {
        queue<int> Q;
        vis[s] = true;
        dist[s] = 0;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            result[dist[u]]++;
            result[nodes[u].len + 1]--;
            for (const auto& [c, v] : nodes[u].next) {
                if (!vis[v]) {
                    dist[v] = dist[u] + 1;
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }

public:
    SuffixAutomaton(const string& input) {
        N = input.size();
        nodes.resize(2 * N);
        vis.resize(2 * N, false);
        dist.resize(2 * N, 0);
        result.resize(N + 1, 0);
        init();

        for (char c : input)
            extend(c);

        bfs();
    }

    void distinctSubstringsCount() {
        for (int i = 1; i <= N; i++) {
            result[i] += result[i - 1];
            cout << result[i] << " \n"[i == N];
        }
    }
};

void solve() {
    string S;
    cin >> S;

    SuffixAutomaton sa(S);
    sa.distinctSubstringsCount();
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
