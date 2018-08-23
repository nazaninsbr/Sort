#include <iostream>
using namespace std;

void printArray(int numbers[], int n){
	for(int i=0; i<n; i++){
		cout<<numbers[i]<<"  ";
	}
	cout<<"\n";
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int Partition(int numbers[], int start, int end){
	// cout<<"INSIDE PARTITION\n";
	int pivot = numbers[start];
	int smallerIndex = start-1;
	int piIndex = start;
	for(int i=start+1; i<=end; i++){
		if(numbers[i]<=pivot){
			// cout<<"i= "<<i<<" number[i]= "<<numbers[i]<<" piIndex= "<<piIndex<<" pivot= "<<pivot<<"\n";
			smallerIndex++;
			swap(&numbers[i], &numbers[smallerIndex]);
			if(smallerIndex==piIndex){
				piIndex = i;
			}
		}
	}
	smallerIndex++;
	swap(&numbers[smallerIndex], &numbers[piIndex]);
	// printArray(numbers, 10);
	return smallerIndex;
}

void QuickSort(int numbers[], int start, int end){
	if(start<end){
		int partition = Partition(numbers, start, end);

		QuickSort(numbers, start, partition-1);
		QuickSort(numbers, partition+1, end);
	}
}

int main(){
	int numbers[] = {1, -2, 32, 12, 9, 8, 4, -10, 7, 40};
	int n = sizeof(numbers)/ sizeof(int);

	cout<<"Actual Array: \n";
	printArray(numbers, n);

	QuickSort(numbers, 0, n-1);
	cout<<"Sorted Array: \n";
	printArray(numbers, n);
}