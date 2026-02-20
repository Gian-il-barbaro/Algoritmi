#include <stdio.h>

/*
Time Complexity	 
Best	O(n+max)
Worst	O(n+max)
Average	O(n+max)
Space Complexity	O(max)
Stability	Yes
*/

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findmax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int size) {
    int max = findmax(arr, size);
    //inizializzo il secondo array con tutti i valori a 0
    int arr2[max + 1];
    for (int i = 0; i <= max; i++) {
        arr2[i] = 0;
    }
    //conta le occorrenze di ogni elemento
    for (int i = 0; i < size; i++)
    {
        arr2[arr[i]]++;
    }

    //somma cumulativa
    for (int i = 1; i <= max; i++)
    {
        arr2[i] = arr2[i]  + arr2[i - 1];
    }

    //creazione dell'array ordinato
    int result[size];
    for (int i = 0; i < size; i++) {
        result[arr2[arr[i]] - 1] = arr[i];
        arr2[arr[i]]--;
    }

    // copia dell'array ordinato nell'array originale
    for (int i = 0; i < size; i++) {
        arr[i] = result[i];
    }
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Troviamo il valore massimo nell'array
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Array prima dell'ordinamento: ");
    printarray(arr, size);
    countingSort(arr, size);
    printf("Array dopo l'ordinamento: ");
    printarray(arr, size);
}