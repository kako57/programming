#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int c = n;
    cout << 2 << '\n';
    for (int i = n-1; i >= 1; i--) {
      cout << c << ' ' << i << '\n';
      c = (c + i + 1) / 2;
    }
  }
}
