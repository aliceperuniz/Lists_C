#include <iostream>
#include <string.h>
​
using namespace std;
​
int main()
{
    //diferenca da string de c para c++
    char str1[3];//c
    string str2;//c++
    strcpy(str1, "oi");
    str2 = "oi";
    cout<<str1<<endl;
    cout<<str2<<endl;
   
    char teste[] = "guilherme"; //g u i l h e r m e \0 \0 \0 ...
    int i=0;
    while(teste[i] != '\0'){
        cout<<teste[i];
        i++;
    }
    cout<<endl;
    cout<<teste<<endl;
    cout<<endl;
    //sinonimo com inteiros
   
    int numero[3];
    int numero2 = 123;
    numero[0] = 1;
    numero[1] = 2;
    numero[2] = 3;
    for(int i=0; i<3; i++){
        cout<<numero[i];
    }
    cout<<endl;
    cout<<numero2<<endl;
   
    //ponteiros
    cout<<"PONTEIROS"<<endl;
    cout<<endl;
   
    int *p;
    char *p2;
    float *p3;
    X *p4;
    int x = 3;
    p = &x;// p aponta para o index de x
    cout<<(*p)<<endl;//int = %d valor armazenado **
    cout<<p<<endl;//%p index
    x = 4;
    cout<<(*p)<<endl;
   
    //alocação dinamica
    cout<<"ALOCAÇAO DINAMICA"<<endl;
    cout<<endl;
    int *vtr4 = NULL;
    int vtr[5];
    int *vtr2 = (int*)malloc(sizeof(int) * 5);//reserva 5 espaços de inteiros
    vtr2 = (int*)realloc(vtr2 ,sizeof(int) * 6);//realoca os elementos da primeira alocação
    cout<<vtr2[6]<<endl;
    int *vtr3 = (int*)calloc(3, sizeof(int));//aloca espaços preenchendo com 0
    cout<<vtr3[0]<<endl;
    
    free(vtr2);
    free(vtr3);
   
​
    return 0;
}