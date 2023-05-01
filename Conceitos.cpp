/*
#include <iostream>

using namespace std;

int main(){

    Criando array dinâmica:
      data_type_array *name_array;
      name_array = new data_type_array[number_of_elements];
      nome_array[0] = value;
      delete [] name_array; //(apaga toda a array)
    

} 
*/

/* gpt: (LISTAS)
#include <iostream>

// Define a estrutura dos nós da lista
struct Node {
    int data;
    Node* next;
};

// Insere um elemento no início da lista
void insert(Node** head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Remove um elemento da lista
void remove(Node** head, int value) {
    if (*head == nullptr) return;

    if ((*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }

    Node* current = *head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

// Imprime os elementos da lista
void print(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    print(head);

    remove(&head, 10);
    print(head);

    return 0;
}


LISTAS DENTRO DE LISTA:

#include <iostream>

// Define a estrutura dos nós da lista interna
struct InnerNode {
    int data;
    InnerNode* next;
};

// Define a estrutura dos nós da lista externa
struct OuterNode {
    InnerNode* innerHead;
    OuterNode* next;
};

// Insere um elemento na lista interna
void insertInner(InnerNode** head, int value) {
    InnerNode* newNode = new InnerNode;
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insere um elemento na lista externa
void insertOuter(OuterNode** head, int value) {
    OuterNode* newNode = new OuterNode;
    newNode->innerHead = nullptr;
    newNode->next = *head;
    *head = newNode;

    insertInner(&((*head)->innerHead), value);
}

// Remove um elemento da lista interna
void removeInner(InnerNode** head, int value) {
    if (*head == nullptr) return;

    if ((*head)->data == value) {
        InnerNode* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }

    InnerNode* current = *head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next != nullptr) {
        InnerNode* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

// Remove um elemento da lista externa
void removeOuter(OuterNode** head, int value) {
    if (*head == nullptr) return;

    if ((*head)->innerHead != nullptr && (*head)->innerHead->data == value) {
        InnerNode* temp = (*head)->innerHead;
        (*head)->innerHead = (*head)->innerHead->next;
        delete temp;
        if ((*head)->innerHead == nullptr) {
            OuterNode* temp2 = *head;
            *head = (*head)->next;
            delete temp2;
        }
        return;
    }

    OuterNode* current = *head;
    while (current->next != nullptr && (current->next->innerHead == nullptr || current->next->innerHead->data != value)) {
        current = current->next;
    }

    if (current->next != nullptr) {
        InnerNode* temp = current->next->innerHead;
        current->next->innerHead = current->next->innerHead->next;
        delete temp;
        if (current->next->innerHead == nullptr) {
            OuterNode* temp2 = current->next;
            current->next = temp2->next;
            delete temp2;
        }
    }
}

// Imprime os elementos da lista interna
void printInner(InnerNode* head) {
    InnerNode* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

// Imprime os elementos da lista externa
void printOuter(OuterNode* head) {
    OuterNode* current = head;
    while (current != nullptr) {
        std::cout << "[";
        printInner(current->innerHead);
        std::cout << "]";
       


*/;
