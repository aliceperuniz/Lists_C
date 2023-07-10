#include <iostream>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int HoarePartition(int array[], int low, int high){
    int pivo = array[low];
    int i = low;
    int j = high + 1;
    do{
        do{
            i++;
        } while(!(array[i] >= pivo || i >= high));
        do{
            j--;
        }while(!(array[j] <= pivo));
        swap(array[i], array[j]);
    } while(!(i >= j));
    swap(array[i], array[j]);
    swap(array[low], array[j]);
    return j;
}

void quickSort(int array[], int low, int high){
    if (low < high){
        int s = HoarePartition(array, low, high);
        quickSort(array, low, s - 1);
        quickSort(array, s + 1, high);
    }
}

void binarySearchPair(int lista[], int left, int right, int cursor, int diferenca, int resposta, bool continua) {
    while ((right >= left) && (continua == true)) {
        int m = (left + right) / 2;
        if (lista[cursor] - lista[m] == diferenca) {
            resposta += 1; continua = false;
        } else if (lista[cursor] - lista[m] < diferenca) {
            right = m - 1;
        } else {
            left = m + 1;
        }
    } 
    
}

int main() {

    int entradas; int diferenca; int resposta = 0; bool continua = true;
    cin >> entradas >> diferenca;
    int lista_numeros[entradas];
    for (int i = 0; i < entradas; i++) {
        cin >> lista_numeros[i];
    }
    quickSort(lista_numeros, 0, entradas - 1);
    int j = entradas - 1;
    for (int n = 0; n > entradas - 1; n++) {
        binarySearchPair(lista_numeros, 0, j, j, diferenca, resposta, continua);
        j -= 1;
    }
    cout << resposta;

    return 0;
}
