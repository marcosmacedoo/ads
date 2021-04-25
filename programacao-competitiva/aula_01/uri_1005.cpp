#include <bits/stdc++.h>

using namespace std;

int main() {
  double first_number, second_number, mean;

  cin >> first_number >> second_number;

  mean = ((first_number * 3.5) + (second_number * 7.5)) / 11.0;

  cout << "MEDIA = " << fixed << setprecision(5) << mean << endl; 

  return 0;
}