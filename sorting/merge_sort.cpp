#include <iostream>

using namespace std;
// MergeSort Algorithm Implementation in C++
void merge(int arr[], int left, int mid, int right) {
	int size1 = mid - left + 1;//Sol yarının boyutu
	int size2 = right - mid; //Sağ yarının boyutu

	int* lefarr = new int[size1]; //Sol yarı için dinamik dizi
	int* righarr = new int[size2]; //Sağ yarı için dinamik dizi

	for (int i = 0; i < size1; i++) {
		lefarr[i] = arr[left + i]; //Sol yarıyı doldur]
	}
	for (int j = 0; j < size2; j++) {
		righarr[j] = arr[mid + 1 + j]; //Sağ yarıyı doldur
	}
//Birleştirme
	int i = 0, j = 0, k = left; // i: sol yarı için, j: sağ yarı için, k: ana dizi için indeksler
	while (i < size1 && j < size2) {
		if (lefarr[i] <= righarr[j]) { //Sol yarıdaki eleman sağ yarıdaki elemandan küçükse
			arr[k] = lefarr[i]; //Sol yarıyı ekle
			i++;
		}
		else { //Sağ yarıdaki eleman sol yarıdaki elemandan küçükse
			arr[k] = righarr[j]; //Sağ yarıyı ekle
			j++;
		}
		k++;
	}
	//Kalan elemanları ekle
	while (i < size1)
		arr[k++] = lefarr[i++];
	while (j < size2)
		arr[k++] = righarr[j++];

	delete[] lefarr;  // Bellek sızıntısını önlemek için serbest bırak
	delete[] righarr; // Bellek sızıntısını önlemek için serbest bırak

}

void merge_sort(int arr[], int left, int right) {
	
	if(left < right){
		int mid = left + (right - left) / 2; // Calculate mid index)
		merge_sort(arr, left, mid);//Sol yarıyı sırala
		merge_sort(arr, mid + 1, right); //Sağ yarıyı sırala
		/* merge_sort(0,6)
		   |
		   |
		   |-->merge_sort(0,3)
		   |        |
		   |        |-->merge_sort(0,1)
		   |        |        |
		   |        |        |-->merge_sort(0,0) // Base case: if left >= right, return (no need to sort a single element)
		   |        |        |-->merge_sort(1,1) // Base case: if left >= right, return (no need to sort a single element)
		   |        |        |-->merge(0,0,1) // Merge the two sorted halves
		   |        |-->merge_sort(2,3)
		   |                 |
		   |                 |-->merge_sort(2,2) // Base case: if left >= right, return (no need to sort a single element)
		   |                 |-->merge_sort(3,3) // Base case: if left >= right, return (no need to sort a single element)
		   |                 |-->merge(2,2,3) // Merge the two sorted halves
	       |        |
		   |		|-->merge(0,1,3) // Merge the two sorted halves
		   |
		   |-->merge_sort(4,6)
                |
				|-->merge_sort(4,5)
				|        |
				|        |-->merge_sort(4,4) // Base case: if left >= right, return (no need to sort a single element)
				|        |-->merge_sort(5,5) // Base case: if left >= right, return (no need to sort a single element)
				|        |-->merge(4,4,5) // Merge the two sorted halves
				|
				|-->merge_sort(6,6) // Base case: if left >= right, return (no need to sort a single element)
				|-->merge(4,5,6) // Merge the two sorted halves
		   
		   |-->merge(0,3,6) // Merge the two sorted halves

		*/
		merge(arr, left, mid, right);//Birleştir
	}
}

void print(int array[], int size) {
	cout << "Array sorted with merge sort algorithm: " << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
    }
}
int main(){
    int array[] = { 38, 27, 43, 3, 9, 82, 10 };
    for (int element: array) {
        cout << element << " ";
    }
    int size = sizeof(array) / sizeof(array[0]); // Calculate array size
	int left = 0; // Starting index of the array
	int right = size - 1; // Ending index of the array
   cout << "Sorting of Array with merge sort algorithm..." << endl;
   merge_sort(array, left, right);
   print(array, size);
   return 0;
}
//Update this merge sort coding...
