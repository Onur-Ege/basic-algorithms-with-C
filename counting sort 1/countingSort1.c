#include <stdio.h>

void countingSort1(int array[], int n){
	
	int temporaryArray[n];
	int sortedArray[n];
	
	int i;
	
	for(i=0;i<n;i++){
		
		temporaryArray[i] = 0;
		sortedArray[i] = 0;
	}
	
	for(i=0;i<n;i++){
		
		int j;	
		
		for(j =i+1;j<n;j++){
			
			if(array[i]>array[j]){
				
				temporaryArray[i] += 1; 
			}
			else{
				
				temporaryArray[j] += 1;
			}
		}
	}
	for(i=0;i<n;i++){
		
		sortedArray[temporaryArray[i]] = array[i];	
	}
	
	for(i=0;i<n;i++){
		
		array[i] = sortedArray[i];
	}
}

int main(){
	
	int array[] = {48, 78, 2, 45, 36, 14, 25, 75};
	int n = sizeof(array) / sizeof(array[0]);
	
	countingSort1(array,n-1);

	int i;
	for(i=0;i<n-1;i++){
		
		printf("%d ",array[i]);
	}
	printf("\n");
}
