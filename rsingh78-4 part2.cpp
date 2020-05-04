/********************************
Quicksort algorithm using 
randomization
by Ranvir Singh

*********************************/

#include<iostream>
#include<climits>

using namespace std;

void display(int arr[], int n){

for(int i=0; i<n; i++){
	cout<<arr[i]<<";";
}

}

int partition(int arr[], int start, int end){

	int pivot= arr[end];

	int partitionIndex = start;
	

	for(int i=start; i<=end; i++){

		if(arr[i]<pivot){

			swap(arr[i], arr[partitionIndex]);
			partitionIndex++;
		}
	}

	swap(arr[end], arr[partitionIndex]);
	return partitionIndex;
}

void Quicksort(int arr[], int start, int end){

	if(start<end){
	
		int partitionIndex=	partition(arr, start, end);
		Quicksort(arr, start, partitionIndex-1);
		Quicksort(arr, partitionIndex+1, end);
		
	}
}
int main(){

int n;
cin>>n;
int arr[n];

for(int i=0; i<n; i++){

	cin>>arr[i];
}


Quicksort(arr, 0, n-1);

display(arr , n);

}