#include <iostream>

using namespace std;

struct Node {
    int size; 
    Node* next; // ponteiro para o nó do topo
};

//Node* top = nullptr; // ponteiro para o topo da pilha

bool isEmpty() {
    return top == nullptr; // retorna true se a pilha estiver vazia, false caso contrário
}

void push(int element) {
    Node* newNode = new Node(); // cria um novo nó
    newNode->data = element; // define o dado do nó como o elemento a ser inserido
    newNode->next = top; // o próximo nó do novo nó será o nó que atualmente está no topo
    top = newNode; // atualiza o topo para apontar para o novo nó
}

void pop() {
    if (isEmpty()) {
        cout << "Erro: a pilha está vazia." << endl;
    } else {
        Node* temp = top; // armazena o nó atual do topo em um nó temporário
        top = top->next; // atualiza o topo para apontar para o próximo nó
        delete temp; // libera a memória do nó removido
    }
}

int topElement() {
    if (isEmpty()) {
        cout << "Erro: a pilha está vazia." << endl;
        return -1;
    } else {
        return top->data; // retorna o dado do nó no topo da pilha
    }
}

int main() {
    push(1);
    push(2);
    push(3);

    cout << "Topo da pilha: " << topElement() << endl;

    pop();

    cout << "Topo da pilha após pop: " << topElement() << endl;

    return 0;
}
