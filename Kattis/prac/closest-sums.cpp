#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, prob = 1;
  while (cin >> n) {
    cout << "Case " << prob++ << ":" << endl;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        b.push_back(a[i] + a[j]);
      }
    }
    sort(b.begin(), b.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      auto it1 = lower_bound(b.begin(), b.end(), x);
      auto it2 = it1 - 1;
      cout << "Closest sum to " << x << " is ";
      if (it1 == b.begin()) {
        cout << b.front();
      } else {
        cout << (abs(*it1 - x) < abs(*it2 - x) ? *it1 : *it2);
      }
      cout << '.' << endl;
    }
  }
}
