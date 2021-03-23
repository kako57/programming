#include <bits/stdc++.h>

using namespace std;

int64_t grid[300][300];
const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};


void wee() {
  int rows, cols;
  cin >> rows >> cols;
  memset(grid, 0, sizeof(grid));
  uint64_t ans = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> grid[i][j];
    }
  }
  int count = 0;
  bool check_again;
  do {
    check_again = false;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        for (int d = 0; d < 4; d++) {
          int ni = i + di[d], nj = j + dj[d];
          if (0 <= ni && ni < rows && 0 <= nj && nj < cols) {
            int diff = grid[i][j] - grid[ni][nj];
            if (diff > 1) {
              grid[ni][nj] = diff - 1;
              ans += diff - 1;
              check_again = true;
            }
          }
        }
      }
    }
    if (++count % 10000 == 0) {
      cerr << count << endl;
    }
  } while (check_again);
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

