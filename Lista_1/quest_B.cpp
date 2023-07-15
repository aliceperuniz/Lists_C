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

int binarySearchPairs(int lista[], int size, int diff) {

    int count = 0;
    int left = 0;
    int right = 1;

    while (right < size) {
        int currentDiff = lista[right] - lista[left];

        if (currentDiff == diff) {
            count++;
            left++;
            right++;
        } else if (currentDiff < diff) {
            right++;
        } else {
            left++;
        }

        if (left == right) {
            right++;
        }
    }

    return count;
}

int main() {
    
    int entradas; int diferenca; int resposta = 0;
    cin >> entradas >> diferenca;
    int lista_numeros[entradas];
    for (int i = 0; i < entradas; i++) {
        cin >> lista_numeros[i];
    }
    quickSort(lista_numeros, 0, entradas - 1);
    resposta = binarySearchPairs(lista_numeros, entradas, diferenca);
    cout << resposta;

    return 0;
}
