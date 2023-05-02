
#include <iostream>
using namespace std;

#define MAX (100^4)/2

int pai[MAX];

int find(int x){
	
	if(pai[x]==x) return x;
	return find(pai[x]);
}
 
void unite(int x, int y){
    cout << "unite " << x << y << endl;
	pai[find(x)]=find(y);
}

int main() { // j, k, o, i, s, n, g
    
    int n_labirintos; // K
    int tamanho_labirinto; // N
    int n_paredes_removidas; // M
    int n_celulas_consultadas; // Q
    
    cin >> n_labirintos ;
    for (int i = 0; i < n_labirintos; i++){ // para rodar em cada lab:

        cin >> tamanho_labirinto;
        //colocando cada célula para ser pai de si mesma (make_set):
        for (int o = 0; o < tamanho_labirinto*tamanho_labirinto; o++){
            pai[o] = o;
        }

        cin >> n_paredes_removidas;
        cin >> n_celulas_consultadas;
        int parede_removida;
        for (int k = 0; k < n_paredes_removidas; k++){
            cin >> parede_removida;
            int numero = tamanho_labirinto - 2;
            int linha = 0;
            if (parede_removida <= numero){
                unite(parede_removida, (parede_removida + 1));
            } else{
                while (numero < parede_removida) // verificando em qual linha a parede removida se encontra:
                {
                    linha += 1;
                    if (linha%2 == 0){ // se linha = par:
                        numero += tamanho_labirinto;
                    } else { // se for ímpar
                        numero += (tamanho_labirinto - 1);
                    }
                }
                // vendo qual parede da linha foi removida:
                if (linha%2 == 0){
                    int temp = numero - tamanho_labirinto; int local = 0;
                    while (temp != parede_removida){
                        local += 1; temp += 1;
                    }
                    int x = (tamanho_labirinto * (linha/2) + local)-1;
                    unite(x, x-1);
                } else{
                    int temp2 = numero - tamanho_labirinto-1; int local2 = 0;
                    while (temp2 != parede_removida){
                        local2 += 1; temp2 += 1;
                    }
                    int u; u = (tamanho_labirinto * ((linha-1)/2)) + local2 - 1;
                    unite(u + tamanho_labirinto, u);
                }
            }
        }
        int celula_1; int celula_2;
        // verificando as células consultadas e printando "L.Q Y"
        for (int j = 0; j < n_celulas_consultadas; j++){
            cin >> celula_1; cin >> celula_2;
            int y; 
            if(pai[celula_1] == pai[celula_2]){
                y = 1;
            } else{
                y = 0;
            };
            cout <<"pais das cells " << pai[celula_1] << pai[celula_2] << endl;
            cout << i << "." << j << " " << y << endl;
        }
    };
}
