#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_CLASSES 100

typedef struct {
    int classCode;
    char className[MAX_LENGTH];
    int maxClassSize;
    char classDay[4];
    int classTime;
} Class;

Class classes[MAX_CLASSES];
int classCount = 0;

void getClassDetails(int* code, char name[], int* size, char day[], int* time) {
    // Prompt the user to enter the class code
    printf("    Enter class code: ");
    scanf("%d", code);

    // If the class code is less than 0 or greater than 999, error and return to beginning
    if ((*code < 0) || (*code > 999)) {
        printf("\nEntered code is invalid - must be between 0 and 999.");
        return;
    }

    // If the class code already exists, error and return to beginning
    for (int i = 0; i < classCount; i++) {
        if (classes[i].classCode == *code) {
            printf("\nEntered class code already exists in the database.");
            return;
        }
    }

    // Prompt user to enter class name
    printf("    Enter class name: ");
    scanf(" %99[^\n]", name);

    // Use terminating null character to truncate name if longer than max length
    name[MAX_LENGTH - 1] = '\0';

    // Prompt user to enter class size
    printf("    Enter maximum class size: ");
    scanf("%d", size);

    // Check if size is between 10 and 500
    if ((*size <= 10) || (*size >= 500)) {
        printf("\nClass size invalid - must be between 10 and 500.");
        return;
    }

    // Prompt user to enter day of the week
    printf("    Enter the day: ");
    scanf("%s", day);

    // Check if day is valid using strcmp
    if (strcmp(day, "Mon") != 0 && strcmp(day, "Tue") != 0 && strcmp(day, "Wed") != 0 && strcmp(day, "Thu") != 0 && strcmp(day, "Fri") != 0) {
        printf("\nInvalid class day - must be Mon, Tue, Wed, Thu or Fri");
        return;
    }

    // Prompt user to enter class time
    printf("    Enter the time: ");
    scanf("%d", time);

    // Check if the time given is valid
    if (*time != 1 && *time != 2 && *time != 3 && *time != 4 && *time != 9 && *time != 10 && *time != 11 && *time != 12) {
        printf("\n Invalid time - must be 1, 2, 3, 4, 9, 10, 11 or 12");
        return;
    }
}

void insertClass() {
    // If the database is full, error and return to beginning
    if (classCount >= MAX_CLASSES) {
        printf("Cannot insert any more classes - list full.\n");
        return;
    }

   int code, size, time;
   char name[MAX_LENGTH], day[4];

   getClassDetails(&code, name, &size, day, &time);

    // All checks passed - insert class into database

    classes[classCount].classCode = code;
    strcpy(classes[classCount].className, name);
    classes[classCount].maxClassSize = size;
    strcpy(classes[classCount].classDay, day);
    classes[classCount].classTime = time;
    classCount++;

}

void searchClass() {
    int code;

    // Prompt the user for the class code
    printf("\n    Enter class code: ");
    scanf("%d", &code);

    for (int i = 0; i < classCount; i++) {
        if (classes[i].classCode == code) {
            printf("\nClass Code   Class Name                                 Max Class Size    Day       Time");
            printf("\n%-13d%-43s%-18d%-10s%-4d",
               classes[i].classCode, classes[i].className, classes[i].maxClassSize,
               classes[i].classDay, classes[i].classTime);
            return;
        }
    }

    printf("\nClass code not found.");
}

void updateClass() {
    int code;

    // Prompt user to enter code of the class they want to update
    printf("    Enter class code: ");
    scanf("%d", &code);

    for (int i = 0; i < classCount; i++) {
        if(classes[i].classCode == code) {
            int newSize;
            char newName[100];
            char newDay[4];
            int newTime;

            printf("    Enter new information - ");

            getClassDetails(&code, newName, &newSize, newDay, &newTime);

            // Update in database
            classes[i].classCode = code;
            strcpy(classes[i].className, newName);
            classes[i].maxClassSize = newSize;
            strcpy(classes[i].classDay, newDay);
            classes[i].classTime = newTime;

            return;
        }
    }

}

void printClasses() {
    printf("\nClass Code   Class Name                                 Max Class Size    Day       Time");
    
    for(int i = 0; i < classCount; i++) {
        printf("\n%-13d%-43s%-18d%-10s%-4d",
                    classes[i].classCode, classes[i].className, classes[i].maxClassSize,
                    classes[i].classDay, classes[i].classTime);
    }
}

int main() {
    char code;

    while (1) {
        printf("\n\nEnter operation code: ");
        scanf(" %c", &code);

        switch (code) {
            case 'i':
                insertClass();
                break;
            case 's':
                searchClass();
                break;
            case 'u':
                updateClass();
                break;
            case 'p':
                printClasses();
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid code. Please try again.\n");
        }
    }

    return 0;
}