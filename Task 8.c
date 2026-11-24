#include <stdio.h>

#define ROWS 6
#define COLS 4

int main() {
    int arr[ROWS][COLS] = {
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20},
        {21, 22, 23, 24}
    };
    int i, j;

    printf("Elements of the 2D array (%d rows x %d columns):\n\n", ROWS, COLS);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }

    printf("\nArray in matrix form:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
