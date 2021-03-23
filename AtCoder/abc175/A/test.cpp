#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  Solution() {
    string s;
    cin >> s;
    if (s == "SSS") {
      cout << "0\n";
    } else if (s == "RRR") {
      cout << "3\n";
    } else if (s == "RRS" || s == "SRR") {
      cout << "2\n";
    } else {
      cout << "1\n";
    }
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  Solution();
}
