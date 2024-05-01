#include <stdio.h>

int bubbleSort(int array[], int n){
	int i,j;
	
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i; j++){
			
			if(array[j]>array[j+1]){
				int temp = array[j];			// swap if next value in the array smaller than current value
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d ",array[i]);					// printing sorted array
	}
}
int main(){
	int i;
	int array[] = {36, 45, 3, 5, 37, 12, 44};

	int n = sizeof(array) / sizeof(array[0]);
	
	bubbleSort(array,n);
	
}
