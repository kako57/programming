#include <bits/stdc++.h>

using namespace std;

void wee() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int l = 0, r = n - 1; l < r; l++, r--) {
    k -= s[l] != s[r];
  }
  cout << abs(k) << '\n';
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
