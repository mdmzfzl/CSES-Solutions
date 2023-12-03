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
    int len, link, count, start;
    map<char, int> next;
};

class SuffixAutomaton {
private:
    string S;
    int N, size, last, lrsIndex, lrsLength;
    vector<Node> nodes;
    vector<bool> vis;

    void extend(char c) {
        int cur = size++;
        nodes[cur] = {nodes[last].len + 1, -1, 1, nodes[last].len, {}};
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
                nodes[clone] = {nodes[p].len + 1, nodes[q].link, nodes[q].count, nodes[q].start, nodes[q].next};

                while (p != -1 && nodes[p].next[c] == q) {
                    nodes[p].next[c] = clone;
                    p = nodes[p].link;
                }

                nodes[q].link = nodes[cur].link = clone;
            }
        }

        last = cur;
    }

    void updateCount() {
        vector<vi> states_by_len(size);

        for (int i = 0; i < size; ++i)
            states_by_len[nodes[i].len].pb(i);

        for (int i = size - 1; i >= 0; --i)
            for (int u : states_by_len[i])
                if (nodes[u].link != -1)
                    nodes[nodes[u].link].count += nodes[u].count;
    }

    void dfs(int u = 0) {
        vis[u] = true;

        if (nodes[u].len > lrsLength && nodes[u].count > 1 && u != 0) {
            lrsIndex = nodes[u].start - nodes[u].len + 1;
            lrsLength = nodes[u].len;
        }

        for (const auto& [c, v] : nodes[u].next)
            if (!vis[v])
                dfs(v);
    }

public:
    SuffixAutomaton(string s) : S(s), N(s.size()), size(1), last(0), lrsIndex(-1), lrsLength(-1) {
        nodes.resize(2 * N);
        vis.resize(2 * N, false);
        nodes[0] = {0, -1, 0, 0, {}};

        for (int i = 0; i < N; ++i)
            extend(S[i]);

        updateCount();
        dfs();
    }

    string longestRepeatingSubstring() {
        if (lrsLength == -1)
            return "-1";
        else
            return S.substr(lrsIndex, lrsLength);
    }
};

void solve() {
    string S;
    cin >> S;

    SuffixAutomaton sa(S);
    cout << sa.longestRepeatingSubstring() << '\n';
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
