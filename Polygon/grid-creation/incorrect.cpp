#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void debug(vector<vector<bool>>& a) {
  int m = a.size();
  int n = a[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cerr << a[i][j] << " \n"[j+1==n];
    }
  }
  cerr << endl;
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<int> rows(m);
  vector<int> columns(n);
  vector<vector<bool>> a(m, vector<bool>(n, 0));
  for (int i = 0; i < m; i++) {
    cin >> rows[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> columns[i];
  }
  sort(rows.begin(), rows.end());
  sort(columns.begin(), columns.end());

  for (int i : rows) cerr << i << ' ';
  cerr << endl;
  for (int i : columns) cerr << i << ' ';
  cerr << endl;

  for (int i = 0; i < m; i++) {
    int cur = rows[i];
    for (int j = 0; j < cur; j++) {
      a[i][n - 1 - j] = 1;
    }
  }

  debug(a);

  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < m; j++) {
      s += a[j][i];
    }
    if (s > columns[i]) {
      for (int j = 0; s != columns[i] && j < m; j++) {
        if (a[j][i] == 1) {
          a[j][i] = 0;
          s--;
        }
      }
    } else if (s < columns[i]) {
      for (int j = m - 1; s != columns[i] && j >= 0; j--) {
        if (a[j][i] == 0) {
          a[j][i] = 1;
          s++;
        }
      }
    }
  }

  debug(a);

  for (int i = 0; i < m; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) {
      s += a[i][j];
    }
    if (s > rows[i]) {
      for (int j = 0; s != rows[i] && j < n; j++) {
        if (a[i][j] == 1) {
          a[i][j] = 0;
          s--;
        }
      }
    } else if (s < rows[i]) {
      for (int j = 0; s != rows[i] && j < n; j++) {
        if (a[i][j] == 0) {
          a[i][j] = 1;
          s++;
        }
      }
    }
  }

  debug(a);

  bool ok = true;
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < m; j++) {
      s += a[j][i];
    }
    if (s != columns[i]) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "YES\n";
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (j != 0) {
          cout << ' ';
        }
        cout << a[i][j];
      }
      cout << '\n';
    }
  } else {
    cout << "NO\n";
  }
}
