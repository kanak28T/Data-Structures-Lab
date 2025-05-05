//Write a program to sort (Ascending order) the given elements using merge sort technique.

#include <stdio.h>
#include "MergeSortFunctions.c"
void main() {
	int arr[15], i, n;
	printf("Enter array size : ");
	scanf("%d", &n);
	printf("Enter %d elements : ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Before sorting the elements are : ");
	display(arr, n);
	splitAndMerge(arr, 0, n - 1);
	printf("After sorting the elements are : ");
	display(arr, n);
}

void display(int arr[15], int n) {
	for(int i = 0 ; i < n ; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void merge(int arr[15], int low, int mid, int high) {
	int temp[high - low + 1];
	int i = low , j = mid+1 , k = 0 ; 
	while(i <= mid && j <= high){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
		}
	}
	while(i  <= mid){
		temp[k++] = arr[i++];
	}
	while(j <= high){
		temp[k++] =arr[j++];
	}
	for(i = low , k = 0 ; i <= high ; i++ , k++){
		arr[i] = temp[k];
	}
}
void splitAndMerge(int arr[15], int low, int high) {
	if(low < high){
		int mid = (high+low)/2;
		splitAndMerge(arr,low,mid);
		splitAndMerge(arr,mid + 1 , high);
		merge(arr,low,mid,high);
	}
}


