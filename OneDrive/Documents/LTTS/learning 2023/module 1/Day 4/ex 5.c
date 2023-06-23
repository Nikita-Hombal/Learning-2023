#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void swapFields(struct Person* p1, struct Person* p2) {
    // Swap the name fields
    char tempName[50];
    strcpy(tempName, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, tempName);

    // Swap the age fields
    int tempAge = p1->age;
    p1->age = p2->age;
    p2->age = tempAge;
}

int main() {
    struct Person person1, person2;

    // Input the details for person 1
    printf("Enter the name for person 1: ");
    scanf("%s", person1.name);
    printf("Enter the age for person 1: ");
    scanf("%d", &(person1.age));

    // Input the details for person 2
    printf("Enter the name for person 2: ");
    scanf("%s", person2.name);
    printf("Enter the age for person 2: ");
    scanf("%d", &(person2.age));

    // Display the original details
    printf("\nOriginal Details:\n");
    printf("Person 1: Name = %s, Age = %d\n", person1.name, person1.age);
    printf("Person 2: Name = %s, Age = %d\n", person2.name, person2.age);

    // Swap the fields
    swapFields(&person1, &person2);

    // Display the swapped details
    printf("\nSwapped Details:\n");
    printf("Person 1: Name = %s, Age = %d\n", person1.name, person1.age);
    printf("Person 2: Name = %s, Age = %d\n", person2.name, person2.age);

    return 0;
}
