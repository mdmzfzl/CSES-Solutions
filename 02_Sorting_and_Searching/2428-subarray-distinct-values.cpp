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

    vi nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    unordered_map<int, int> freq;
    ll total = 0, distinct = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        freq[nums[right]]++;

        if (freq[nums[right]] == 1) {
            distinct++;
        }

        while (distinct > k && left <= right) {
            freq[nums[left]]--;

            if (freq[nums[left]] == 0) {
                distinct--;
            }

            left++;
        }

        total += (right - left + 1);
    }

    cout << total << '\n';
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
