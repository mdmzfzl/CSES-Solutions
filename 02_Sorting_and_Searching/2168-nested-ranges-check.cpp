#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

struct Range {
    int l, r, idx;
};

void printArray(const vector<bool> &arr) {
    for (bool val : arr) {
        cout << val << ' ';
    }
    cout << "\n";
}

void solve() {
    int n;
    cin >> n;
    vector<Range> ranges(n);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].idx = i + 1;
    }

    sort(ranges.begin(), ranges.end(), [](const Range& a, const Range& b) {
        return (a.l == b.l ? a.r > b.r : a.l < b.l);
    });

    vector<bool> left(n, false);
    int min_r = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        if (min_r <= ranges[i].r) {
            left[ranges[i].idx - 1] = true;
        }
        min_r = min(min_r, ranges[i].r);
    }

    printArray(left);

    vector<bool> right(n, false);
    int max_r = 0;
    for (int i = 0; i < n; i++) {
        if (max_r >= ranges[i].r) {
            right[ranges[i].idx - 1] = true;
        }
        max_r = max(max_r, ranges[i].r);
    }

    printArray(right);
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
