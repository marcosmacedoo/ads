#include <bits/stdc++.h>

using namespace std;

int main() {
  double n1, n2, n3, n4;
  double p1 = 2.0, p2 = 3.0, p3 = 4.0, p4 = 1.0;

  cin >> n1 >> n2 >> n3 >> n4;

  double media = ((n1 * p1) + (n2 * p2) + (n3 * p3) + (n4 * p4)) / (p1 + p2 + p3 + p4);

  cout << "Media: " << fixed << setprecision(1) << media << endl;

  if (media >= 7.0) {
    cout << "Aluno aprovado." << endl;
  } else if (media < 5.0) {
    cout << "Aluno reprovado." << endl;
  } else {
    cout << "Aluno em exame." << endl;

    double nova_nota ;

    cin >> nova_nota;

    cout << "Nota do exame: " << fixed << setprecision(1) << nova_nota << endl;

    double media_final = (nova_nota + media) / 2.0;

    if (media_final >= 5.0) {
      cout << "Aluno aprovado." << endl;
    } else {
      cout << "Aluno reprovado." << endl;
    }

    cout << "Media final: " << fixed << setprecision(1) << media_final << endl;
  }

  return 0;
}