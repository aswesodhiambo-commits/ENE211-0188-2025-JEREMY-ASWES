#include <stdio.h>

#define BUFFER_SIZE 5

typedef struct {
    int data[BUFFER_SIZE];
    int head;   // index where the next sample will be written
    int count;  // number of valid samples stored (max BUFFER_SIZE)
} CircularBuffer;

void init(CircularBuffer *cb) {
    cb->head = 0;
    cb->count = 0;
}

void insert(CircularBuffer *cb, int value) {
    cb->data[cb->head] = value;
    cb->head = (cb->head + 1) % BUFFER_SIZE;  // circular indexing
    if (cb->count < BUFFER_SIZE) {
        cb->count++;
    }
}

void printChronological(const CircularBuffer *cb) {
    if (cb->count == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    // If full, the oldest sample is at head. Otherwise it is at index 0.
    int start = (cb->count == BUFFER_SIZE) ? cb->head : 0;

    printf("Samples (oldest -> newest): ");
    for (int i = 0; i < cb->count; i++) {
        int idx = (start + i) % BUFFER_SIZE;
        printf("%d ", cb->data[idx]);
    }
    printf("\n");
}

void printRaw(const CircularBuffer *cb) {
    printf("Raw buffer: [");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (i < cb->count || cb->count == BUFFER_SIZE) {
            printf("%d", cb->data[i]);
        } else {
            printf("-");
        }
        if (i < BUFFER_SIZE - 1) printf(" ");
    }
    printf("]\n");
}

int main() {
    CircularBuffer cb;
    int choice, value;

    init(&cb);

    printf("Circular Data Logger (BUFFER_SIZE = %d)\n", BUFFER_SIZE);

    do {
        printf("\n1. Insert new sample\n");
        printf("2. Print samples (chronological order)\n");
        printf("3. Show raw buffer\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter sensor value: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    return 1;
                }
                insert(&cb, value);
                break;
            case 2:
                printChronological(&cb);
                break;
            case 3:
                printRaw(&cb);
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
