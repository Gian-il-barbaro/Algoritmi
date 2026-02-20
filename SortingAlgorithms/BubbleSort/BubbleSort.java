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

import java.util.Arrays;

class Main {

  // funzione per ordinare un array usando il bubble sort
  static void bubbleSort(int array[]) {
    int size = array.length;
    
    // loop per scorrere tutti gli elementi dell'array
    for (int i = 0; i < size - 1; i++)
    
      // loop per confrontare l'elemento corrente con il successivo
      for (int j = 0; j < size - i - 1; j++)

        // guarda se l'elemento corrente è maggiore del successivo
        if (array[j] > array[j + 1]) {

          // scambio degli elementi
          int temp = array[j];
          array[j] = array[j + 1];
          array[j + 1] = temp;
        }
  }

  public static void main(String args[]) {
      
    int[] data = { -2, 45, 0, 11, -9 };
    
    bubbleSort(data);
    
    System.out.println("Array ordinato in ordine crescente:");
    System.out.println(Arrays.toString(data));
  }
}