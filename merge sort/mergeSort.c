#include <stdio.h>

void merge(int array[], int first, int last, int mid){
	
	int a = mid - first + 1;
	int b = last - mid;	
	
	int left[a];
	int right[b];
	
	int i;
	for(i=0;i<a;i++){
		left[i] = array[first + i];
	}
	
	for(i=0;i<b;i++){
		right[i] = array[mid + i + 1];
	}
	int m = 0;
	int n = 0;
	
	for(i=first;i<=last;i++){
		if(m<a &&( n>=b || (left[m] < right[n]))){
			array[i] = left[m];			
			m++;
		}else{
			array[i] = right[n];
			n++;
		}	
	}
}
void mergeSort(int array[], int first, int last){
	
	if(first < last){
		int mid = (last + first) / 2;
		mergeSort(array,first,mid);
		mergeSort(array,mid+1,last);
		merge(array,first,last,mid);
	}	
}
int main(){
	int array[] = {25, 78, 74, 4, 56, 12, 36, 8};
	int first = 0;
	int last = sizeof(array) / sizeof(array[0]);
	
	mergeSort(array,first,last-1);
	
	int i;
	for(i=0;i<last;i++){
		printf("%d ",array[i]);
	}
}
