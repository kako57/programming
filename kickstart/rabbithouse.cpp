#include <bits/stdc++.h>

using namespace std;

int64_t grid[300][300];
const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};

void wee() {
  int rows, cols;
  cin >> rows >> cols;
  uint64_t ans = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      queue<pair<int, int>> q;
      q.push({i, j});
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
          int ni = x + di[d], nj = y + dj[d];
          if (0 <= ni && ni < rows && 0 <= nj && nj < cols
              && grid[ni][nj] + 1 < grid[x][y]) {
            ans += grid[x][y] - grid[ni][nj] - 1;
            grid[ni][nj] = grid[x][y] - 1;
            q.push({ni, nj});
          }
        }
      }
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
