#include <stdio.h>

int findLargestNumber(int num) {
    int largest = 0;

    // Iterate through each digit of the number
    for (int i = 0; i < 4; i++) {
        int temp = num / 10; // Remove the rightmost digit
        int multiplier = 1;

        // Construct the new number by excluding the current digit
        for (int j = 0; j < 3; j++) {
            if (j == i) {
                temp *= multiplier;
            }
            multiplier *= 10;
            temp += (num % 10) * multiplier;
            num /= 10;
        }

        // Update the largest number if the current number is larger
        if (temp > largest) {
            largest = temp;
        }

        num = temp; // Restore the original number for the next iteration
    }

    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNumber = findLargestNumber(num);
    printf("Largest number by deleting a single digit: %d\n", largestNumber);

    return 0;
}
