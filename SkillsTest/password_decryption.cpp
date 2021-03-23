#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  string s, nums = "", chars = "";
  getline(cin, s);
  int j = 0, i = 0;
  for (i = 0; s[i] && s[i] >= '1' && s[i] <= '9'; i++) {
    nums.push_back(s[i]);
  }
  reverse(nums.begin(), nums.end());
  for (; s[i]; i++) {
    if (s[i] == '*') {
      swap(chars[chars.size() - 1], chars[chars.size() - 2]);
    } else if (s[i] == '0') {
      chars.push_back(nums[j++]);
    } else {
      chars.push_back(s[i]);
    }
  }
  cout << chars << '\n';
}
