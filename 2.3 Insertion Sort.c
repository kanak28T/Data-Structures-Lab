//Write a program to sort the given elements using insertion sort technique.

#include<stdio.h>
void main() {
	int a[20], i, n, j, temp, pos;
	printf("Enter value of n : ");
	scanf("%d", &n);
	
	for (i = 0 ; i < n ; i++){
		printf("Enter element for a[%d] : ",i);
		scanf("%d", &a[i]);
	}
	
	printf("Before sorting the elements in the array are\n");
	for(i = 0 ; i < n ; i++){
		printf("Value of a[%d] = %d\n",i,a[i]);
	}

	for(i = 0 ; i < n ; i++){
		int key = a[i] ;
		j = i - 1 ;
		while(j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j = j - 1 ;
		}
		a[j+1] = key ;
	}

	printf("After sorting the elements in the array are\n");

	for(i = 0 ; i < n ; i++){
		printf("Value of a[%d] = %d\n", i , a[i]);
	}
	
}

