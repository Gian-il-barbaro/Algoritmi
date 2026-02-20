package SortingAlgorithms.InsertionSort;
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

public class InsertionSort {
    public static void main(String[] args) {
        int[] arr = {9, 5, 1, 4, 3};
        System.out.println("Original array: ");
        printArray(arr);

        insertionSort(arr);
        System.out.println("Sorted array: ");
        printArray(arr);
    }
    private static void insertionSort(int[] arr) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
    private static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }   
}
