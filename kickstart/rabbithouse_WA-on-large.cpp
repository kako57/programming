#include <bits/stdc++.h>

using namespace std;

int64_t grid[300][300];

void wee() {
  int rows, cols;
  cin >> rows >> cols;
  // memset(grid, 0, sizeof(grid));
  uint64_t ans = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> grid[i][j];
      if (j - 1 >= 0) { // left
        int64_t diff = grid[i][j] - grid[i][j-1];
        int64_t add = abs(diff) - 1;
        if (diff > 1) { // current is bigger than on left
          grid[i][j-1] += add;
          ans += add;
        } else if (diff < -1) { // left is bigger than current
          grid[i][j] += add;
          ans += add;
        }
      }
      if (i - 1 >= 0) { // up
        int64_t diff = grid[i][j] - grid[i-1][j];
        int64_t add = abs(diff) - 1;
        if (diff > 1) { // current is bigger than above
          grid[i-1][j] += add;
          ans += add;
        } else if (diff < -1) { // above is bigger than current
          grid[i][j] += add;
          ans += add;
        }
      }
    }
  }
  for (int i = rows; i >= 0; i--) {
    for (int j = cols; j >= 0; j--) {
      // cin >> grid[i][j];
      if (j - 1 >= 0) { // left
        int64_t diff = grid[i][j] - grid[i][j-1];
        int64_t add = abs(diff) - 1;
        if (diff > 1) { // current is bigger than on left
          grid[i][j-1] += add;
          ans += add;
        }
      }
      if (i - 1 >= 0) { // up
        int64_t diff = grid[i][j] - grid[i-1][j];
        int64_t add = abs(diff) - 1;
        if (diff > 1) { // current is bigger than above
          grid[i-1][j] += add;
          ans += add;
        }
      }
    }
  }
  cout << '\n';
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << grid[i][j] << " \n"[j + 1 == cols];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ": ";
    wee();
  }
}
