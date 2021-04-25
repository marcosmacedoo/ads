#include <bits/stdc++.h>

using namespace std;

int main() {
  int amount_input;

  cin >> amount_input;

  for (int i = 0; i < amount_input; i++) {
    int a, b;

    cin >> a >> b;

    if (b == 0) {
      cout << "divisao impossivel" << endl;
    } else {
      double division = (double) a / b;
      cout << fixed << setprecision(1) << division << endl;
    }

  }

  return 0;
}