#include <bits/stdc++.h>

using namespace std;

struct Circle {
  int x;
  int y;
  int r;
};

int main() {
  int n;
  cin >> n;
  vector<Circle> circles;
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    circles.push_back(Circle{x,y,r});
  }
}
