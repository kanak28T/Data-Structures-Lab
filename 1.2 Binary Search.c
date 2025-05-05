//Write a program to search a key element in the given array of elements using binary search.

#include<stdio.h>
void main() {
	int a[20], i, j, n, key, flag = 0, low, high, mid, temp;
	printf("Enter value of n : ");
	scanf("%d", &n);
	int pos;
	for(i = 0 ; i < n ; i++){
		printf("Enter element for a[%d] : ",i);
		scanf("%d",&a[i]);
	}
	printf("Enter key element : ");
	scanf("%d", &key);


	for(i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n-i-1 ; j++){
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp ;
			}
		}
	}
	printf("After sorting the elements in the array are\n");

	for(i = 0 ; i < n ; i++){
		printf("Value of a[%d] = %d\n",i,a[i]);
	}
	low = 0; 
	high = n - 1;
	mid = (low+high)/2 ;

	while(low <= high){
		if(a[mid] == key){
			pos = mid ;
			flag = 1;
			break;
		}
		else if(a[mid] < key){
			low = mid + 1 ;
			mid = (low+high)/2;
		}else{
			high = mid - 1;
			mid = (low+high)/2;
		}
	}
	if (flag == 1) { 
		printf("The key element %d is found at the position %d\n",key,pos); 
	} else {
		printf("The Key element %d is not found in the array\n",key); 
	}
}
