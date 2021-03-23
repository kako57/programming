#include <bits/stdc++.h>

using namespace std;

class Addition {
public:
  Addition(int n = 1) {
    srand(time(NULL));
    for (int question = 0; question < n; question++) {
      int a = rand() % 10, b = rand() % 10, guess, ans = a + b;
      cout << a << " + " << b << " = " << flush;
      cin >> guess;
      if (guess == ans) {
        cout << "Correct" << endl;
      } else {
        cout << "Wrong" << endl;
      }
    }
  }
};

class Subtraction {
public:
  Subtraction(int n = 1) {
    srand(time(NULL));
    for (int question = 0; question < n; question++) {
      int a = rand() % 20 + 1, b = rand() % a, guess, ans = a - b;
      cout << a << " - " << b << " = " << flush;
      cin >> guess;
      if (guess == ans) {
        cout << "Correct" << endl;
      } else {
        cout << "Wrong" << endl;
      }
    }
  }
};

class Multiplication {
public:
  Multiplication(int n = 1) {
    srand(time(NULL));
    for (int question = 0; question < n; question++) {
      // int a = rand() % 11;
      int a = rand() % 2 + 4;
      int b = rand() % 11;
      int guess;
      int ans = a * b;
      cout << a << " x " << b << " = " << flush;
      cin >> guess;
      if (guess == ans) {
        cout << "Correct" << endl;
      } else {
        cout << "Wrong" << endl;
      }
    }
  }
};

class Random {
public:
  Random(int n) {
    srand(time(NULL));
    for (int question = 0; question < n; question++) {
      int a = rand() % 3;
      if (a == 0)
        Addition *a = new Addition();
      else if (a == 1)
        Subtraction *s = new Subtraction();
      else if (a == 2)
        Multiplication *m = new Multiplication();
      else
        assert(false);
    }
  }
};

class Menu {
public:
  Menu() {
    cout << "GEGETEST!" << endl;
    cout << "[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Random\nChoose [1/2/3/4]: " << flush;
    int choice, q;
    cin >> choice;
    cout << "Number of questions: " << flush;
    cin >> q;
    if (choice == 1)
      Addition *a = new Addition(q);
    else if (choice == 2)
      Subtraction *s = new Subtraction(q);
    else if (choice == 3)
      Multiplication *m = new Multiplication(q);
    else if (choice == 4)
      Random *r = new Random(q);
    else
      assert(false);
  }
};

int main() {
  Menu();
}
