#include <stdio.h>
/* qsort: sort v[left] ... v[right] into increasing order */


void swap(int v[], int i, int j) {
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int partition(int v[], int left, int right) {
    int pivot = right;
    int i = left;
    int j;
    for (j = i; j < right; j++) {
        if (v[j] < v[pivot]) {
            swap(v, i++, j);
        }
    }
    swap(v, i, pivot);
    return i;
}

void qsort(int v[], int left, int right) {
    int p;
    if (left < right) {
        p = partition(v, left, right);
        qsort(v, left, p - 1);
        qsort(v, p + 1, right);
    }
}

int main() {
    int arr[] = {1, 5, 2, 9, 14, 33, 0, 1, 24, 58, 3, 4, 18, 9, 0, 1, 0};
    int len = sizeof(arr) / sizeof(*arr);
    qsort(arr, 0, len - 1);
    for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
