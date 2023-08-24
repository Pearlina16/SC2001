#include <stdio.h>

void findMinMax(int ar[], int start, int end, int minMax[]) {
//minMax is an array of two integers to return the min and max found
    int tempMinMax1[2];
    int tempMinMax2[2];
    int mid;

    if (start == end) { //one element
        minMax[0] = ar[start];
        minMax[1] = ar[start];
    } 
    
    else if (end - start == 1) { //two element array
        if (ar[start] > ar[end]) {
            minMax[1] = ar[start];  // minMax[1] is larger
            minMax[0] = ar[end];
        } else {
            minMax[0] = ar[start];
            minMax[1] = ar[end];
        }
    } 
    
    else {
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

int main(){
    int n;
    printf("Enter number of elements: \n");
    scanf("%d", &n);

    int ar[n];
    for (int i=0; i<n; i++){
         printf("Enter the numbers to be sorted: \n");
         scanf("%d", &ar[i]);
    }
    
    for (int i=0; i<n; i++){
        findMinMax(&ar[i], 0, n, &ar[i]);
    }

    printf("Sorted array in ascending order \n");
    for(int i=0; i<n; i++)
        printf("%d ", ar[i]);
        
}