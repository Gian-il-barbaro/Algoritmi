package QuickSort;

/*
Time Complexity	 
Best	O(n*log n)
Worst	O(n2)
Average	O(n*log n)
Space Complexity	O(log n)
Stability	No
*/


public class QuickSort{

    public static void main(String[] args) {
        int[] arr = {9, 5, 1, 4, 3};
        int n = arr.length;

        QuickSort quickSort = new QuickSort();
        quickSort.quickSort(arr, 0, n - 1);

        System.out.println("Sorted array: ");
        quickSort.printArray(arr);
    }

    private void quickSort(int[] arr, int leftmost, int rightmost) {
        if (leftmost < rightmost) {
            int pivot = partition(arr, leftmost, rightmost);

            quickSort(arr, leftmost, pivot - 1);
            quickSort(arr, pivot + 1, rightmost);
        }

    }
    private int partition(int[] arr, int leftmost, int rightmost){
        int pivot = arr[rightmost];
        int index = leftmost;

        for (int i = leftmost; i < rightmost; i++) {
            if (arr[i] < pivot) {
                swap(arr, index, i);
                index++;
            }
        }
        swap(arr, index, rightmost);
        return index;
    }


    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private void printArray(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    
}