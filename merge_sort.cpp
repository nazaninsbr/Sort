#include <iostream>
using namespace std;

void printArray(int numbers[], int n){
	for(int i=0; i<n; i++){
		cout<<numbers[i]<<"  ";
	}
	cout<<"\n";
}

void Merge(int numbers[], int start, int middle, int end){
	int first_half_size = middle-start+1; 
	int second_half_size = end-middle; 

	int arrRight[second_half_size], arrLeft[first_half_size];
	for(int i=0; i<first_half_size; i++){
		arrLeft[i]=numbers[start+i];
	}
	for(int i=0; i<second_half_size; i++){
		arrRight[i]=numbers[middle+1+i];
	}

	int i, j, mainCounter;
	i = 0; 
	j = 0;
	mainCounter = start;

	while(i<first_half_size && j<second_half_size){
		if(arrLeft[i] <= arrRight[j]){
			numbers[mainCounter] = arrLeft[i];
			i++;
		} else {
			numbers[mainCounter] = arrRight[j];
			j++;
		} 
		mainCounter++;
	}
	while(i<first_half_size){
		numbers[mainCounter] = arrLeft[i];
		i++;
		mainCounter++;
	}
	while(j<second_half_size){
		numbers[mainCounter] = arrRight[j];
		j++;
		mainCounter++;
	}
}


void MergeSort(int numbers[], int start, int end){
	if(start<end){
		int middle = start + (end-start)/2;

		MergeSort(numbers, start, middle);
		MergeSort(numbers, middle+1, end);

		Merge(numbers, start, middle, end);
	}
}

int main(){
	int numbers[] = {1, -2, 32, 12, 9, 8, 4, -10, 7, 40};
	int n = sizeof(numbers)/ sizeof(int);

	cout<<"Actual Array: \n";
	printArray(numbers, n);

	MergeSort(numbers, 0, n-1);
	cout<<"Sorted Array: \n";
	printArray(numbers, n);
}