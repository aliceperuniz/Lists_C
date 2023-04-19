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

int main() {
    
    int n_labirintos; // K
    int tamanho_labirinto; // N
    int n_paredes_removidas; // M
    int n_celulas_consultadas; // Q
    int lista_paredes[2*((tamanho_labirinto^2) - tamanho_labirinto)-1];
    int i; int n; int k; int j;
    for (n = 0; n < 2*((tamanho_labirinto^2) - tamanho_labirinto); n++){
        lista_paredes[n] = n;
    }
    cin >> n_labirintos ;
    for (i = 0; i < n_labirintos; i++){
        cin >> tamanho_labirinto;
        cin >> n_paredes_removidas;
        cin >> n_celulas_consultadas;
        int parede_removida;
        for (k = 0; k < n_paredes_removidas; k++){
            cin >> parede_removida;
            lista_paredes[parede_removida] = -1;
        }
        int celula_1; int celula_2;
        for (j = 0; j < n_celulas_consultadas; j++){
            cin >> celula_1; cin >> celula_2;
            
        }
        
    };

}
