#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int x, y;
  cin >> x >> y;
  cout << 2 * bool(y < 0) + (bool) ((x > 0) != (y > 0)) + 1 << endl;
}
