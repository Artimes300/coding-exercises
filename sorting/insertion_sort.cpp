#include <iostream>

using namespace std;
// InsertionSort Algorithm Implementation in C++
void insertion_sort(int arr[], int size) { //ikinci elemandan itibaren soldan kontrole başlanır.İskambil kartları gibi düşün.
    
  for(int i = 1; i < size; i++){
      int key = arr[i];
	  int j = i - 1;
      while (j >= 0 && key > arr[j]) {
		  arr[j + 1] = arr[j];
          j--;
      }
	  arr[j + 1] = key; // Anahtar eleman doğru konumuna yerleştirilir.]
  }
}

void print(int array[], int size) {
	cout << "Array sorted with insertion sort algorithm: " << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
    }
}
int main(){
    int array[] = { 12, 45, 23, 67, 34 };
	// Print the original array
	cout << "Original array: " << endl;
    for (int element : array) {
        cout << element << " ";
    }
    int size = sizeof(array) / sizeof(array[0]); // Calculate array size
   cout << "Sorting of Array with insertion sort algorithm..." << endl;
   insertion_sort(array, size);
   print(array, size);
   return 0;
}
//Update this code...
