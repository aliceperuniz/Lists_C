#include <iostream>

using namespace std;

struct No{
    int valor;
    No* next;
};

struct lista{
    No* head; //ponteiro do tipo "nó"
    No* tale;
};

void iniciar_lista(lista &Lista){
    No* head = NULL;
    No* tale = NULL;
};

void inserir_elemento(No* cur, int v){
    No* temp = new No();
    temp ->valor = v;
    temp ->next = cur ->next;

};

int main(){

    int n_jog;
    string entrada;
    cin >> n_jog;
    // criando array dinâmica:
    lista *lista_jog;
    lista_jog = new lista[n_jog];

    int n;
    for(n=0; n<n_jog; n++){
        iniciar_lista(lista_jog[n]);
    }

    while (entrada != "END"){
        cin >> entrada;
        if (entrada == "DEA"){
            int i = 0;
            for(i=0; i<n_jog; i++){
                string carta;
                cin >> carta;
                // adicionar carta à lista do jog[i]
            }
        } else if(entrada == "PRT"){
            int num_jog;
            cin >> num_jog ;
            cout << ""/*lista de cartas do jogador[num_jog]*/;
        }
    }

    return 0;
}
