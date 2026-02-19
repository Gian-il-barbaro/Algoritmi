/*
 * LinkedList_MergeSort.c
 * Esempio di Merge Sort applicato a una linked list semplicemente concatenata.
 * Contiene funzioni per costruire una lista da un array, stampare, dividere
 * la lista (split), unire due liste ordinate (sortedMerge) e la procedura
 * ricorsiva di merge sort (mergeSort).
 * Complessità temporale: O(n log n) nella maggior parte dei casi.
 */

#include <stdio.h>
#include <stdlib.h>

/* Struttura di un nodo della linked list: contiene un valore intero e
 * il puntatore al nodo successivo. 
 */
struct Node {
    int value;
    struct Node* next;
};

/////////////////////
// Creazione lista //
/////////////////////

/* arrayToList
 * Trasforma un array di interi in una linked list concatenata.
 * Parametri:
 *  - arr: array di input
 *  - size: numero di elementi nell'array
 * Ritorno: puntatore alla testa della lista creata (NULL se size==0)
 * Nota: alloca memoria usando malloc per ogni nodo; il chiamante è
 * responsabile di liberare la memoria se necessario.
 */
struct Node* arrayToList(int arr[], int size) {
    if (size == 0) return NULL; // lista vuota

    struct Node* head = malloc(sizeof(struct Node)); // crea primo nodo
    head->value = arr[0];
    head->next = NULL;

    struct Node* current = head;

    for (int i = 1; i < size; i++) {
        struct Node* node = malloc(sizeof(struct Node)); // nuovo nodo
        node->value = arr[i];
        node->next = NULL;

        current->next = node; // collega al precedente
        current = node;       // avanza il puntatore corrente
    }

    return head;
}

/////////////////////////
// Utility stampa lista//
/////////////////////////

/* printList
 * Stampa in ordine i valori della lista separati da spazio e termina con \n.
 * Parametro: puntatore al primo nodo della lista.
 */

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

/////////////////////////
// Split lista in due  //
/////////////////////////

/* split
 * Divide la lista head in due metà: left e right.
 * Usa il metodo dei due puntatori (slow/fast) per trovare il punto medio.
 * Parametri:
 *  - head: lista da dividere (non deve essere NULL)
 *  - left: output pointer alla prima metà (inizio della lista)
 *  - right: output pointer alla seconda metà (successivo al mid)
 * Dopo la chiamata la lista originale viene spezzata impostando slow->next = NULL.
 */
void split(struct Node* head, struct Node** left, struct Node** right) {

    struct Node* slow = head;            // avanza di 1
    struct Node* fast = head->next;      // avanza di 2

    // Scorri la lista: quando fast raggiunge la fine, slow è al centro
    while (fast != NULL) {
        fast = fast->next;                 // muovi fast di uno
        if (fast != NULL) {
            slow = slow->next;            // muovi slow di uno
            fast = fast->next;            // muovi fast di un altro
        }
    }

    *left = head;           // prima metà inizia dall'inizio
    *right = slow->next;    // seconda metà inizia dopo slow
    slow->next = NULL;      // termina la prima metà
}

/////////////////////////
// Merge di due liste  //
/////////////////////////

/* sortedMerge
 * Unisce due liste ordinate a e b restituendo una lista ordinata risultante.
 * Funziona ricorsivamente scegliendo il nodo con valore minore come testa.
 * Parametri: puntatori alle due liste ordinate (possono essere NULL).
 * Ritorno: puntatore alla testa della lista unita.
 */
struct Node* sortedMerge(struct Node* a, struct Node* b) {

    if (a == NULL) return b; // se una lista è vuota, ritorna l'altra
    if (b == NULL) return a;

    struct Node* result = NULL;

    // Scegli il nodo con valore minore e ricorri per il resto
    if (a->value <= b->value) {
        result = a;
        result->next = sortedMerge(a->next, b); // unisci resto di a con b
    } else {
        result = b;
        result->next = sortedMerge(a, b->next); // unisci a con resto di b
    }

    return result;
}

/////////////////////////
// Merge Sort su lista //
/////////////////////////

/* mergeSort
 * Procedura principale di Merge Sort per linked list. È ricorsiva.
 * Parametro: `headRef` è l'indirizzo del puntatore alla testa della lista.
 * Ragionamento:
 *  - Caso base: lista vuota o con un solo elemento (già ordinata).
 *  - Divisione: split la lista in due metà.
 *  - Conquista: ordina ricorsivamente le due metà.
 *  - Combina: unisci le due metà ordinate con sortedMerge.
 */
void mergeSort(struct Node** headRef) {

    struct Node* head = *headRef;

    // Caso base: nulla da ordinare
    if (head == NULL || head->next == NULL)
        return;

    struct Node* left;
    struct Node* right;

    // Dividi la lista in due metà
    split(head, &left, &right);

    // Ordina entrambe le metà
    mergeSort(&left);
    mergeSort(&right);

    // Unisci le due liste ordinate e aggiorna la testa
    *headRef = sortedMerge(left, right);
}

/////////////////////////
// Main                //
/////////////////////////

int main() {

    int data[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(data) / sizeof(data[0]);

    // Array → Lista
    struct Node* head = arrayToList(data, size);

    printf("Lista originale:\n");
    printList(head);

    // Ordina lista
    mergeSort(&head);

    printf("Lista ordinata:\n");
    printList(head);

    return 0;
}
