#include <iostream>
using namespace std;

int *apply_all(int array1[], size_t size1, int array2[], size_t size2);
void print(int *results, size_t size);

int main(){

	int array1[5] {1, 2, 3, 4, 5};
	int array2[3] {10, 20, 30};

	cout << "Array 1: ";
	print(array1, 5);

	cout << "Array 2: ";
	print(array2, 3);

	int *results = apply_all(array1, 5, array2, 3);
	cout << "Result: ";
	print(results, 15);

	delete [] results;

	return 0;
}

int *apply_all(int array1[], size_t size1, int array2[], size_t size2){
	int *results { new int[size1 * size2] };
	int index {0};

	for(size_t i {0}; i < size2; i++)
		for (size_t j {0}; j < size1; j++)
			results[index++] = array2[i] * array1[j];
	
	return results;
}

void print(int *results, size_t size){
	cout << "[";
	for (size_t i = 0; i < size; i++)
		cout << " " <<results[i];
	cout << " ]" << endl;
}