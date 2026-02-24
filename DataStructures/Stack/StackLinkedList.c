#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
// Variabile globale per il top dello stack
struct Node *top;

//funzione push per inserire un elemento nello stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Errore allocazione memoria\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode; // Aggiorna il top dello stack
    printf("[push] Inserito %d\n", value);
}

int pop() {
    if (top == NULL) {
        printf("Stack vuoto o non creato\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = temp->next;
    free(temp);
    printf("[pop] Estratto %d\n", value);
    return value;
}

void printStack() {
    if (top == NULL) {
        printf("Stack vuoto o non creato\n");
        return;
    }
    struct Node* current = top;
    printf("[printStack] Elementi dello stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printStack();

    pop();
    pop();

    printStack();

    // Pulizia finale
    while (top != NULL) {
        pop();
    }

    return 0;
}