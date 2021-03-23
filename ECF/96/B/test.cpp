#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int64_t T;
  cin >> T;
  while (T--) {
    int64_t n, k, mx = 0;
    cin >> n >> k;
    vector<uint64_t> a(n);
    for (auto& i : a) cin >> i;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i <= k; i++) {
      mx += a[i];
    }
    cout << mx << '\n';
  }
}
