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

  for (int i : rows) {
    if (i > n) {
      cout << "no solution" << endl;
      return 0;
    }
  }
  for (int i : columns) {
    if (i > m) {
      cout << "no solution" << endl;
      return 0;
    }
  }

  sort(rows.begin(), rows.end());
  sort(columns.rbegin(), columns.rend());

  for (int i : rows) cerr << i << ' ';
  cerr << endl;
  for (int i : columns) cerr << i << ' ';
  cerr << endl;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < rows[i]; j++) {
      a[i][j] = 1;
    }
  }

  debug(a);

  vector<int> spr(m, 0);

  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < m; j++) {
      s += a[j][i];
    }
    if (s > columns[i]) {
      for (int j = 0; j < m && s != columns[i]; j++) {
        if (a[j][i]) {
          a[j][i] = 0;
          spr[j]++;
          s--;
        }
      }
    } else if (s < columns[i]) {
      for (int j = 0; j < m && s != columns[i]; j++) {
        if (spr[j]) {
          spr[j]--;
          a[j][i] = 1;
          s++;
        }
      }
    }
  }

  debug(a);

  bool ok = true;
  for (int i : spr) {
    ok &= (i == 0);
  }

  if (ok) {
    cout << "ez" << endl;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j] << " \n"[j+1==n];
      }
    }
  } else {
    cout << "no way" << endl;
  }
}
