#include <iostream>
using namespace std;

 
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void BubbleSort(int numbers[], int n){
	int boundary = 0;
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-1-i; j++){
			if(numbers[j]>numbers[j+1]){
				swap(&numbers[i], &numbers[j]);
			}
		}
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

	BubbleSort(numbers, n);
	cout<<"Sorted Array: \n";
	printArray(numbers, n);
}