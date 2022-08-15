#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int sizeOfArray = 20;

int getRandomNumber(int min, int max) {
    int number;
    number = min + rand() % (max - min +1);

    return number;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void initArray(int *arr) {
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < sizeOfArray; i++) {
        arr[i] = getRandomNumber(0, 100);
    }
    printf("Array initialization successful!\n");
}

void insertionSort(int *arr) {
    int i;
    int pos, key;

    for (i = 0; i < sizeOfArray; i++) {
        key = arr[i];
        pos = i;
        
        while (pos > 0 && arr[pos - 1] > key) {
            arr[pos] = arr[pos - 1];
            pos--;
        }
        arr[pos] = key;
    }
}

void bubbleSort(int *arr) {
    int i, j;

    for (i = 0; i < sizeOfArray; i++) {
        bool haveSwap = false;
        for (j = 0; j < sizeOfArray - 1 -i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                haveSwap = true;
            }
        }
        if (haveSwap == false) {
            break;
        }
    }
}

int binarySearch(int *arr, int x) {
    int left = 0;
    int right = sizeOfArray - 1;
    int foundIndex = -1; //-1 is Not found

    while (right >= left) {
        int mid = left + (right - left) / 2;

        if (x < arr[mid]) {
            right = mid - 1;
        }
        if (x > arr[mid]) {
            left = mid + 1;
        }
        if (x == arr[mid]) {
            foundIndex = mid;
            break;
        }
    }

    return foundIndex;
}

void display(int *arr) {
    int i;

    for (i = 0; i < sizeOfArray; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void menu() {
    int choice;
    int *array;
    int findElement;
    int foundIndex;
    array = (int*)calloc(sizeOfArray, sizeof(int));

    if (array == NULL) {
        printf("Not enough memory!");
        exit(0);
    }

    while (1) {
        printf("\n---------------------------\n");
        printf("SORT AND SEARCH\n");
        printf("---------------------------\n");
        printf("1. Init Array\n");
        printf("2. Bubble Sort\n");
        printf("3. Insertion Sort\n");
        printf("4. Search By Value\n");
        printf("5. Exit");
        printf("\n---------------------------\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initArray(array);
                break;
            case 2:
                bubbleSort(array);
                display(array);
                break;
            case 3:
                insertionSort(array);
                display(array);
                break;
            case 4:
                printf("Enter the element you want to find: ");
                scanf("%d", &findElement);
                foundIndex = binarySearch(array, findElement);

                if (foundIndex == -1) {
                    printf("Not found %d in array", findElement);
                } else {
                    printf("Found %d at position %d in array", findElement, foundIndex);
                }
                break;
            case 5:
                free(array);
                exit(0);
        }
    }



}

int main() {
    menu();

    return 0;
}
