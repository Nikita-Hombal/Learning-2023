#include <stdio.h>

struct Complex {
    double real;
    double imaginary;
};

void readComplex(struct Complex* num) {
    printf("Enter the real part: ");
    scanf("%lf", &(num->real));
    printf("Enter the imaginary part: ");
    scanf("%lf", &(num->imaginary));
}

void writeComplex(struct Complex num) {
    printf("Complex number: %.2lf + %.2lfi\n", num.real, num.imaginary);
}

struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

struct Complex multiplyComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    result.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    // Read the first complex number
    printf("Enter the first complex number:\n");
    readComplex(&num1);

    // Read the second complex number
    printf("Enter the second complex number:\n");
    readComplex(&num2);

    // Write the complex numbers
    printf("First complex number:\n");
    writeComplex(num1);
    printf("Second complex number:\n");
    writeComplex(num2);

    // Perform addition
    sum = addComplex(num1, num2);
    printf("Sum of the complex numbers:\n");
    writeComplex(sum);

    // Perform multiplication
    product = multiplyComplex(num1, num2);
    printf("Product of the complex numbers:\n");
    writeComplex(product);

    return 0;
}
