
/****************************
Heapsort algorithm
by Ranvir Singh

*****************************/
#include <iostream> 
  
using namespace std; 
  

void heapify(int a[], int n, int i) 
{ 
    int greater = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2;  

    //left child larger than root
    if (l < n && a[l] > a[greater]) 
        greater = l; 
  
    // right child larger than root 
    if (r < n && a[r] > a[greater]) 
        greater = r; 
  
    // root is not largest
    if (greater != i) 
    { 
        swap(a[i], a[greater]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(a, n, greater); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Building heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
       
        swap(arr[0], arr[i]); 
  
        heapify(arr, i, 0); 
    } 
} 
  
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << ";"; 
    
} 
  
// Driver program 
int main() 
{ 
	int n;
	cin>>n;
    int arr[n]; 

	for(int i=0; i<n; i++){
		cin>>arr[i];
	} 
  
    heapSort(arr, n); 
  
    printArray(arr, n); 
} 
