#include <stdio.h>

int main() {
    int n, i, value, pos;

    printf("Input the size of array : ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Size of array must be greater than 0.\n");
        return 1;
    }

    int arr[n + 1];

    printf("Input %d elements in the array in ascending order:\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Input the value to be inserted : ");
    scanf("%d", &value);

    printf("Input the Position, where the value to be inserted : ");
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position. Enter a value between 1 and %d.\n", n + 1);
        return 1;
    }

    printf("The current list of the array : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    printf("\nAfter Insert the element the new list is : ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}
