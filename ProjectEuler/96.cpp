#include <bits/stdc++.h>

using namespace std;

int m[9][9], ans = 0;

void print_matrix() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << m[i][j] << " \n"[j+1==9];
        }
    }
}

bool possible(int y, int x, int n) {
    for (int i = 0; i < 9; i++)
        if (m[y][i] == n)
            return false;
    for (int i = 0; i < 9; i++)
        if (m[i][x] == n)
            return false;
    int x0 = (x / 3) * 3,
        y0 = (y / 3) * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (m[y0+i][x0+j] == n)
                return false;
    return true;
}

void solve() {
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            if (m[y][x] == 0) {
                for (int n = 1; n < 10; n++) {
                    if (possible(y,x,n)) {
                        m[y][x] = n;
                        solve();
                        m[y][x] = 0;
                    }
                }
                return;
            }
        }
    }
    ans += m[0][0] * 100 + m[0][1] * 10 + m[0][2];
}

int main() {
    freopen("sudoku.txt", "r", stdin);
    string s;
    while (cin >> s >> s) {
        memset(m, 0, sizeof m);
        for (int i = 0; i < 9; i++) {
            cin >> s;
            for (int j = 0; j < 9; j++) {
                m[i][j] = s[j] - '0';
            }
        }
        solve();
    }
    cout << ans << endl;
}

