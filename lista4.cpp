#include <iostream>

using namespace std;

#define MAX (100^4)/2
 

int pai[MAX], peso[MAX];

int find(int x){
	
	if(pai[x]==x) return x;
	return find(pai[x]);
}
 
void unite(int x, int y){
	
	pai[find(x)]=find(y);
}

void mesma_parede(int x, int y){

}

int main() {
    
    int n_labirintos; // K
    int tamanho_labirinto; // N
    int n_paredes_removidas; // M
    int n_celulas_consultadas; // Q
    int paredes_direita[tamanho_labirinto^2 - tamanho_labirinto];
    int paredes_abaixo[tamanho_labirinto^2 - tamanho_labirinto];
    int g=0; int k; int j; int x=0; int nivel = 0; int n_2=0; int b = 2*(tamanho_labirinto^2-tamanho_labirinto)-1;
    for (int m = 0; m < tamanho_labirinto^2; m++){
        pai[m] = m; 
    }
    for (int n = 0; n < 2*(tamanho_labirinto^2 - tamanho_labirinto); n++){
        if(x < n){
            paredes_direita[n_2] = n;
            x += 1;
            n_2 += 1;
        } else{
            paredes_abaixo[g] = n;
            g+=1;
            nivel += 1;
            if (nivel == tamanho_labirinto){
                x = 0;
            }
        }
    }
    cin >> n_labirintos ;
    for (int i = 0; i < n_labirintos; i++){
        cin >> tamanho_labirinto;
        cin >> n_paredes_removidas;
        cin >> n_celulas_consultadas;
        int parede_removida;
        for (int k = 0; k < n_paredes_removidas; k++){
            cin >> parede_removida;
            int cursor = tamanho_labirinto-2;
            while(b>=0){
                if (parede_removida == b){
                    bool direita = false; bool abaixo = false;
                    for (int c = 0; c < sizeof(paredes_direita); c++) {
                        if (paredes_direita[c] == parede_removida) {
                          direita = true; paredes_direita[c] = -1;      //
                          unite(tamanho_labirinto-1, tamanho_labirinto-2);
                        } else if (paredes_abaixo[c] == parede_removida){
                            abaixo = true;
                        }
                    }
                } else{
                    b-=1;
                }
            }
        }
        int celula_1; int celula_2;
        for (int j = 0; j < n_celulas_consultadas; j++){
            cin >> celula_1; cin >> celula_2;
            
        }
        
    };
cout << pai;
}
