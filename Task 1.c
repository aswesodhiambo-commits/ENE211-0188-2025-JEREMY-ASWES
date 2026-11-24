#include <stdio.h>

int main() {
    int n, i;

    printf("Input the number of elements to store in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of elements must be greater than 0.\n");
        return 1;
    }

    int arr[n];

    printf("Input %d number of elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe values stored into the array are : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThe values stored into the array in reverse are : ");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
