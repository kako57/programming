#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  int mn = atoi(argv[1]);
  int m = rnd.next(1,mn);
  int n = rnd.next(1,mn);
  vector<int> rows(m);
  vector<int> cols(n);
  int s = 0;
  for (int i = 0; i < m; i++) {
    rows[i] = rnd.next(n+1);
    s += rows[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cols[i] = rnd.next(min(s,m+1));
    s -= cols[i];
  }
  cols[n - 1] = min(s, m);
  println(m, n);
  println(rows);
  println(cols);
}
