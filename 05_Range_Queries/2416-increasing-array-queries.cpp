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

ll binarySearchUB(vl &arr, ll x) {
    ll ans = -1;
    ll l = 0;
    ll r = arr.size() - 1;

    while (l <= r) {
        ll m = (l + r) >> 1;

        if (arr[m] > x) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}

void solve() {
    ll n, q;
    cin >> n >> q;

    vl seq(n);
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    vl res(n, 0);
    vl stk;
    vl ans(q);
    vector<array<ll, 3>> queries;

    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        queries.pb({--l, --r, i});
    }

    sort(all(queries));
    reverse(all(queries));

    vl pre_sum(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        pre_sum[i] += pre_sum[i - 1] + seq[i - 1];
    }

    vl cur(n, 0);
    ll act = 0;
    ll w = 0;

    for (int i = n - 1; i >= 0; i--) {
        res[i] += 1;

        while (!stk.empty() && seq[stk.back()] <= seq[i]) {
            res[i] += res[stk.back()];
            act -= seq[stk.back()] * res[stk.back()];
            stk.pop_back();
        }

        stk.pb(i);
        act += res[i] * seq[i];
        cur[i] = act;

        while (w < int(queries.size()) && queries[w][0] == i) {
            ll ub = binarySearchUB(stk, queries[w][1]);
            ll a = act;
            ll end = n - 1;

            if (ub != -1) {
                a -= cur[stk[ub]];
                end = stk[ub] - 1;
            }

            ub++;
            a -= seq[stk[ub]] * (end - queries[w][1]);
            ans[queries[w][2]] = a - (pre_sum[queries[w][1] + 1] - pre_sum[queries[w][0]]);
            w++;
        }
    }

    for(auto i : ans) cout << i << '\n';
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
