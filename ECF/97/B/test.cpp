#include <bits/stdc++.h>

using namespace std;

void wee() {
  int n;
  string s;
  cin >> n >> s;
  int ans1 = 0, ans2 = 0;
  {
    string t = s;
    int i = 0, j = n - 1;
    while (i < j) {
      cerr << t << endl;
      if (t.empty()) {
        cerr << "t is empty" << endl;
      }
      {
        char c;
        cin >> c;
      }
      while (t[i] - '0' == i % 2) i++;
      while (t[j] - '0' == j % 2) j--;
      if (i < j) {
        while (i < j) {
          t[i] ^= t[j];
          t[j] ^= t[i];
          t[i] ^= t[j];
        }
        ans1++;
      }
    }
  }
  {
    string t = s;
    int i = 0, j = n - 1;
    while (i < j) {
      while (t[i] - '0' != i % 2) i++;
      while (t[j] - '0' != j % 2) j--;
      if (i < j) {
        while (i < j) {
          t[i] ^= t[j];
          t[j] ^= t[i];
          t[i] ^= t[j];
        }
        ans2++;
      }
    }
  }
  cout << min(ans1, ans2) << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--)
  wee();
}
