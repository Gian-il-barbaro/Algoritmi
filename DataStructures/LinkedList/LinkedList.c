#include <stdio.h>
#include <stdlib.h>

// Crea un nodo
struct Node {
  int data;
  struct Node* next;
};

struct Node *head = NULL; // Variabile globale per il nodo head della lista

// Inserisci all'inizio della lista
void insertAtBeginning(int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

  new_node->data = new_data;
  new_node->next = head;
  // Move head to new node
  head = new_node;
}

// Insert a node after a node
void insertAfterValue(int key, int new_data) {
    struct Node* current = head;

    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) return;  // valore non trovato

    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = new_data;
    
    //new_node si prende il next del nodo corrente
    new_node->next = current->next;
    //current punta a new_node
    current->next = new_node;
}

// Inserisci alla fine della lista
void insertAtEnd(int new_data) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  struct Node* last = head; // serve per scorrere la lista fino alla fine

  new_node->data = new_data;
  new_node->next = NULL;

  if (head == NULL) {
  head = new_node;
  return;
  }
  // Scorri fino alla fine della lista
  while (last->next != NULL) last = last->next;

  last->next = new_node;
  return;
}

// elimina un nodo
void deleteNode(int key) {
  struct Node *temp = head, *prev;  // temp = primo nodo, prev = non inizializzato
  
  // Se il primo nodo è quello da eliminare
  if (temp != NULL && temp->data == key) {
    head = temp->next;  // head punta al secondo
    free(temp);
    return;
  }
  
  // Altrimenti scorri la lista
  while (temp != NULL && temp->data != key) {
    prev = temp;      // prev ricorda il nodo precedente
    temp = temp->next; // temp avanza al prossimo
  }
  
  // Quando trovi il nodo da eliminare
  prev->next = temp->next;  // salta il nodo eliminato
  free(temp);
}

// cerca un nodo
int searchNode(int key) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) return 1;
            current = current->next;    
        }
    return 0;
}

// sort della lista
void sortLinkedList() {
    struct Node *current = head, *index = NULL;
    int temp;

    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
        // index è usato per scorrere i nodi dopo current
        index = current->next;

        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
        }
    }
}

// stampa della lista
void printList() {
  struct Node* node = head;
  while (node != NULL) {
  printf(" %d ", node->data);
  node = node->next;
  }
}


int main() {
  insertAtEnd(1);
  insertAtBeginning(2);
  insertAtBeginning(3);
  insertAtEnd(4);
  insertAfterValue(2, 5);  

  printf("Linked list: ");
  printList();

  printf("\nAfter deleting an element: ");
  deleteNode(3);
  printList();

  int item_to_find = 3;
  if (searchNode(item_to_find)) {
  printf("\n%d is found", item_to_find);
  } else {
  printf("\n%d is not found", item_to_find);
  }

  sortLinkedList();
  printf("\nSorted List: ");
  printList();
}