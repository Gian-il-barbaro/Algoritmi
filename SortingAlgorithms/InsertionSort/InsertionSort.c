#include <stdio.h>
/*
L'insertion sort viene utilizzato quando:

l'array ha un piccolo numero di elementi
ci sono solo pochi elementi rimasti da ordinare

Best	O(n)
Worst	O(n2)
Average	O(n2)
Space Complexity	O(1)
Stability	Yes
*/
void insertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;

    // sposta gli elementi di array[0..i-1], che sono maggiori di key, a una posizione avanti rispetto alla loro posizione attuale
    while (j >=0 && key < array[j]) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {9, 5, 1, 4, 3};
    printf("Original array: \n");
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);
    printf("Sorted array: \n");
    printArray(arr, size);
    return 0;
}


