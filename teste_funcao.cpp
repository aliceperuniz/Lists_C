#include <iostream>

using namespace std;

/* void localizacao(int parede, int linha, int numero, int tamanho_labirinto, int n, bool direita, bool abaixo){
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
    }
}; */

int main(){
    int parede;
    int tamanho;
    int unite[2];
    int linha = 1;
    int n = 0;
    bool direita = false;
    bool abaixo = false;
    int coluna;
    cin >> tamanho;
    cin >> parede;
    int numero = tamanho - 2;
    if (parede <= numero){
        direita = true;
        linha = 1;
        unite [0] = parede; unite[1] = parede + 1;
    } else{
        //cout << "entrou na merda da função";
        //localizacao(parede, linha, numero, tamanho, n, direita, abaixo);
        while(parede > numero){
            if(linha%2 != 0){
                numero += tamanho;
                linha += 1;
                direita = false; abaixo = true;
            } else{
                numero += (tamanho-1);
                linha += 1;
                abaixo = false; direita = true;
            }
            int x = numero; while(x != parede){
            n += 1;
            x -= 1;
        }
        }
        if (direita == true){
            coluna = tamanho - n - 1;
            unite[0] = tamanho*(((linha-1)/2)+1) - n-1; unite[1] = unite[0] - 1;
            cout << "direita true";
        } else if(abaixo == true){
            unite[0] = (linha/2)*tamanho - n - 1; unite[1] = unite[0] + tamanho;
        }
    }
    
    cout << "linha: " << linha << " coluna: " << coluna << endl;
    cout << "as celulas sao: " << unite[0] << " e " << unite[1];

}
