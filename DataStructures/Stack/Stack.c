#include <stdio.h>
#include <stdlib.h>
/*
Complessità temporale dello stack
Per l'implementazione di uno stack basato su array, le operazioni di push e pop richiedono tempo costante, cioè O(1).

Applicazioni della struttura dati Stack
Sebbene lo stack sia una struttura dati semplice da implementare, è molto potente. Gli usi più comuni dello stack sono:

Per invertire una parola - Inserisci tutte le lettere in uno stack e poi esegui il pop; grazie all'ordine LIFO otterrai le lettere in ordine inverso.
Nei compilatori - I compilatori usano lo stack per valutare espressioni come 2 + 4 / 5 * (7 - 9) convertendo l'espressione in forma prefissa o postfissa.
Nei browser - Il pulsante "indietro" in un browser salva tutti gli URL visitati precedentemente in uno stack.
            Ogni volta che visiti una nuova pagina, questa viene aggiunta in cima allo stack. Quando premi il pulsante "indietro",
            l'URL corrente viene rimosso dallo stack e viene ripristinato l'URL precedente.
*/
#define MaxSize 10

struct Stack {
    int top;
    int array[MaxSize];
};

void createStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MaxSize - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Errore: stack pieno\n");
        return;
    }
    stack->top++;
    stack->array[stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Errore: stack vuoto\n");
        return -1;
    }
    return stack->array[stack->top--];
}

void printStack(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Lo stack è vuoto\n");
        return;
    }
    printf("Elementi dello stack: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    createStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);
    push(&stack, 70);
    push(&stack, 80);
    push(&stack, 90);
    push(&stack, 100);
    push(&stack, 110);
    push(&stack, 120);
    printStack(&stack);

    printf("Elemento rimosso: %d\n", pop(&stack));
    printf("Elemento rimosso: %d\n", pop(&stack));

    printStack(&stack);

    return 0;
}