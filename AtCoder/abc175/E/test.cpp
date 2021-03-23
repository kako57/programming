#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  Solution() {
    int R, C, K;
    cin >> R >> C >> K;
    vector<vector<int64_t>> a(R+1, vector<int64_t>(C+1, 0));
    for (int i = 0; i < K; i++) {
      int r, c, v;
      cin >> r >> c >> v;
      a[r][c] = v;
    }
    vector<vector<vector<int64_t>>> dp(R+1, vector<vector<int64_t>>(C+1, vector<int64_t>(4, 0)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        for (int k = 0; k <= 3; k++) {
          mxs(dp[i][j][0], dp[i-1][j][k]); // nothing to take => get value above and left
          mxs(dp[i][j][1], dp[i-1][j][k] + a[i][j]); // take one => add a[i][j] to above and left
          mxs(dp[i][j][k], dp[i][j-1][k]); // take k => compare with left with k items
          if (k >= 1) {
            mxs(dp[i][j][k], dp[i][j-1][k-1] + a[i][j]); // see if a[i][j] will add more value
          }
        }
      }
    }
    int64_t ans = 0;
    for (int k = 0; k <= 3; k++) {
      mxs(ans, dp[R][C][k]);
    }
    cout << ans << endl;
  }
  template<typename T>
  void mxs(T& a, T b) {
    if (a < b) {
      a = b;
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  Solution();
}
