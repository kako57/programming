#include <bits/stdc++.h>

using namespace std;

void wee() {
  int l, r, a;
  cin >> l >> r;
  a = r + 1;
  if (2*(l % a) >= a) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--)
  wee();
}
