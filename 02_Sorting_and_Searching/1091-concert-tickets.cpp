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

int getUpperBound(int price, multiset<int>& ticketPrices) {
    auto it = ticketPrices.upper_bound(price);
    if (it == ticketPrices.begin()) {
        return -1;
    } else {
        it--;
        int best_ticket_price = *it;
        ticketPrices.erase(it);
        return best_ticket_price;
    }
}

void solve() {
    int num_tickets, num_customers;
    cin >> num_tickets >> num_customers;

    multiset<int> available_tickets;

    for (int i = 0; i < num_tickets; i++) {
        int ticket_price;
        cin >> ticket_price;
        available_tickets.insert(ticket_price);
    }

    vi max_customer_prices(num_customers);

    for (int i = 0; i < num_customers; i++) {
        cin >> max_customer_prices[i];
    }

    for (int price : max_customer_prices) {
        int best_ticket_price = getUpperBound(price, available_tickets);
        cout << best_ticket_price << '\n';
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
