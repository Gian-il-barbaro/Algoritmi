#include <stdio.h>
/*
Time Complexity	 
Best	O(n*log n)
Worst	O(n2)
Average	O(n*log n)
Space Complexity	O(log n)
Stability	No
*/

//funzione di scambio di elementi
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//funzione per stampare l'array
void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//funzione di partizione
int partition(int arr[], int leftmost, int rightmost) {
    // Scegliamo l'ultimo elemento come pivot
    int pivot = arr[rightmost];
    // Indice per il posizionamento del pivot
    int index = leftmost;

    for (int i = leftmost; i < rightmost; i++) {
        // Se l'elemento corrente è minore del pivot, scambialo con l'elemento all'indice
        if (arr[i] < pivot) {
            swap(&arr[index], &arr[i]);
            index++;
        }
        // Se l'elemento è maggiore o uguale al pivot, non fare nulla
    }
    //a fine del ciclo, posizioniamo il pivot al suo posto corretto
    swap(&arr[index], &arr[rightmost]);
    // Restituiamo l'indice del pivot
    return index;
}
    
//
void quicksort(int arr[], int leftmost, int rightmost){
    if(leftmost < rightmost){
        // Partizioniamo l'array e otteniamo l'indice del pivot
        int pivot = partition(arr, leftmost, rightmost);
        // Ricorsivamente ordiniamo le due partizioni
        quicksort(arr, leftmost, pivot - 1);
        quicksort(arr, pivot+1, rightmost);
    }

}


int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printarray(arr, size);

    printf("Sorted array: \n");
    quicksort(arr, 0, size - 1);
    printarray(arr, size);
    return 0;
}