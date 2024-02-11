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

struct Node {
    ll dp;
    int len, link;
    map<char, int> next;
};

class SuffixAutomaton {
public:
    SuffixAutomaton(const string& str) : last(0), size(1) {
        init();
        buildAutomaton(str);
        calc();
    }

    string findKthSubstring(ll k) {
        vector<char> result;
        dfs(0, k - 1, result);
        return string(all(result));
    }

private:
    int last, size;
    vector<Node> nodes;

    void init() {
        nodes.resize(2 * MAX_N);
        nodes[0].len = 0;
        nodes[0].link = -1;
    }

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

    void buildAutomaton(const string& str) {
        for (char c : str)
            extend(c);
    }

    void calc(int u = 0) {
        nodes[u].dp = 1;

        for (const auto& [c, v] : nodes[u].next) {
            if (!nodes[v].dp)
                calc(v);
            nodes[u].dp += nodes[v].dp;
        }
    }

    void dfs(int u, ll k, vector<char>& result) {
        if (k < 0)
            return;

        for (const auto& [c, v] : nodes[u].next) {
            if (nodes[v].dp <= k)
                k -= nodes[v].dp;
            else {
                result.pb(c);
                dfs(v, k - 1, result);
                return;
            }
        }
    }
};

void solve() {
    string S;
    ll K;
    cin >> S >> K;

    SuffixAutomaton sa(S);
    string result = sa.findKthSubstring(K);

    cout << result << '\n';
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
