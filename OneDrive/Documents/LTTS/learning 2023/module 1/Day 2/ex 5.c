#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int getTotalSetBits(int arr[], int size) {
    int totalSetBits = 0;
    for (int i = 0; i < size; i++) {
        totalSetBits += countSetBits(arr[i]);
    }
    return totalSetBits;
}

int main() {
    int arr[] = {0x1, 0xF4, 0x10001};
    int size = sizeof(arr) / sizeof(arr[0]);

    int totalSetBits = getTotalSetBits(arr, size);

    printf("Total number of set bits: %d\n", totalSetBits);

    return 0;
}
