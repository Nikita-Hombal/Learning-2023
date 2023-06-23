#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

void getTimeDifference(struct Time t1, struct Time t2, struct Time* difference) {
    int totalSeconds1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int totalSeconds2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int diffSeconds = totalSeconds2 - totalSeconds1;

    difference->hours = diffSeconds / 3600;
    difference->minutes = (diffSeconds % 3600) / 60;
    difference->seconds = (diffSeconds % 3600) % 60;
}

int main() {
    struct Time startTime, endTime, timeDifference;

    // Read the start time
    printf("Enter the start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    // Read the end time
    printf("Enter the end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    // Calculate the time difference
    getTimeDifference(startTime, endTime, &timeDifference);

    // Display the time difference
    printf("Time difference: %02d:%02d:%02d\n", timeDifference.hours, timeDifference.minutes, timeDifference.seconds);

    return 0;
}
