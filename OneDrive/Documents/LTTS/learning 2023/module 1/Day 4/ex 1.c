#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

double calculateSurfaceArea(struct Box* boxPtr) {
    return 2 * (boxPtr->length * boxPtr->width +
                boxPtr->length * boxPtr->height +
                boxPtr->width * boxPtr->height);
}

int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;

    // Input the dimensions of the box
    printf("Enter the length of the box: ");
    scanf("%lf", &(boxPtr->length));
    printf("Enter the width of the box: ");
    scanf("%lf", &(boxPtr->width));
    printf("Enter the height of the box: ");
    scanf("%lf", &(boxPtr->height));

    // Calculate and display the volume and surface area
    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);

    printf("Volume of the box: %.2lf\n", volume);
    printf("Total surface area of the box: %.2lf\n", surfaceArea);

    return 0;
}
