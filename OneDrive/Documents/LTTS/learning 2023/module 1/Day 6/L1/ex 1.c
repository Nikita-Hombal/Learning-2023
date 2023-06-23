#include <stdio.h>

int main() {
    FILE *source, *destination;
    char ch;

    // Open the source file in read mode
    source = fopen("source_file.txt", "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    destination = fopen("destination_file.txt", "w");
    if (destination == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(source);
        return 1;
    }

    // Copy the contents of source file to destination file
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    // Close the files
    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");

    return 0;
}
