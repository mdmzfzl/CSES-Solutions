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

const int MAX_N = 1e6 + 5;
const int MAX_C = 26;

string s;

class Trie {
private:
    bool stop[MAX_N];
    int trie[MAX_N][MAX_C];
    int count = 0;
 
public:
    int dp[5005];
    void insert(string s) {
        int node = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (!trie[node][s[i]-'a']) trie[node][s[i]-'a'] = ++count;
            node = trie[node][s[i]-'a'];
        }
        stop[node] = 1;
    }
 
    int search(int x) {
        int node = 0, result = 0;
        for (size_t i = x; i < s.size(); i++) {
            if (!trie[node][s[i]-'a']) return result;
            node = trie[node][s[i] - 'a'];
            if (stop[node]) {
                (result += dp[i+1]) %= MOD;
            }
        }
        return result;
    }
};

void solve() {
    cin >> s;
    int k;
    cin >> k;
    Trie trie; 
    while (k--) {
        string x;
        cin >> x;
        trie.insert(x); 
    }
    trie.dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        trie.dp[i] = trie.search(i); 
    }
    cout << trie.dp[0] << '\n';
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
