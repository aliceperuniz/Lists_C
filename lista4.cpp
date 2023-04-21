
#include <iostream>

using namespace std;

#define MAX (100^4)/2
 

int pai[MAX];

int find(int x){
	
	if(pai[x]==x) return x;
	return find(pai[x]);
}
 
void unite(int x, int y){
	
	pai[find(x)]=find(y);
}

void localizacao(int parede, int linha, int numero, int tamanho_labirinto, int n, bool direita, bool abaixo){
    if(linha%2 != 0){
        numero += tamanho_labirinto;
        linha += 1;
        direita = false; abaixo = true;
    } else{
        numero += (tamanho_labirinto-1);
        linha += 1;
        abaixo = false; direita = true;
    }
    if(parede > numero){
        localizacao(parede, linha, numero, tamanho_labirinto, n, direita, abaixo);
    } else{
        int x = numero; while(x != parede){
            n += 1;
            x -= 1;
        }
        int celula1; int celula2;
        if ((direita == true)&&(abaixo == false)){
            celula1 = tamanho_labirinto*(((linha-1)/2)+1) - n-1; celula2 = celula1 - 1;
            unite(celula1, celula2);
        } else if((abaixo == true) && (direita == false)){
            celula1 = (linha/2)*tamanho_labirinto - n - 1; celula2 = celula1 + tamanho_labirinto;
            unite(celula1, celula2);
        }
    }
    
};

int main() { // j, k, o, i, s, n, g
    
    int n_labirintos; // K
    int tamanho_labirinto; // N
    int n_paredes_removidas; // M
    int n_celulas_consultadas; // Q
    int paredes_direita[tamanho_labirinto^2 - tamanho_labirinto];
    int paredes_abaixo[tamanho_labirinto^2 - tamanho_labirinto];
    
    cin >> n_labirintos ;
    int lista_print[n_celulas_consultadas*n_labirintos*3];
    for (int i = 0; i < n_labirintos; i++){

        cin >> tamanho_labirinto;
        for (int o = 0; o < tamanho_labirinto; o++){
            pai[o] = o;
        }

        cin >> n_paredes_removidas;
        cin >> n_celulas_consultadas;
        int parede_removida;
        for (int k = 0; k < n_paredes_removidas; k++){
            cin >> parede_removida;
            
        }
        int celula_1; int celula_2;
        int s=0;
        for (int j = 0; j < n_celulas_consultadas; j++){
            cin >> celula_1; cin >> celula_2;
            int y; if(pai[celula_1] == pai[celula_2]){
                y = 1;
            } else{y = 0;}
            lista_print[s] = i; lista_print[s+1] = i; lista_print[s+2] = i;
            s+=3;
        }

    };
    int g=0;
    for (int n = 0; n < n_celulas_consultadas; n++){
        cout << lista_print[g] << "." << lista_print[g+1], lista_print[g+2]; // << endl;
        g+=3;
    }

}
