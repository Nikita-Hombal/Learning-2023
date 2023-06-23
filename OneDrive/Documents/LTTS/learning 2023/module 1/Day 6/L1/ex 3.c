#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct LogEntry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
};

void extractLogEntries(struct LogEntry logEntries[], int *numEntries, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    char line[256];
    char *token;
    int entryCount = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        
        // Extract the values from the line and assign them to the corresponding structure fields
        logEntries[entryCount].entryNo = atoi(token);
        
        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].sensorNo, token);
        
        token = strtok(NULL, ",");
        logEntries[entryCount].temperature = atof(token);
        
        token = strtok(NULL, ",");
        logEntries[entryCount].humidity = atoi(token);
        
        token = strtok(NULL, ",");
        logEntries[entryCount].light = atoi(token);
        
        token = strtok(NULL, ",");
        strcpy(logEntries[entryCount].timestamp, token);

        entryCount++;
    }

    *numEntries = entryCount;

    fclose(file);
}

void displayLogEntries(const struct LogEntry logEntries[], int numEntries) {
    printf("%-8s %-10s %-12s %-8s %-8s %-8s\n", "EntryNo", "SensorNo", "Temperature", "Humidity", "Light", "Timestamp");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%-8d %-10s %-12.2f %-8d %-8d %-8s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }
}

int main() {
    struct LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    extractLogEntries(logEntries, &numEntries, "data.csv");
    displayLogEntries(logEntries, numEntries);

    return 0;
}
