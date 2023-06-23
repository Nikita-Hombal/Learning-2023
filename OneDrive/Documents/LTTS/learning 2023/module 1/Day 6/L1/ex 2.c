#include <stdio.h>
#include <ctype.h>
#include <string.h>

void convertToUpperCase(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

void convertToLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void convertToPureUpperCase(char *str) {
    int length = strlen(str);
    int i;

    for (i = 0; i < length; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        return 1;
    }

    char *option = argv[1];
    char *sourceFilename = argv[2];
    char *destinationFilename = argv[3];

    FILE *source, *destination;
    char ch;

    source = fopen(sourceFilename, "r");
    if (source == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    destination = fopen(destinationFilename, "w");
    if (destination == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(source);
        return 1;
    }

    // Copy the contents of source file to destination file with case handling
    while ((ch = fgetc(source)) != EOF) {
        if (strcmp(option, "-s") == 0) {
            fputc(toupper(ch), destination);
        } else if (strcmp(option, "-l") == 0) {
            fputc(tolower(ch), destination);
        } else if (strcmp(option, "-u") == 0) {
            fputc(toupper(ch), destination);
        } else {
            fputc(ch, destination);
        }
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");

    return 0;
}
