#include <stdio.h>
#include <stdlib.h>

void sort(char array[], int n){
	
	int low = 0;
	int high = n-1;
	int m = 0;
	
	while(m <= high){
		if (array[m] == 'B'){
			
			char temp = array[low];
			array[low] = array[m];
			array[m] = temp;
			
			low++;
			m++;
			
		}else if (array[m] == 'M' ){
			m++;
		}else{
			
			char temp = array[m];
			array[m] = array[high];
			array[high] = temp;
			
			high--;
		}
	}
}

int main(int argc, char *argv[]) {
	
	char array[7] = {'B','M','W','W','B','M','B'};
	//int i;
	//while( (scanf("%c",&array[i]) ) != -1){
	//	i++;
	//}
	
	int n = sizeof(array)/sizeof(array[0]);
	
	
	sort(array,n);
	
	int j;
	for(j = 0; j<n; j++){
		printf("%c",array[j]);
	}	
	
	return 0;
}
