#include <stdio.h>

int binarySearch(int array[],int first,int last, int key){
	
	int mid = (first + last) / 2;
	
	while(first < last){
	
		if(array[mid]== key){
			return 1;
		}
		else if(key < array[mid]){
			return binarySearch(array,first, mid - 1, key);
		}else{
			return binarySearch(array,first + 1, last, key);
		}	
	}
	return 0;
}
int main(){
	int array[] = {25, 4, 9, 78, 34, 6, 15, 24, 17};
	
	int first = 0;
	int last = sizeof(array) / sizeof(array[0]);
	
	int key;
	printf("please enter the key:");
	scanf("%d",&key);
	
	if(binarySearch(array,first,last,key)){
		printf("yes, it exist!\n");
	}else{
		printf("key is not found\n");
	}
}
