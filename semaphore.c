#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int matrix[MAX_ROWS][MAX_COLS];
int column_sums[MAX_COLS];
sem_t semafor;
int row, column;

void* calcColSum(void* col_index);
void* sortingAndPrintingSums();

int main() {
    // Read row and column numbers
    scanf("%d %d", &row, &column);
	int i,j;
    // Read matrix elements
    for (i = 0; i < row; ++i) {
        for (j = 0; j < column; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Initialize semaphores
    sem_init(&semafor, 0, 1);
    

    // Create threads for calculating column sums
    pthread_t threads[MAX_COLS];
    int col_indices[MAX_COLS];

    for (i = 0; i < column; ++i) {
        col_indices[i] = i;
        pthread_create(&threads[i], NULL, calcColSum, (void*)&col_indices[i]);
    }

    // Create the final thread for sorting and printing column sums
    pthread_t sonThread;

    // Join threads
    for (i = 0; i < column; ++i) {
        pthread_join(threads[i], NULL);
    	
    }
    sleep(1);
    pthread_create(&sonThread, NULL, sortingAndPrintingSums, NULL);
    pthread_join(sonThread, NULL);

    // Clean up
    sem_destroy(&semafor);
    

    return 0;
}
void* calcColSum(void* col_index) {

    sem_wait(&semafor);
	int i;
    int sum = 0;
    for (i = 0; i < row; ++i) {
        sum += matrix[i][*((int*)col_index)];
    }

    column_sums[*((int*)col_index)] = sum;
    
    sem_post(&semafor);
    
    return NULL;
}
void* sortingAndPrintingSums() {
  	int i,j;
    // Sort the column sums
    for (i = 0; i < column - 1; ++i) {
        for (j = 0; j < column - i - 1; ++j) {
            if (column_sums[j] > column_sums[j + 1]) {
                // Swap
                int temp = column_sums[j];
                column_sums[j] = column_sums[j + 1];
                column_sums[j + 1] = temp;
            }
        }
    }

    // Print sorted column sums
    for (i = 0; i < column; ++i) {
        printf("%d ", column_sums[i]);
    }
	printf("\n");
    return NULL;
}


