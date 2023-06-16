#include <iostream>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

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
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, 0, size - 1, target);
    if (result == -1)
        std::cout << "Elemento não encontrado" << std::endl;
    else
        std::cout << "Elemento encontrado na posição: " << result << std::endl;

    return 0;
}
