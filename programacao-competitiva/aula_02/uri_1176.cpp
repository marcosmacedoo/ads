#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t primeiro, segundo, soma;
    int posicao, n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> posicao;

        primeiro = 0;
        segundo = 1;

        if (posicao == 0) {
            cout << "Fib(0) = 0" << endl;
        } else if (posicao == 1) {
            cout << "Fib(1) = 1" << endl;
        } else {
            for (int j = 2; j < posicao + 1; j++) {
                soma = primeiro + segundo;
                primeiro = segundo;
                segundo = soma;
            }
            cout << "Fib(" << posicao  << ") = " << soma << endl;
            soma = 0;
        }


    }


    return 0;
}
