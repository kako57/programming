#include <bits/stdc++.h>

using namespace std;

int64_t next(int prev) {
  string s = to_string(prev);
  for (int i = s.length() - 1; i >= 0; i++) {
  }
}

void wee() {
  int64_t l, r, ans = 0;
  cin >> l >> r;
  for (int64_t i = l; i <= r; i++) {
    if (boring(i)) {
      ans++;
    }
  }
  cout << ans << endl;
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
