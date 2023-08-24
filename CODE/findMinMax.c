#include <stdio.h>

void findMinMax(int ar[], int start, int end, int minMax[]) {
    int tempMinMax1[2];
    int tempMinMax2[2];
    int mid;

    if (start == end) {
        minMax[0] = ar[start];
        minMax[1] = ar[start];
    } else if (end - start == 1) {
        if (ar[start] > ar[end]) {
            minMax[1] = ar[start];
            minMax[0] = ar[end];
        } else {
            minMax[0] = ar[start];
            minMax[1] = ar[end];
        }
    } else {
        mid = (start + end) / 2;

        findMinMax(ar, start, mid, tempMinMax1);
        findMinMax(ar, mid + 1, end, tempMinMax2);

        if (tempMinMax1[0] < tempMinMax2[0])
            minMax[0] = tempMinMax1[0];
        else
            minMax[0] = tempMinMax2[0];

        if (tempMinMax1[1] > tempMinMax2[1])
            minMax[1] = tempMinMax1[1];
        else
            minMax[1] = tempMinMax2[1];
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int minMax[2]; // 0th index for min, 1st index for max
    findMinMax(arr, 0, n - 1, minMax);

    printf("Minimum: %d\n", minMax[0]);
    printf("Maximum: %d\n", minMax[1]);

    return 0;
}
