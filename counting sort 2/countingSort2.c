#include <stdio.h>

void countingSort2(int array[], int n, int k){
	
	int i;
	int temporaryArray[k+1];
	
	for(i=0;i<=k;i++){
		
		temporaryArray[i] = 0;
	}
	
	int sortedArray[n];

	for(i=0;i<n;i++){
		
		sortedArray[i] = 0;		
	}
	
	for(i=0;i<n;i++){
		
		temporaryArray[array[i]] += 1;
	}
	
	for(i=1;i<=k;i++){
		
		temporaryArray[i] = temporaryArray[i] + temporaryArray[i-1];
	}
	
	for(i=n-1;i>=0;i--){
		
		sortedArray[temporaryArray[array[i]]-1] = array[i];
		temporaryArray[array[i]] -= 1;
	}
	
	for(i=0;i<n;i++){
		
		array[i] = sortedArray[i];
	}
}
int main(){
	
	int array[] = {85, 78, 5, 23, 15, 36, 4, 45, 97};
	int n = sizeof(array) / sizeof(array[0]);
	
	int max = 0;
	
	int i;
	
	for(i=0;i<n;i++){
		
		if(array[i] > max){
			
			max = array[i];
		}
	}
	
	countingSort2(array,n,max);
	
	for(i=0;i<n;i++){
		printf("%d ",array[i]);
	}
}
