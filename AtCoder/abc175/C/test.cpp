#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  Solution() {
    int64_t x, k, d;
    cin >> x >> k >> d;
    // start at x, do exactly k moves of distance d
    int64_t tmp;
    if (x > 0) {
      tmp = min((x + d) / d, k);
      x -= tmp * d;
      k -= tmp;
      x = x + d * (k&1);
      k = 0;
    } else if (x < 0) {
      tmp = min((-x + d) / d, k);
      x += tmp * d;
      k -= tmp;
      x = x - d * (k&1);
      k = 0;
    } else {
      // arrives at 0 => we can just alternate at d and 0
      x = d * (k&1);
      k = 0;
    }
    cerr << k << ' ' << tmp << ' ' << x << endl;
    cout << abs(x) << endl;
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  Solution();
}
