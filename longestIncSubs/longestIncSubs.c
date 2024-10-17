#include <stdio.h>

int maximum(int x, int y) {		//find the maximum of two given integer
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

void longIncSub(int subseq[], int n) {
    int lisLength[100];  // Assuming a maximum size of the array
    int i, j;
    // Initialize LIS lengths to 1
    //at the beginning all subseqeunces lengths are 1
    for (i = 0; i < n; i++) {
        lisLength[i] = 1;
	}
    // Dynamic Programming to find the LIS
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (subseq[i] > subseq[j] && lisLength[i] < lisLength[j] + 1) {
                lisLength[i] = lisLength[j] + 1;
            }
        }
    }
    // Find the maximum LIS length
    int maxLength = 0;
    for (i = 0; i < n; i++) {
        maxLength = maximum(maxLength, lisLength[i]);
    }

    int lis[100];  // Assuming a maximum size of the array
    int currentLength = maxLength;			//
    for (i = n - 1; i >= 0; i--) {
        if (lisLength[i] == currentLength) {
            lis[--currentLength] = subseq[i];
        }
    }
    // Print the LIS   
    for (i = 0; i < maxLength; i++) {
        printf("%d ", lis[i]);
    }
    printf("\n");
}

int main() {
    int sequence[] = {50,3,100,7,40,80};
    int n = sizeof(sequence) / sizeof(sequence[0]);

    longIncSub(sequence, n);

    return 0;
}
