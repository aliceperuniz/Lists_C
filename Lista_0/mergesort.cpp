#include <iostream>
using namespace std;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if (size < 2)
        return;

    int meio = size / 2;
    int left[meio];
    int right[size - meio];

    for (int i = 0; i < meio; i++)
        left[i] = arr[i];
    for (int i = meio; i < size; i++)
        right[i - meio] = arr[i];

    mergeSort(left, meio);
    mergeSort(right, size - meio);

    merge(arr, left, meio, right, size - meio);
}

int main() {
    int tamanho;
    cin >> tamanho;
    int arr[tamanho] = {0};
    int numero;
    for(int n = 0; n < tamanho; n++) {
        cin >> numero;
        arr[n] = numero;
    }
    int size = tamanho;

    mergeSort(arr, size);

    cout << "Array ordenado: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
