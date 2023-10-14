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

const vi dx = {-2, -2, -1, -1, 1, 1, 2, 2};
const vi dy = {-1, 1, -2, 2, -2, 2, -1, 1};
vector<vi> chessboard(8, vi(8));

bool is_valid(int x, int y) {
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int knight_degree(int x, int y) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny) && !chessboard[nx][ny]) {
            count++;
        }
    }
    return count;
}

bool solve_knights_tour(int x, int y, int depth = 1) {
    chessboard[x][y] = depth;
    if (depth == 64) {
        return true;
    }

    vector<vi> neighbors;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny) && !chessboard[nx][ny]) {
            neighbors.pb({knight_degree(nx, ny), nx, ny});
        }
    }
    sort(all(neighbors));

    for (auto neighbor : neighbors) {
        int nx = neighbor[1];
        int ny = neighbor[2];
        if (solve_knights_tour(nx, ny, depth + 1)) {
            return true;
        }
    }

    chessboard[x][y] = 0;
    return false;
}

void solve() {
    int x, y;
    cin >> y >> x;
    
    solve_knights_tour(x - 1, y - 1);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << chessboard[i][j] << " ";
        }
        cout << "\n";
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
