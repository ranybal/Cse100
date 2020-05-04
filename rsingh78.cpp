/************************************
Insertion sort program in c++ 
Written by Ranvir SIngh

1) This program asks the user to 
input integers and then it prints
the output in an ascending order
of the same integers.
2) The program prints each iteration
of the insertion sort algorithm.
************************************/
#include <bits/stdc++.h>
 
using namespace std; 
  
/* Function to sort all elements*/
void Sorting(int arr[], int n)  
{  
    int i, index, j;  
    for (i = 1; i < n; i++) 
    {  
        index = arr[i];  
        j = i - 1; 
  
        /* Move elements */
        while (j >= 0 && arr[j] > index) 
        {  
            arr[j + 1] = arr[j];
  
            j = j - 1;  
        }  
        arr[j + 1] = index;
    }  

}  
  
// A function for printing array of size n 
void printingArray(int arr[], int n)  
{  
    int i; 

    for (i = 0; i < n; i++){  
 
       cout <<arr[i] << ";";  
 
	}
cout<<"\n";	
}

  
/* Main Driver code */
int main()  
{  
int n;
cin>>n;

    int arr[n];  
     

for(int i=0;i<n;i++){
cin>>arr[i];

}
for(int i=0; i<n; i++){
	if(i>0){  
    Sorting(arr, i+1);  
    printingArray(arr, i+1);  
  
   
		}
	} 
	return 0; 
}  
























