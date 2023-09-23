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

// 2D grid to track visited cells
vector<vector<bool>> visited(9, vector<bool>(9));

// Variables for counting paths and tracking current position
int countPaths = 0, currentIndex = -1;

// Function to check if a cell is a valid one-way path based on specific conditions
bool isValid(int i, int j) {
    return (i - 7 && j - 1 && !visited[i - 1][j] + !visited[i + 1][j] + !visited[i][j + 1] + !visited[i][j - 1] == 1);
}

// Depth-First Search (DFS) function to explore paths in the grid
void dfs(int row, int col, const string& path) {
    // Check if the DFS traversal has reached the destination (7, 1)
    if (row == 7 && col == 1) {
        // Check if the current path length is 47, increment countPaths if true
        countPaths += currentIndex == 47;
        return;
    }
    
    // Increment the currentIndex to move to the next character in the path string
    ++currentIndex;
    // Mark the current cell as visited
    visited[row][col] = 1;
    
    // Check if moving right is a valid option and follows the path string
    if (!visited[row][col + 1] && isValid(row, col + 1)) {
        if (path[currentIndex] == '?' || path[currentIndex] == 'R') {
            dfs(row, col + 1, path);
        }
        // Backtrack by decrementing currentIndex and marking the cell as unvisited
        --currentIndex;
        visited[row][col] = 0;
        return;
    }
    
    // Check if moving left is a valid option and follows the path string
    if (!visited[row][col - 1] && isValid(row, col - 1)) {
        if (path[currentIndex] == '?' || path[currentIndex] == 'L') {
            dfs(row, col - 1, path);
        }
        // Backtrack by decrementing currentIndex and marking the cell as unvisited
        --currentIndex;
        visited[row][col] = 0;
        return;
    }
    
    // Check if moving down is a valid option and follows the path string
    if (!visited[row + 1][col] && isValid(row + 1, col)) {
        if (path[currentIndex] == '?' || path[currentIndex] == 'D') {
            dfs(row + 1, col, path);
        }
        // Backtrack by decrementing currentIndex and marking the cell as unvisited
        --currentIndex;
        visited[row][col] = 0;
        return;
    }
    
    // Check if moving up is a valid option and follows the path string
    if (!visited[row - 1][col] && isValid(row - 1, col)) {
        if (path[currentIndex] == '?' || path[currentIndex] == 'U') {
            dfs(row - 1, col, path);
        }
        // Backtrack by decrementing currentIndex and marking the cell as unvisited
        --currentIndex;
        visited[row][col] = 0;
        return;
    }
    
    // Check if moving right (R) is a valid option and follows the path string
    if (!visited[row][col + 1] && (path[currentIndex] == '?' || path[currentIndex] == 'R')) {
        // Check if the cell two steps to the right is not visited
        // and if the diagonal cells (top-right and bottom-right) are not blocked
        if (!(visited[row][col + 2] && !visited[row + 1][col + 1] && !visited[row - 1][col + 1])) {
            // If conditions are met, recursively explore the path by moving right
            dfs(row, col + 1, path);
        }
    }

    // Check if moving down (D) is a valid option and follows the path string
    if (!visited[row + 1][col] && (path[currentIndex] == '?' || path[currentIndex] == 'D')) {
        // Check if the cell two steps down is not visited
        // and if the diagonal cells (bottom-left and bottom-right) are not blocked
        if (!(visited[row + 2][col] && !visited[row + 1][col - 1] && !visited[row + 1][col + 1])) {
            // If conditions are met, recursively explore the path by moving down
            dfs(row + 1, col, path);
        }
    }

    // Check if moving left (L) is a valid option and follows the path string
    if (!visited[row][col - 1] && (path[currentIndex] == '?' || path[currentIndex] == 'L')) {
        // Check if the cell two steps to the left is not visited
        // and if the diagonal cells (top-left and bottom-left) are not blocked
        if (!visited[row][col - 1] && !(visited[row][col - 2] && !visited[row - 1][col - 1] && !visited[row + 1][col - 1])) {
            // If conditions are met, recursively explore the path by moving left
            dfs(row, col - 1, path);
        }
    }

    // Check if moving up (U) is a valid option and follows the path string
    if (!visited[row - 1][col] && (path[currentIndex] == '?' || path[currentIndex] == 'U')) {
        // Check if the cell two steps up is not visited
        // and if the diagonal cells (top-left and top-right) are not blocked
        if (!(visited[row - 2][col] && !visited[row - 1][col - 1] && !visited[row - 1][col + 1])) {
            // If conditions are met, recursively explore the path by moving up
            dfs(row - 1, col, path);
        }
    }

    
    // If none of the above conditions are met, backtrack by decrementing currentIndex and marking the cell as unvisited
    --currentIndex;
    visited[row][col] = 0;
}

void solve() {
    string path;
    cin >> path;

    // Initialize the visited grid based on grid edge conditions
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            visited[row][col] = row == 8 || !row || col == 8 || !col;
        }
    }

    // Start the DFS traversal from the initial position (1, 1) with the given path string
    dfs(1, 1, path);
    cout << countPaths << " ";
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
