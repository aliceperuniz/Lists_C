
#include <iostream>
using namespace std;

#define MAX (100^4)/2

int pai[MAX];
int altura[MAX];

void make_set(int n) {
    for (int i = 0; i < n; i++) {
        pai[i] = i;
        altura[i] = 0;
    }
}

int find(int x){
	
	if(pai[x]==x) return x;
	return find(pai[x]);
}
 
void unite(int x, int y){

    int px = find(x);
    int py = find(y);
    if (altura[px] < altura[py]) {
        pai[px] = py;
        altura[py] += altura[px];
    } else if (altura[px] >= altura[py]) {
        pai[py] = px;
        altura[px] += altura[py];
    } else {
        pai[py] = px;
        altura[px] += altura[py];
    }
}

int main() { 
    
    int n_labirintos; // K
    int tamanho_labirinto; // N
    int n_paredes_removidas; // M
    int n_celulas_consultadas; // Q
    
    cin >> n_labirintos ;
    for (int o = 0; o < n_labirintos; o++){ // para rodar em cada lab:

        cin >> tamanho_labirinto;
        make_set(tamanho_labirinto*tamanho_labirinto);

        cin >> n_paredes_removidas;
        cin >> n_celulas_consultadas;
        int parede_removida;
        for (int k = 0; k < n_paredes_removidas; k++){
            cin >> parede_removida;
            int numero = tamanho_labirinto - 2;
            int linha = 0;
            if (parede_removida <= numero){
                if (find(parede_removida) != find(parede_removida+1)){
                    unite(parede_removida, (parede_removida + 1));
                }
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
                    if (find(x) != find(x-1)){
                        unite(x, x-1);
                    }
                } else{
                    int temp2 = numero - tamanho_labirinto-1; int local2 = 0;
                    while (temp2 != parede_removida){
                        local2 += 1; temp2 += 1;
                    }
                    int u; u = (tamanho_labirinto * ((linha-1)/2)) + local2 - 1;
                    if (find(u) != find(u+tamanho_labirinto)){
                        unite(u + tamanho_labirinto, u);
                    }
                }
            }
        }
        int celula_1; int celula_2;
        // verificando as células consultadas e printando "L.Q Y"
        for (int j = 0; j < n_celulas_consultadas; j++){
            cin >> celula_1; cin >> celula_2;
            int y; 
            if(find(celula_1) == find(celula_2)){
                y = 1;
            } else{
                y = 0;
            };
            cout << o << "." << j << " " << y << endl;
        }
    };
}
