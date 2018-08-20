#include <iostream>
using namespace std;

void InsertionSort(int numbers[], int n){
	int j=0; 
	int value = 0;

	for(int i=0; i<n-1; i++){

		value = numbers[i];
		j = i-1; 

		while(j>=0 && value<numbers[j]){

			numbers[j+1] = numbers[j];
			j = j-1;

		}

		numbers[j+1] = value;
	}
}


void printArray(int numbers[], int n){
	for(int i=0; i<n; i++){
		cout<<numbers[i]<<"  ";
	}
	cout<<"\n";
}


int main(){
	int numbers[] = {1, -2, 32, 12, 9, 8, 4, -10, 7, 40};
	int n = sizeof(numbers)/ sizeof(int) ;

	cout<<"Actual Array: \n";
	printArray(numbers, n);

	InsertionSort(numbers, n);
	cout<<"Sorted Array: \n";
	printArray(numbers, n);
}