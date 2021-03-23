#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  Solution() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i += 2) {
      int l = (a[i] * a[i+1]) / __gcd(a[i],a[i+1]);
      ans[i] = l / a[i];
      ans[i+1] = - l / a[i+1];
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i+1==n];
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    Solution();
  }
}
