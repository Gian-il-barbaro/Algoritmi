/*
Quando viene utilizzato il bubble sort:
La complessità non viene tenuta conto
semplice e velocemente da implementare

Time Complexity	 
Best	O(n)
Worst	O(n2)
Average	O(n2)
Space Complexity	O(1)
Stability	Yes
*/

#include <stdio.h>

// perform the bubble sort
void bubbleSort(int array[], int size) {

  // loop per accedere ad ogni elemento dell'array
  for (int j = 0; j < size - 1; ++j) {
      
    // loop per confrontare gli elementi dell'array
    for (int i = 0; i < size - j - 1; ++i) {
      
      // comparare l'elemento corrente con il successivo
      if (array[i] > array[i + 1]) {
        
        // scambiare l'elemento corrente con il successivo
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int data[] = {-2, 45, 0, 11, -9};
  
  // trovare la dimensione dell'array
  int size = sizeof(data) / sizeof(data[0]);

  bubbleSort(data, size);
  
  printf("Array ordinato in ordine crescente:\n");
  printArray(data, size);
}