#include <stdio.h>
/*
Quando si usa il merge sort:
problemi di di conteggio inverso


Time Complexity	 
Best	O(n*log n)
Worst	O(n*log n)
Average	O(n*log n)
Space Complexity	O(n)
Stability	Yes
*/
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // creo L ← A[p..q] e M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  //copio i dati negli array temporanei L[] e M[]
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // indici iniziali di primo e secondo sottovettore e dell'array originale
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // finche non arrivo alla fine di uno dei due array
  while (i < n1 && j < n2) {
    //se l'elemento corrente di L è minore o uguale a quello di M, lo inserisco nell'array originale
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else { //inserisco laltro altrimenti
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // prendo i restanti elementi di L, se ce ne sono
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  // prendo i restanti elementi di M, se ce ne sono
  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergesort(int array[], int start_index, int end_index) {
    if(start_index < end_index) {
        // trova il punto di divisione dell'array in due metà
        int middle_index = start_index + (end_index - start_index) / 2;
        
        mergesort(array, start_index, middle_index);
        mergesort(array, middle_index + 1, end_index);

        merge(array, start_index, middle_index, end_index);
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
  int data[] = {6, 5, 12, 10, 9, 1};
  
  // trovare la dimensione dell'array
  int size = sizeof(data) / sizeof(data[0]);

  mergesort(data, 0, size - 1);
  
  printf("Array ordinato in ordine crescente:\n");
  printArray(data, size);
}