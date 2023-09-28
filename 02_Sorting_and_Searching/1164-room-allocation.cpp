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
    int n;
    cin >> n;

    vector<pll> requests;

    for (int i = 0; i < n; ++i) {
        ll arrival_time, departure_time;
        cin >> arrival_time >> departure_time;
        requests.emplace_back(arrival_time, -(i + 1));
        requests.emplace_back(departure_time, (i + 1));
    }

    sort(requests.begin(), requests.end());

    ll room_count = 0;
    ll room_assignment[2*n + 1];
    vl available_rooms;

    size_t curr = 0;

    for (int i = 0; i < 2 * n; ++i) {
        if (requests[i].se < 0) {
            if (curr == available_rooms.size()) {
                room_count++;
                room_assignment[-requests[i].se] = room_count;
            } else {
                room_assignment[-requests[i].se] = available_rooms[curr];
                curr++;
            }
        } else {
            available_rooms.pb(room_assignment[requests[i].se]);
        }
    }

    if (curr == available_rooms.size()) {
        cout << room_count << '\n'; // No more rooms can be allocated
    } else {
        cout << *max_element(room_assignment + 1, room_assignment + n + 1) << '\n';
    }

    for (int i = 1; i <= n; ++i) {
        cout << room_assignment[i] << ' ';
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
