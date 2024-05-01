#include <stdio.h>

int lamutoPartition(int array[], int first, int last){
	
	int p = array[first];
	int s = first;
	
	int i;
	for(i=first+1;i<=last;i++){
		if(array[i] < p){
			s += 1;
			int temp = array[s];
			array[s] = array[i];
			array[i] = temp;
		}
	}
	int temp = array[first];
	array[first] = array[s];
	array[s] = temp;
	
	return s;
}
void quickSort(int array[], int first, int last){
	
	if(first < last){
		int s = lamutoPartition(array,first,last);
		quickSort(array,first,s-1);
		quickSort(array,s+1,last);
	}
}
int main(){
	
	int array[] = {89, 78, 15, 25 ,24 ,36, 2, 3, 17};
	int first = 0;
	int last = sizeof(array) / sizeof(array[0]);
	
	quickSort(array,first,last - 1);
	
	int i;
	for(i=0; i<last; i++){
		
		printf("%d ",array[i]);
		
	}	
}
