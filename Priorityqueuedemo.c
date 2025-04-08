//Demo for Priority queue in DSA concept.
#include <stdio.h>
#define MAX 100

// Priority Queue implemented as Min-Heap
int heap[MAX];
int size = 0;

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert an element into the priority queue
void insert(int value) {
    if (size >= MAX) {
        printf("Priority Queue is full!\n");
        return;
    }

    // Insert the new value at the end of the heap
    heap[size] = value;
    int current = size;
    size++;

    // Bubble up to maintain the heap property
    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

// Function to remove and return the element with the highest priority (min element)
int deleteMin() {
    if (size <= 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    // Heapify down to maintain the heap property
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest == current) {
            break;
        }

        swap(&heap[current], &heap[smallest]);
        current = smallest;
    }

    return min;
}

// Function to display the priority queue
void display() {
	int i;
    if (size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue: ");
    for ( i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete Min\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                value = deleteMin();
                if (value != -1) {
                    printf("Deleted element with highest priority: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

