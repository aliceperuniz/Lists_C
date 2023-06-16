#include <iostream>
using namespace std;

// Função auxiliar para trocar dois elementos de posição
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Função que escolhe o último elemento como pivô,
// coloca o pivô em sua posição correta no array
// e posiciona todos os elementos menores que o pivô à sua esquerda
// e todos os elementos maiores que o pivô à sua direita
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // escolhe o último elemento como pivô
    int i = (low - 1); // índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] >= pivot) {
            i++; // incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal que implementa o Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi é o índice de partição, arr[p] agora está no lugar correto
        int pi = partition(arr, low, high);

        // Ordena os elementos separadamente antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função auxiliar para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Exemplo de uso
int main() {
    
    int n_casos;
    int tamanho_array;
    cin >> n_casos;

    for (int n=0; n<n_casos; n++) {
        cin >> tamanho_array; 
        int array[tamanho_array];
        for (int r=0; r<tamanho_array; r++) {
            cin >> array[r];  // formando a array inicial (sem estar ordenada)
        }

        quickSort(array, 0, tamanho_array-1);
        for(int o=0; o<tamanho_array; o++) {
            cout << array[o] << ", ";
        }
    }

    return 0;
}
