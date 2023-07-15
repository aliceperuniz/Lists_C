#include <iostream>

// Definição da estrutura do nó da lista
struct Node {
    int data;
    Node* next;
};

// Função para inserir um elemento no início da lista
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Função para imprimir os elementos da lista
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr; // Inicialmente, a lista está vazia

    // Inserindo elementos na lista
    insertAtBeginning(head, 3);
    insertAtBeginning(head, 2);
    insertAtBeginning(head, 1);

    // Imprimindo os elementos da lista
    printList(head);

    return 0;
}
