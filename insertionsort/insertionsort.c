#include <stdio.h>

int insertionSort(int array[], int arrayLength){
	
	int i;
	for(i=1;i<arrayLength;i++){
		int temp = array[i];
		int j=i-1;
		
		while(j>=0 & array[j]>temp){
			array[j+1] = array[j];
			j -= 1;
		}	
		array[j+1] = temp;
	}
	for(i=0;i<arrayLength;i++){
		printf("%d ",array[i]);
	}
}
int main(){
	
	int array[] = {25, 36, 78, 3, 15, 48, 79};
	
	int arrayLength = sizeof(array) / sizeof(array[0]);
	
	insertionSort(array,arrayLength);
}
