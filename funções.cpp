#include <iostream>
​
using namespace std;
​
void count1(int cont, int *cont2, int *v) { //lembrando que as variáveis não precisam ter o mesmo nome que na main
    v = (int *) malloc(sizeof(int) * 5);
    for(int i = 0; i < 8; i++) {
        cont++;
        (*cont2)++;
    }
}
​
int count2(int cont) {
    for(int i = 0; i < 5; i++) {
        cont++;
    }
    return cont;
} 
​
int *vetor(int *vet) {
    vet = (int *) malloc(sizeof(int) * 5);
    for(int i = 0; i < 5; i++) {
        vet[i] = i;
    }
    
    return vet;
}
​
void Vetor2(int *&vet) { //Passando o vetor dessa forma, ele será salvo na main sem precisar retorná-lo
    vet = (int *) malloc(sizeof(int) * 5);
    vet[3] = 7; 
}
​
int main() {
    int contador, contador2;
    contador = 0;
    contador2 = 2;
    
    int *V; //vetor
    int *auxiliar; //vetor auxiliar
    
    count1(contador, &contador2, V);  //o vetor V alocado só pode ser usado dentro da função 
                                      //Para que as alterações no vetor sejam salvas , uma boa forma é retorná-lo 
                                      //e salvar em um outro vetor
                                      
    auxiliar = vetor(V); //Em auxiliar, será atribuído vet
    
     for(int i = 0; i < 5; i++) {
        cout << auxiliar[i] << " ";
    }
    
    cout << endl;
    
    Vetor2(V); //Aqui V é modificado na função e as alterações feitas serão salvas na main
    
    cout << V[3] << endl;
    
    cout << contador << endl;
    cout << contador2 << endl;
    
    int resposta_cont;
    
    resposta_cont = count2(contador);
    
    cout << contador << endl;
    
    cout << resposta_cont << endl;
​
    return 0;
}
​