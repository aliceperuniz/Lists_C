/* Funções que talvez sejam usadas no futuro :
struct No{
    int valor;
    No* next;
};

struct bst{
    int valor;
    bst* left;
    bst* right;
};

struct lista{
    No* front;
    No* rear;
};

void find_element(No* head, int v){
    No *cur = head;
    while (cur ->next != NULL || cur ->next ->valor != v){
        cur = cur ->next;
    }
    return cur;
};

void get_element(struct No* head){
    No *cur = head;
    int n;
    for(n = 0; n<pos; n++){
        cur = cur->next;
    }
    return cur;
};

void insert_element(struct No cur, int v){
    No* temp = new No();
    temp ->valor = v;
    temp ->next = cur ->next;

} 
*/