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
        int nova_lista[x];
        int temporario = n_itens - 1; // última posição da lista de preços;
        for (int m = 0; m < x; m++) {  // pegando os x maiores preços da lista de preços
            nova_lista[m] = lista_precos[temporario];
            temporario -= 1;
        }
        int soma = 0;
        temporario = x - 1; // última posição da nova lista;
        for (int o = 0; o < y; o++) {   // pegando os y menores preços da lista de x maiores preços
            soma += nova_lista[temporario];
            temporario -= 1;
        }
        cout << soma << endl;
    }
    return 0;
}