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

const int N = 2e5 + 1;
const int BIT = 2 * N;

struct Interval {
    int l, r, idx;
};

void update(int i, int v, vector<int>& b) {
    for (; i < BIT; i += -i & i) {
        b[i] += v;
    }
}

int query(int i, const vector<int>& b) {
    int c = 0;
    for (; i > 0; i -= -i & i) {
        c += b[i];
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    
    vector<Interval> intervals(n);
    set<int> uniqueEndpoints;
    map<int, int> endpointToIndex;

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].l >> intervals[i].r;
        intervals[i].idx = i;
        uniqueEndpoints.insert(intervals[i].l);
        uniqueEndpoints.insert(intervals[i].r);
    }
    
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return (a.l == b.l ? a.r > b.r : a.l < b.l);
    });

    int index = 1;
    for (int endpoint : uniqueEndpoints) {
        endpointToIndex[endpoint] = index++;
    }

    vector<int> bit(BIT, 0);
    vector<vector<int>> ans(2, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        int upperEndpoint = endpointToIndex[intervals[i].r];
        int rangeIndex = intervals[i].idx;

        ans[0][rangeIndex] = query(upperEndpoint, bit);
        update(upperEndpoint, 1, bit);
    }

    fill(bit.begin(), bit.end(), 0);
    for (int i = 0; i < n; i++) {
        int upperEndpoint = endpointToIndex[intervals[i].r];
        int rangeIndex = intervals[i].idx;

        ans[1][rangeIndex] = i - query(upperEndpoint - 1, bit);
        update(upperEndpoint, 1, bit);
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << (j == n - 1 ? '\n' : ' ');
        }
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
