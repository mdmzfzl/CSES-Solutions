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

const int MAX_C = 26;

class SuffixAutomaton {
public:
    SuffixAutomaton(const string& s) : N(s.length()), size(1), last(0) {
        nodes.emplace_back();
        for (char c : s) {
            extend(c);
        }
        calc();
    }

    ll distinctSubstrings() const {
        return nodes[0].dp - 1;
    }

private:
    struct Node {
        ll dp;
        int len, link;
        array<int, MAX_C> next;

        Node() : dp(0), len(0), link(-1) {
            next.fill(-1);
        }
    };

    vector<Node> nodes;
    int N, size, last;

    void extend(char c) {
        int cur = size++;
        nodes.emplace_back();
        nodes[cur].len = nodes[last].len + 1;
        int p = last;

        while (p != -1 && nodes[p].next[c - 'a'] == -1) {
            nodes[p].next[c - 'a'] = cur;
            p = nodes[p].link;
        }

        if (p == -1) {
            nodes[cur].link = 0;
        } else {
            int q = nodes[p].next[c - 'a'];
            if (nodes[p].len + 1 == nodes[q].len) {
                nodes[cur].link = q;
            } else {
                int clone = size++;
                nodes.emplace_back(nodes[q]);
                nodes[clone].len = nodes[p].len + 1;
                while (p != -1 && nodes[p].next[c - 'a'] == q) {
                    nodes[p].next[c - 'a'] = clone;
                    p = nodes[p].link;
                }
                nodes[q].link = nodes[cur].link = clone;
            }
        }
        last = cur;
    }

    void calc(int u = 0) {
        nodes[u].dp = 1;
        for (int v : nodes[u].next) {
            if (v != -1 && !nodes[v].dp) {
                calc(v);
            }
            if (v != -1) {
                nodes[u].dp += nodes[v].dp;
            }
        }
    }
};

void solve() {
    string s;
    cin >> s;

    SuffixAutomaton sa(s);
    cout << sa.distinctSubstrings() << '\n';
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
