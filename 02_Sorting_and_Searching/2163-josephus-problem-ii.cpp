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
    
    int size = 1;
    while (size < n) {
        size <<= 1;
    }
    
    vi order(2 * size, 1);
    
    for (int i = size - 1; i > 0; --i) {
        order[i] = 2 * order[2 * i];
    }
    
    int pos = 0;
    
    while (n--) {
        pos += k;
        pos %= n + 1;
        int child = pos;
        int node = 1;
        
        while (node < size) {
            node *= 2;
            
            if (order[node] <= child) {
                child -= order[node];
                node += 1;
            }
            
            order[node] -= 1;
        }
        
        cout << node - size + 1 << " ";
    }
    
    cout << endl;
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
