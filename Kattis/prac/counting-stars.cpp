#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, prob = 0;
  vector<int> dr{-1,1,0,0};
  vector<int> dc{0,0,-1,1};
  while (cin >> n >> m) {
    vector<vector<char>> a(n, vector<char>(m));
    vector<pair<int,int>> b;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if (a[i][j] == '-') {
          b.push_back({i,j});
        }
      }
    }
    int ans = 0;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    for (pair<int,int> p : b) {
      int r = p.first;
      int c = p.second;
      if (!visited[r][c]) {
        ++ans;
        queue<pair<int,int>> q;
        q.push({r,c});
        while (!q.empty()) {
          pair<int,int> cur = q.front();
          q.pop();
          visited[cur.first][cur.second] = true;
          for (int i = 0; i < 4; ++i) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m
                && !visited[nr][nc] && a[nr][nc] == '-') {
              q.push({nr,nc});
            }
          }
        }
      }
    }
    cout << "Case " << ++prob << ": " << ans << endl;
  }
}
