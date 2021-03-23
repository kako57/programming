#include <bits/stdc++.h>

using namespace std;

void wee() {
  int64_t n, k, s;
  cin >> n >> k >> s;
  int64_t ans = min(k + n, n + 2 * k - 2 * s);
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
