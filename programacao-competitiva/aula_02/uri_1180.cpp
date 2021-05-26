#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, posicao_do_menor = 0, menor = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (i == 0) {
            menor = x;
        } else if (x < menor) {
            menor = x;
            posicao_do_menor = i;
        }
    }

    cout << "Menor valor: " << menor << endl;
    cout << "Posicao: " << posicao_do_menor << endl;


    return 0;
}
