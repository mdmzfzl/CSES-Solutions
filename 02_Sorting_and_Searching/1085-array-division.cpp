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

bool canDivideArray(const vector<ll>& arr, int k, ll maxSum) {
    int n = arr.size();
    int partitions = 0;
    ll currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxSum) {
            return false;
        }

        if (currentSum + arr[i] <= maxSum) {
            currentSum += arr[i];
        } else {
            partitions++;
            currentSum = arr[i];

            if (partitions >= k) {
                return false;
            }
        }
    }

    return true;
}

ll findMinimumMaxSum(const vector<ll>& arr, int k) {
    ll left = 1;
    ll right = accumulate(arr.begin(), arr.end(), 0LL);
    ll result = right;

    while (left <= right) {
        ll mid = left + (right - left) / 2;

        if (canDivideArray(arr, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll minMaxSum = findMinimumMaxSum(arr, k);
    cout << minMaxSum << "\n";
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
