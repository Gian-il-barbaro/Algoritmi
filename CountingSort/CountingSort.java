package CountingSort;

public class CountingSort {

    public static void main(String[] args) {
        int[] arr = {9, 5, 1, 4, 3};

        System.out.println("Original array: ");
        printArray(arr);
        System.out.println("Sorted array: ");
        int[] sorted = cs(arr);
        printArray(sorted);
    }

    private static int[] cs(int[] arr) {

        int max = findMax(arr);

        // Array di conteggio
        int[] count = new int[max + 1];

        // Conta le occorrenze
        for (int i = 0; i < arr.length; i++) {
            count[arr[i]]++;
        }

        // Prefix sum
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        // Array risultato
        int[] output = new int[arr.length];

        // Riempimento output (da destra per stabilità)
        for (int i = 0; i < arr.length; i++) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }

        return output;
    }

    private static int findMax(int[] arr) {
        int max = arr[0];
        for (int num : arr) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    private static void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}