#include <iostream>
using namespace std;

int binarySearch(int lista[], int left, int right, int alvo) {
    if (right >= left) {
        int m = (left + right) / 2;
        if (alvo == lista[m]) {
            return m;
        } else if (alvo < lista[m]) {
            return binarySearch(lista, left, m - 1, alvo);
        } else {
            return binarySearch(lista, m + 1, right, alvo);
        }
    } else{
        return -1;
    }
}

int main() {

    int entradas; int alvo;
    cin >> entradas >> alvo;
    int lista_numeros[entradas];
    for (int i = 0; i < entradas; i++) {
        cin >> lista_numeros[i];
    }
    if (binarySearch(lista_numeros, 0, entradas - 1, alvo) == -1) {
        cout << "O numero " << alvo << " nao foi encontrado na lista.";
    } else {
        cout << "O número foi encontrado";
    }

    return 0;
}
