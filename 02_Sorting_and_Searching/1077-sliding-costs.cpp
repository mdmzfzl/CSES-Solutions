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

void solve() {
    int n, k;
    cin >> n >> k;

    vi arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    multiset<int> lower_half, upper_half;
    ll sum_lower_half = 0, sum_upper_half = 0;

    auto addToLower = [&](int x) {
        if (lower_half.empty() || x <= *lower_half.rbegin()) {
            lower_half.insert(x);
            sum_lower_half += x;
        } else {
            upper_half.insert(x);
            sum_upper_half += x;
        }
        if (lower_half.size() > (k + 1) / 2) {
            sum_upper_half += *lower_half.rbegin();
            sum_lower_half -= *lower_half.rbegin();
            upper_half.insert(*lower_half.rbegin());
            lower_half.erase(prev(lower_half.end()));
        }
        while (upper_half.size() > k / 2) {
            sum_lower_half += *upper_half.begin();
            sum_upper_half -= *upper_half.begin();
            lower_half.insert(*upper_half.begin());
            upper_half.erase(upper_half.begin());
        }
    };

    auto removeFromSets = [&](int x) {
        if (lower_half.find(x) != lower_half.end()) {
            lower_half.erase(lower_half.find(x));
            sum_lower_half -= x;
        } else {
            upper_half.erase(upper_half.find(x));
            sum_upper_half -= x;
        }
        if (lower_half.empty()) {
            sum_lower_half += *upper_half.begin();
            sum_upper_half -= *upper_half.begin();
            lower_half.insert(*upper_half.begin());
            upper_half.erase(upper_half.begin());
        }
    };

    lower_half.insert(arr[0]);
    sum_lower_half += arr[0];
    for (int i = 1; i < k; i++) {
        addToLower(arr[i]);
    }
    cout << sum_upper_half - sum_lower_half + (k % 2) * (*lower_half.rbegin()) << ' ';

    for (int i = k; i < n; i++) {
        if (k == 1) {
            addToLower(arr[i]);
            removeFromSets(arr[i - k]);
        } else {
            removeFromSets(arr[i - k]);
            addToLower(arr[i]);
        }
        cout << sum_upper_half - sum_lower_half + (k % 2) * (*lower_half.rbegin()) << ' ';
    }

    cout << '\n';
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
