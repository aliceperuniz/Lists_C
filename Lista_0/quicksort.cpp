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
        } while(!(array[i] >= pivo || i >= r));
        do{
            j--;
        }while(!(array[j] <= pivo));
        swap(array[i], array[j]);
    } while(!(i >= j));
    swap(array[i], array[j]);
    swap(array[low], array[j]);
    return j;
}

void quicksort(int array[], int low, int high){
    if (low < high){
        int s = HoarePartition(array, low, high);
        quicksort(array, low, s - 1);
        quicksort(array, s + 1, high);
    }
}