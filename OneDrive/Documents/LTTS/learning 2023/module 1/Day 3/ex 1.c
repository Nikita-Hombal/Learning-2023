#include <stdio.h>

void printIncreasing(int n);
void printSpaces(int n);
void printDecreasing(int n);

int main() {
    int rows;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Print the pattern
    for (int i = 1; i <= rows; i++) {
        printIncreasing(i);
        printSpaces(2 * (rows - i));
        printDecreasing(i);
        printf("\n");
    }

    return 0;
}

void printIncreasing(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    for (int i = 1; i <= n; i++) {
        printf(" ");
    }
}

void printDecreasing(int n) {
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
    }
}
