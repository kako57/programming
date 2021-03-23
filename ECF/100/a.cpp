#include <bits/stdc++.h>

using namespace std;

void wee() {
  int a, b, c;
  cin >> a >> b >> c;
  int s = a + b + c;
  int d = s / 9;
  if (s % 9 == 0 && a >= d && b >= d && c >= d) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    wee();
}
