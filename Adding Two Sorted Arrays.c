#include <stdio.h>

int sumOfArrays(int nums1[], int m, int nums2[], int n) {
    int sum[m + n];
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            sum[k++] = nums1[i++];
        } else {
            sum[k++] = nums2[j++];
        }
    }

    while (i < m) {
        sum[k++] = nums1[i++];
    }

    while (j < n) {
        sum[k++] = nums2[j++];
    }

    int totalSum = 0;
    for (int l = 0; l < m + n; l++) {
        totalSum += sum[l];
    }

    return totalSum;
}

int main() {
    int nums1[] = {1, 3, 5};
    int m = sizeof(nums1) / sizeof(nums1[0]);

    int nums2[] = {2, 4, 6};
    int n = sizeof(nums2) / sizeof(nums2[0]);

    int result = sumOfArrays(nums1, m, nums2, n);
    printf("Sum of the two arrays: %d\n", result);

    return 0;
}
