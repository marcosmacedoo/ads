#include <bits/stdc++.h>

using namespace std;

int main() {
  int x, y, maior, menor, soma = 0;

  cin >> x >> y;

  if (x > y) {
    maior = x;
    menor = y;
  } else {
    maior = y;
    menor = x;
  }

  for (int i = maior - 1; i > menor; i--) {
    if ((i % 2) != 0) {
      soma += i;
    }
  }

  cout << soma << endl;


  return 0;
}