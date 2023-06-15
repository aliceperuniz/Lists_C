#include <iostream>
​
using namespace std;//de aluno pra aluno
​
​
​
typedef struct aluno {
    char CPF[15]; //109.269.114-62\0\0\0\0\0 ...
    string nome; //ou char *nome
    string login;
    int idade;
    float altura;
    int cpf[11]; //1 0 9 2 6 9 1 1 4 6 2
    long long int Cpf; //10926911462
} Aluno;
​
int main() {
    int n;
    
    cout << "Digite a quantidade de alunos" << endl;
    cin >> n;
    
    Aluno *alunos;
    alunos = (Aluno *) malloc(sizeof(Aluno) * n);
    cout << "Digite a idade e a altura do aluno 0" << endl;
    cin >> alunos[0].idade >> alunos[0].altura; 
    
    cout << "Diga o nome do aluno" << endl;
    
    cin >> alunos[0].nome;
    
    return 0;
}
​
​