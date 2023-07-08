#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = (right + left) / 2;

        // Verifica se o elemento está no meio
        if (arr[mid] == target)
            return mid;

        // Se o elemento for maior, ignora a metade esquerda
        if (arr[mid] < target)
            left = mid + 1;

        // Se o elemento for menor, ignora a metade direita
        else
            right = mid - 1;
    }

    // Elemento não encontrado
    return -1;
}

int main() {
    int entradas;
    cin >> entradas;
    int lista[entradas];
    for (int i = 0; i < entradas; i++) {
        cin >> lista[i];
    }
    int target = 23;
    int size = sizeof(lista) / sizeof(lista[0]);

    int result = binarySearch(lista, 0, size - 1, target);
    if (result == -1) {
        cout << "Elemento não encontrado" << endl;
    }
    else {
        cout << "Elemento encontrado na posição: " << result << endl;
    }

    return 0;
}
