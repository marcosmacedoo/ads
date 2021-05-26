#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n, tempo_total = 0, quantidade_de_questoes_corretas = 0,
        tempo_da_questao = 0, quantidade_de_incorretas = 0;
    string alternativa, resultado;

    while (1)
    {
        cin >> n;

        if (n == 0)
        {
            break;
        }

        quantidade_de_questoes_corretas = 0;
        tempo_total = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> alternativa >> tempo_da_questao >> resultado;

            if (resultado == "incorrect")
            {
                quantidade_de_incorretas += 1;
            }
            else
            {
                if (quantidade_de_incorretas == 0)
                {
                    tempo_total += tempo_da_questao;
                }
                else
                {
                    tempo_total += tempo_da_questao + (20 * quantidade_de_incorretas);
                }
                quantidade_de_questoes_corretas++;
                quantidade_de_incorretas = 0;
            }
        }

        cout << quantidade_de_questoes_corretas << " " << tempo_total << endl;
    }

    return 0;
}
