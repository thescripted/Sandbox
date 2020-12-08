#include <stdio.h>
#include <time.h>
#define MAX_SIZE 100000 

int binsearch(int x, int *v, int n);
int optbinsearch(int x, int *v, int n);

int main() {
    int v[MAX_SIZE];
    int i;
    int index;
    int n = -1; /* Object to search for. This does not exist in the array, which will yield worst-case. */
    clock_t time_taken;

    /* Initialize Test Data */
    for (i = 0; i < MAX_SIZE; ++i)
        v[i] = i;
   
    /* performance timing for original binary search */

    for (i = 0, time_taken = clock(); i < 500000; ++i) {
        index = binsearch(n, v, MAX_SIZE);
    }

    time_taken = clock() - time_taken;

    if (index > 0)
        printf("Element %d was found at index %d\n", n, index);
    else
        printf("Element %d was not found.\n", n);

    printf("binsearch() took %lu clocks, (%lu seconds)\n", 
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
    
    /* performance timing for my binary search */

    for (i = 0, time_taken = clock(); i < 500000; ++i) {
        index = optbinsearch(n, v, MAX_SIZE);
    }

    time_taken = clock() - time_taken;

    if (index > 0)
        printf("Element %d was found at index %d\n", n, index);
    else
        printf("Element %d was not found.\n", n);

    printf("optbinsearch() took %lu clocks, (%lu seconds)\n", 
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);

    return 0;
}

int binsearch(int x, int *v, int n) {
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if ( x < *(v + mid))
            high = mid - 1;
        else if (x > *(v + mid))
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int optbinsearch(int x, int *v, int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if (x < *(v + mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (x == *(v + mid))
        return x;
    else
        return -1;
}
