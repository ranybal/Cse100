#include<iostream>
using namespace std;

//utility function to print array.
void PrintArray(int *a, int n){
for(int i=0; i<n; i++){

cout<<a[i]<<";";

}
cout<<"\n";

}
//function for merging two subarrays into parent array.
void merge(int *a, int s, int e){

int mid= (s+e)/2;
int i= s;
int j= mid+1;
int k= s;

int temp[e+1];//temp array to store the sorted array.
while(i<=mid & j<=e){//validity

if(a[i]<=a[j]){

temp[k++]=a[i++];

}
else{

temp[k++]=a[j++];

}


}
while(i<=mid){

temp[k++]=a[i++]; 
}
while(j<=e){
temp[k++]=a[j++];

}
for(int i=s; i<=e; i++){

a[i]=temp[i];// megring the sorted array back to original array.

}
}


//funtion for sorting parent array into subarrays.
void mergesort(int *a, int s, int e){

if(s>=e){
return;
}

int mid = (s+e)/2;

mergesort(a, s, mid);
mergesort(a,mid+1 ,e);
merge(a, s, e);
}



// Driver code..
int main(){

int n;
cin>>n;
int arr[n];
for(int i=0; i<n; i++){

cin>>arr[i];

}

mergesort(arr, 0, n-1);
PrintArray(arr, n);

}
