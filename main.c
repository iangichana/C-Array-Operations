#include <stdio.h>

#define MAX 100  

void insert(int arr[], int *size, int pos, int value) {
    if (*size >= MAX) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *size; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    (*size)++;
    printf("Inserted %d at position %d\n", value, pos);
}

void delete(int arr[], int *size, int pos) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }

    printf("Deleted element: %d\n", arr[pos]);

    for (int i = pos; i < *size - 1; i++)
        arr[i] = arr[i + 1];

    (*size)--;
}

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[MAX], size = 0, choice, pos, value;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter position (0-based index) and value: ");
                scanf("%d %d", &pos, &value);
                insert(arr, &size, pos, value);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                delete(arr, &size, pos);
                break;
            case 3:
                display(arr, size);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
