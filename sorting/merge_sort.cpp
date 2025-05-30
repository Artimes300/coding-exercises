#include <iostream>

using namespace std;
//Merge Sort Algorithm Implementation in C++
void merge_sort(int arr[], int size) { //
   
}

void print(int array[], int size) {
	cout << "Array sorted with merge sort algorithm: " << endl;
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
   cout << "Sorting of Array with merge sort algorithm..." << endl;
   merge_sort(array, size);
   print(array, size);
   return 0;
}
