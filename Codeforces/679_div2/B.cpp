#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  Solution() {
    int n, m; // row col
    cin >> n >> m;
    vector<int> idx(n*m+1, -1);
    vector<vector<int>> row(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> row[i][j];
        idx[row[i][j]] = i;
      }
    }
    vector<int> ord(n);
    for (int i = 0; i < n; i++) {
      cin >> ord[i];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int d;
        cin >> d;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << row[idx[ord[i]]][j] << " \n"[j+1==m];
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--)
  Solution();
}
