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

string manacher(string s) {
    string t = "@#";
    for (char c : s) {
        t += c;
        t += '#';
    }
    t += '$';
    vi p(t.size(), 0);
    int center = 0, right = 0, max_len = 0, start = 0;
    for (int i = 1; i < (int)t.size() - 1; i++) {
        if (right > i) {
            p[i] = min(right - i, p[2 * center - i]);
        }
        while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        if (p[i] > max_len) {
            max_len = p[i];
            start = (i - max_len) / 2;
        }
    }
    return s.substr(start, max_len);
}

void solve() {
    string s;
    cin >> s;
    cout << manacher(s) << '\n';
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
