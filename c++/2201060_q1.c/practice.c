#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <pthread.h>

typedef struct {
    int* array;
    int start;
    int end;
} Args;

void merge(int* array, int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = temp[i - left];
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void* routine(void* arg) {
    Args* args = arg;
    mergeSort(args->array, args->start, args->end);
    pthread_exit(NULL);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int numbers[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int mid = n / 2;

    Args args1 = { numbers, 0, mid - 1 };
    Args args2 = { numbers, mid, n - 1 };


    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, &routine, &args1);
    pthread_create(&thread2, NULL, &routine, &args2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    merge(numbers, 0, mid - 1, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
