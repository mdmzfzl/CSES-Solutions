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

void addValue(multiset<int>& left, multiset<int>& right, int value) {
    if (left.empty() || value <= *left.rbegin()) {
        left.insert(value);
    } else {
        right.insert(value);
    }

    while (left.size() > right.size() + 1) {
        right.insert(*left.rbegin());
        left.erase(prev(left.end()));
    }

    while (right.size() > left.size()) {
        left.insert(*right.begin());
        right.erase(right.begin());
    }
}

void removeValue(multiset<int>& left, multiset<int>& right, int value) {
    if (left.find(value) != left.end()) {
        left.erase(left.find(value));
    } else {
        right.erase(right.find(value));
    }

    while (left.size() > right.size() + 1) {
        right.insert(*left.rbegin());
        left.erase(prev(left.end()));
    }

    while (right.size() > left.size()) {
        left.insert(*right.begin());
        right.erase(right.begin());
    }
}

int getMedian(multiset<int>& left) {
    return *left.rbegin();
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi arr(n);
    multiset<int> left, right;

    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        addValue(left, right, arr[i]);
    }

    cout << getMedian(left) << " ";

    for (int i = k; i < n; i++) {
        cin >> arr[i];
        removeValue(left, right, arr[i - k]);
        addValue(left, right, arr[i]);
        cout << getMedian(left) << " ";
    }

    cout << "\n";
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
