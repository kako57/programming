#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // find all maximal and minimal fret for each note
  Solution() {
    int64_t a[6];
    for (int i = 0; i < 6; i++) {
      cin >> a[i];
    }
    sort(a, a+6);
    int n;
    cin >> n;
    vector<int64_t> notes(n);
    for (int i = 0; i < n; i++) {
      cin >> notes[i];
    }
    vector<int64_t> maximals(n, 0), minimals(n, 1e18);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 6; j++) {
        maximals[i] = max(maximals[i], notes[i] - a[j]);
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 6; j++) {
        minimals[i] = min(minimals[i], notes[i] - a[j]);
      }
    }
    int64_t mn = *max_element(minimals.begin(), minimals.end()),
            mx = *min_element(maximals.begin(), maximals.end());
    cout << abs(mx - mn) << '\n';
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  Solution();
}
