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

void solve() {
    int n;
    cin >> n;

    vector<pair<ll, pll>> projects; // {end date, {start date, reward}}
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        projects.push_back({b, {a, c}});
    }

    sort(all(projects));

    vl dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ll start_date = projects[i - 1].second.first;
        ll reward = projects[i - 1].second.second;

        int prev_project = lower_bound(all(projects), mp(start_date, mp(0LL, 0LL))) - projects.begin();
        dp[i] = max(dp[i - 1], reward + dp[prev_project]);
    }

    cout << dp[n] << "\n";
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
