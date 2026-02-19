package MergeSort;
public class MergeSort {
    public static void main(String[] args) {
        // Esempio di utilizzo del Merge Sort su una lista collegata
        int array[] = {6, 5, 12, 10, 9, 1};
        int size = array.length;
        System.out.println("Array originale:");
        printArray(array);

        // Ordina array
        mergeSort(array, 0, size - 1);

        System.out.println("Array ordinato:");
        printArray(array);
    }

    // Funzione per stampare un array
    public static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    // Funzione principale del Merge Sort
    public static void mergeSort(int[] arr, int p, int r) {
        if (p < r) {
            // Trova il punto medio
            int q = p + (r - p) / 2;

            // Ordina la prima metà
            mergeSort(arr, p, q);
            // Ordina la seconda metà
            mergeSort(arr, q + 1, r);

            // Unisci le due metà ordinate
            merge(arr, p, q, r);
        }
    }

    // Funzione per unire due metà ordinate
    public static void merge(int[] arr, int p, int q, int r) {
        
        // creo L ← A[p..q] e M ← A[q+1..r]
        int n1 = q - p + 1;
        int n2 = r - q;

        // Crea array temporanei
        int[] L = new int[n1];
        int[] R = new int[n2];

        // Copia i dati negli array temporanei
        for (int i = 0; i < n1; i++) {
            L[i] = arr[p + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[q + 1 + j];
        }

        // Unisci gli array temporanei
        int i = 0, j = 0, k = p;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        // Copia gli elementi rimanenti di L[], se ce ne sono
        while (i < n1) {
            arr[k++] = L[i++];
        }

        // Copia gli elementi rimanenti di R[], se ce ne sono
        while (j < n2) {
            arr[k++] = R[j++];
        }
    }
}