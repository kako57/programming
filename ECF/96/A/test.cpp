#include <bits/stdc++.h>

using namespace std;

void wee() {
  int n;
  cin >> n;
  if (n == 1 || n == 2 || n == 4) {
    cout << -1 << '\n';
    return;
  }
  if (n % 3 == 0) {
    cout << n / 3 << " 0 0\n";
  } else if (n % 3 == 1) {
    cout << (n - 7) / 3 << " 0 1\n";
  } else {
    cout << (n - 5) / 3 << " 1 0\n";
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--)
  wee();
}
