#include <stdio.h>

void findSmallestAndLargestDigits(int n, int numbers[]) {
    int smallest = 9;
    int largest = 0;
    int validDigitsFound = 0;

    for (int i = 0; i < n; i++) {
        int currentNumber = numbers[i];

        while (currentNumber != 0) {
            int digit = currentNumber % 10;

            if (digit < smallest) {
                smallest = digit;
                validDigitsFound = 1;
            }

            if (digit > largest) {
                largest = digit;
                validDigitsFound = 1;
            }

            currentNumber /= 10;
        }
    }

    if (validDigitsFound) {
        printf("Smallest digit: %d\n", smallest);
        printf("Largest digit: %d\n", largest);
    } else {
        printf("Not Valid\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    findSmallestAndLargestDigits(n, numbers);

    return 0;
}
