#include <stdio.h>

int lamutoPartition(int array[], int first, int last);
int quickSelect(int array[], int first, int last, int kthSmallest);

int lamutoPartition(int array[], int first, int last){
	
	int p = array[first];
	int s = first;
	int i;
	
	for(i=first+1;i<=last;i++){
		if(array[i]<p){
			s += 1;
			
			int temp = array[s];
			array[s] = array[i];
			array[i] = temp;		
		}
	}
	int tempo = array[first];
	array[first] = array[s];
	array[s] = tempo;
	return s-1;
}
int quickSelect(int array[], int first, int last, int kthSmallest){

	int s = lamutoPartition(array,first,last);

	if(s == kthSmallest){
		return array[s];
	}
	else if(s > first + kthSmallest){
		return quickSelect(array, first, s-1,kthSmallest);
	}
	else{
		return quickSelect(array, s+1, last, kthSmallest - s);
	}
}
int main(){
	
	int array[] = {25, 78, 36, 7, 9, 13, 5, 12, 17};
	int first = 0;
	int last = sizeof(array) / sizeof(array[0]);
	
	int kthSmallest;
	
	printf("this program find kth smallest number. please enter k:");
	scanf("%d",&kthSmallest);
	
	int answer = quickSelect(array,first,last-1,kthSmallest);
	printf("%d is %dth smallest number of array.\n",answer,kthSmallest);
	
}
