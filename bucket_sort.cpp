#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void BucketSort(float numbers[], int sizeOfArray){
	vector< vector<float> > buckets;
	for(int i=0; i<sizeOfArray; i++){
		vector<float> v;
		buckets.push_back(v);
	}
	for(int j=0; j<sizeOfArray; j++){
		int index = sizeOfArray*numbers[j];
		buckets[index].push_back(numbers[j]);
	}
	for (int i=0; i<sizeOfArray; i++){
       sort(buckets[i].begin(), buckets[i].end());
	}
 
    int index = 0;
    for (int i = 0; i < sizeOfArray; i++){
        for (int j = 0; j < buckets[i].size(); j++){
        	numbers[index++] = buckets[i][j];
        }
    }
}	

void printArray(float numbers[], int n){
	for(int i=0; i<n; i++){
		cout<<numbers[i]<<"  ";
	}
	cout<<"\n";
}


int main(){
	float numbers[] = {0.1, 0.32, 0.4, 0.12, 0.21, 0.33, 0.42, 0.323};
	int n = sizeof(numbers)/ sizeof(int) ;

	cout<<"Actual Array: \n";
	printArray(numbers, n);

	BucketSort(numbers, n);
	cout<<"Sorted Array: \n";
	printArray(numbers, n);
}