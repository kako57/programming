#include <bits/stdc++.h>

using namespace std;

void wee() {
  int n;
  cin >> n;
  vector<pair<int, int>> commands;
  for (int i = 0; i < n; i++) {
    int t, x;
    cin >> t >> x;
    commands[i] = {t, x};
  }
  commands.emplace_back(1e9+5, 0);
  int ct = 0, cx = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    int t, int x;
    tie(t, x) = commands[i];
    int dt = t - ct;
    int dx = abs(x - cx);
    if (
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  wee();
}
