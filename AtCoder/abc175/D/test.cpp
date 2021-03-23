#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  Solution() {
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> p(n+1), c(n+1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    // choose where to start
    // find cycles, and the change in value for each cycle
    int64_t ans = -1e18;
    for (int start = 1; start <= n; start++) {
      int64_t cycle_length = 0, cycle_sum = 0, prev = start;
      while (true) {
        int64_t nxt = p[prev];
        cycle_sum += c[nxt];
        cycle_length++;
        prev = nxt;
        if (prev == start) break;
      }
      int64_t ext = 0, cnt = 0;
      while (true) {
        cnt++;
        ext += c[prev]; // extra score added aside from the cycle length
        if (cnt > k) {
          break; // happens if cycle length is greater than k
        }
        int64_t num_cycles = (k - cnt) / cycle_length;
        int64_t tmp = ext + max((int64_t) 0, cycle_sum) * num_cycles;
        ans = max(tmp, ans);
        prev = p[prev];
        if (start == prev) {
          break;
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
