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

struct TrieNode {
    int len, link;
    map<char, int> next;
};

class AhoCorasick {
private:
    vector<TrieNode> nodes;
    int size, last;

public:
    AhoCorasick() : size(1), last(0) {
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

    bool query(const string& pattern) {
        int u = 0;
        for (char c : pattern) {
            if (!nodes[u].next.count(c)) {
                return false;
            } else {
                u = nodes[u].next[c];
            }
        }
        return true;
    }
};

void solve() {
    string s;
    int k;

    cin >> s >> k;

    AhoCorasick aho;
    for (char c : s) {
        aho.extend(c);
    }

    for (int i = 0; i < k; ++i) {
        string pattern;
        cin >> pattern;
        cout << (aho.query(pattern) ? "YES" : "NO") << '\n';
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
