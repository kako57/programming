#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int64_t n, k;
  cin >> n;
  vector<int64_t> a(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> k;
  sort(a.begin(), a.end());
  int64_t sum = 0, i = 0;
  for (i = 0; i < n && sum + a[i] <= k; i++) {
    sum += a[i];
  }
  cout << i << '\n';
}
