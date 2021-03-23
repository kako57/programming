#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  Solution() {
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
      cin >> l[i];
    }
    sort(l.begin(), l.end());
    int ans = 0;
    for (int a = 0; a < n-2; a++) {
      for (int b = a+1; b < n-1; b++) {
        if (l[a] == l[b]) continue;
        for (int c = b + 1; c < n; c++) {
          if (l[c] == l[b]) continue;
          else if (l[c] < l[a] + l[b]) ans++;
          else break;
        }
      }
    }
    cout << ans << endl;
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  Solution();
}
