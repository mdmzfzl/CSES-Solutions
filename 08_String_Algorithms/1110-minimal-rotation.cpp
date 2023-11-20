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

int minRotation(const string& s) {
    string concat = s + s;
    int n = concat.length();

    vi f(n, -1);
    int k = 0;

    for (int j = 1; j < n; j++) {
        char sj = concat[j];
        int i = f[j - k - 1];

        while (i != -1 && sj != concat[k + i + 1]) {
            if (sj < concat[k + i + 1]) {
                k = j - i - 1;
            }
            i = f[i];
        }

        if (sj != concat[k + i + 1]) {
            if (sj < concat[k]) {
                k = j;
            }
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }

    return k;
}

void solve() {
    string s;
    cin >> s;

    int rIndex = minRotation(s);
    cout << s.substr(rIndex) + s.substr(0, rIndex) << '\n';
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
