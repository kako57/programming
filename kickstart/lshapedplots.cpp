#include <bits/stdc++.h>

using namespace std;

int a[1002][1002];
const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};
int64_t cnt[4];

void wee() {
  memset(a, 0, sizeof(a));
  int rows, cols;
  cin >> rows >> cols;
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= cols; j++) {
      cin >> a[i][j];
    }
  }
  uint64_t ans = 0;
  for (int i = 1; i <= rows; i++) {
    for (int j = 1; j <= cols; j++) {
      for (int d = 0; d < 4; d++) {
        int k = 0;
        while (a[i + di[d] * k][j + dj[d] * k] != 0) {
          k++;
        }
        cnt[d] = k;
      }
      for (int k = 0; k < 2; k++) {
        for (int l = 2; l < 4; l++) {
          ans += max(0L, min(2 * cnt[k], cnt[l]) / 2 - 1);
          ans += max(0L, min(2 * cnt[l], cnt[k]) / 2 - 1);
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
