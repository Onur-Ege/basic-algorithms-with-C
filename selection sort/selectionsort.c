#include <stdio.h>

int selectSort(int array[], int n){
	int i,j;
	
	for(i=0;i<n;i++){
		int min = i;
		
		for(j=i+1;j<n;j++){
			if (array[j] < array[min]){
				min = j;					// find index of minimum element and assign it to min variable
			}	
		}
		
		int temp = array[i];				// swapping minimum to current index of array
		array[i] = array[min];
		array[min] = temp;
		
		printf("%d ", array[i]);
	}
}
int main(){
	
	int array[] = {12, 24, 3, 56, 34, 45, 5};
	
	int n = sizeof(array) / sizeof(array[0]);
	
	selectSort(array, n);
}
