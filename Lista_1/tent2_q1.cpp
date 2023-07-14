#include <iostream>

using namespace std;



int main()
{
    int n_itens;
    int n_queries;
    
    cin >> n_itens >> n_queries;
    int lista_precos[n_itens];

    //formndo listas de preços
    for (int i = 0; i < n_itens; i++) {
        cin >> lista_precos[i];
    }
    
    quickSort(lista_precos, 0, n_itens - 1);
    
    int x; int y;
    for (int n = 0; n < n_queries; n++) {
        cin >> x >> y;
        int var = n_itens - x;
        int soma = 0;
        for (int m = var; m < y + var; m++) {   // pegando os y menores preços da lista de x maiores preços
            soma += lista_precos[m];
        }
        cout << soma << endl;
    }
    return 0;
}