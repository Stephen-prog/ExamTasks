#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 50000000   // 50 million integers (~190 MB)
#define REPEATS 5       // repeat test to get average time

// test access pattern with a given stride
void test_access(int *arr, int stride, const char *label) {
    clock_t start = clock();
    volatile long total = 0;  // volatile prevents optimization

    for (int r = 0; r < REPEATS; r++) {
        for (int i = 0; i < SIZE; i += stride) {
            total += arr[i];
        }
    }

    clock_t end = clock();
    double secs = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%s (stride=%d): %.6f sec (avg)\n", label, stride, secs / REPEATS);
    // prevents compiler from optimizing total away
    if (total == 0) printf("ignore this line: %ld\n", total);
}

int main() {
    int *arr = malloc(SIZE * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) arr[i] = i;

    printf("=== Memory hierarchy timing test ===\n");
    printf("Array size: %d ints (~%.2f MB)\n\n",
           SIZE, (SIZE * sizeof(int)) / (1024.0 * 1024.0));

    test_access(arr, 1, "Sequential access");   // high spatial locality
    test_access(arr, 16, "Strided access");     // moderate cache usage
    test_access(arr, 256, "Sparse access");     // low cache usage

    free(arr);
    return 0;
}
