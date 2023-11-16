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

const int BOARD_SIZE = 8;
const int STATES = 64;
const int MAX_MOVES = 105;

using ld = long double;

ld dp[STATES][STATES][MAX_MOVES] = {0};

int dirCount(int x, int y) {
    int moves = 0;
    if (x + 1 < BOARD_SIZE) moves++;
    if (y + 1 < BOARD_SIZE) moves++;
    if (x - 1 >= 0) moves++;
    if (y - 1 >= 0) moves++;
    return moves;
}

ld calc(int x, int y, int moves) {
    int row = x / BOARD_SIZE, col = x % BOARD_SIZE;
    ld prob = 0;

    if (row + 1 < BOARD_SIZE) prob += 1.0 / dirCount(row + 1, col) * dp[row * BOARD_SIZE + 8 + col][y][moves - 1];
    if (col + 1 < BOARD_SIZE) prob += 1.0 / dirCount(row, col + 1) * dp[row * BOARD_SIZE + col + 1][y][moves - 1];
    if (row - 1 >= 0) prob += 1.0 / dirCount(row - 1, col) * dp[row * BOARD_SIZE - 8 + col][y][moves - 1];
    if (col - 1 >= 0) prob += 1.0 / dirCount(row, col - 1) * dp[row * BOARD_SIZE + col - 1][y][moves - 1];

    return prob;
}

void solve() {
    int k;
    cin >> k;

    for (int i = 0; i < STATES; i++) dp[i][i][0] = 1;

    for (int moves = 1; moves <= k; moves++) {
        for (int current = 0; current < STATES; current++) {
            for (int target = 0; target < STATES; target++) {
                dp[current][target][moves] = calc(current, target, moves);
            }
        }
    }

    ld result = 0;
    for (int current = 0; current < STATES; current++) {
        ld temp = 1;
        for (int target = 0; target < STATES; target++) {
            temp *= (1 - dp[current][target][k]);
        }
        result += temp;
    }

    cout << fixed << setprecision(6) << result;
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
