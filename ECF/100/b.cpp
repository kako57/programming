#include <bits/stdc++.h>

using namespace std;

void wee() {
  int64_t n;
  cin >> n;
  vector<int64_t> a(n);
  for (int64_t& i : a) cin >> i;
  for (int64_t i = 1; i < n; i++) {
    if (a[i] % a[i-1] == 0 || a[i-1] % a[i] == 0) {
      continue;
    }
    int m;
    if (a[i] > a[i-1]) {
      m = a[i] % a[i-1];
      if (m < (a[i-1] + 1) / 2) {
        a[i] -= m;
      } else {
        a[i] += a[i-1] - m;
      }
    } else {
      m = a[i-1] % a[i];
      if (m < (a[i] + 1) / 2) {
        a[i-1] -= m;
      } else {
        a[i-1] += a[i] - m;
      }
    }
  }
  for (int64_t i = 0; i < n; i++) {
    cout << a[i] << " \n"[i+1==n];
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    wee();
}
