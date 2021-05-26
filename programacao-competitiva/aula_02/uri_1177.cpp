#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y;
  vector<int> numbers;

  cin >> x;

  for (int i = 0; i < 1000; i++) {
    if (i % x == 0) {
      y = 0;
    }

    cout << "N[" << i << "] = " << y << endl;
    y++;
  }
}