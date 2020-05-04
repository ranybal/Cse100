#include<iostream>
#include<climits>
using namespace std;

int max(int a, int b){// maximum of two numbers/.
if(a>b)
	return a;
else
	return b;
}
int Max(int a, int b, int c){return max(max(a, b), c);}// max of three numbers

int Max_sum_subarray(int a[], int size){

if(size ==1){
return a[0];
}

int m = size/2;
int left_MMS = Max_sum_subarray(a, m);
int right_MMS = Max_sum_subarray(a+m, size-m);

int leftsum=INT_MIN; int sum=0;
for(int i=(m-1); i>=0; i--){
sum = sum + a[i]; 
leftsum = max(sum, leftsum);
}
sum=0; 
int rightsum = INT_MIN;
for(int i=m; i<size; i++){
sum= sum+a[i];
rightsum = max(rightsum, sum); 
}
int crossingsum = leftsum + rightsum;
return Max(right_MMS, left_MMS, crossingsum);
}

int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
cin>>arr[i];
}
int max_sum = Max_sum_subarray(arr, n);
cout<<max_sum;
}




