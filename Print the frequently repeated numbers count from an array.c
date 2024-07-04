#include <stdio.h>

void countFrequentNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int count = 1;
        if (arr[i] == -1) {
            continue;
        }
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1;
            }
        }
        if (count > 1) {
            printf("%d appears %d times\n", arr[i], count);
        }
    }
}

int main() {
    int arr[] = {3, 5, 3, 8, 2, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    countFrequentNumbers(arr, size);
    
    return 0;
}
