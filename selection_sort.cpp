#include <iostream>

using namespace std;

int FindMinimumIn(int numbers[], int start, int end){
	int minIndex = -1; 
	int minNum = 0; 
	for(int j=start; j<end; j++){
		if(minIndex==-1){
			minNum = numbers[j];
			minIndex = j;
		} else {
			if(numbers[j]<minNum){
				minNum = numbers[j];
				minIndex = j;
			}
		}
	}
	return minIndex;
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void SelectionSort(int numbers[], int n){
	int boundary = 0;
	for(int i=0; i<n-1; i++){
		int minIndex = FindMinimumIn(numbers, i, n);
		swap(&numbers[i], &numbers[minIndex]);
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

	SelectionSort(numbers, n);
	cout<<"Sorted Array: \n";
	printArray(numbers, n);
}