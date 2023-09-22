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

const int N = 8;
vector<string> board(N);
vector<bool> col(N), diag1(2 * N - 1), diag2(2 * N - 1);
int countQueens = 0;

bool isSafe(int r, int c) {
    return !col[c] && !diag1[r + c] && !diag2[r - c + N - 1];
}

void placeQueen(int row) {
    if (row == N) {
        countQueens++;
        return;
    }

    for (int c = 0; c < N; c++) {
        if (board[row][c] == '.' && isSafe(row, c)) {
            col[c] = diag1[row + c] = diag2[row - c + N - 1] = true;
            placeQueen(row + 1);
            col[c] = diag1[row + c] = diag2[row - c + N - 1] = false;
        }
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    placeQueen(0);
    cout << countQueens << "\n";
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
