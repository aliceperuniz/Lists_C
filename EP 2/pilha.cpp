#include <iostream>

using namespace std;

struct Stack {
    int size; 
    Stack* top; // ponteiro para o nó do topo
};

void create_stack() {
    Stack* newStack = Stack();
    newStack -> top = nullptr;
    newStack -> size = 0;
}

void push(Stack x, int element) {
    Stack* newStack = new Stack(); // cria um novo nó
    newStack->data = element; // define o dado do nó como o elemento a ser inserido
    newStack->next = top; // o próximo nó do novo nó será o nó que atualmente está no topo
    top = newStack; // atualiza o topo para apontar para o novo nó
}

void pop() {
    if (isEmpty()) {
        cout << "Erro: a pilha está vazia." << endl;
    } else {
        Stack* temp = top; // armazena o nó atual do topo em um nó temporário
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
