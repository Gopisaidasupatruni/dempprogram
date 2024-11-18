#include <stdio.h>
#include <string.h>
#include "functions.h"

int main() {
    Person people[NUM_PEOPLE];
    int choice;
    char searchName[LENGTH];
    FILE *fp;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Enter name and town for 3 people\n");
        printf("2. Search town by name\n");
        printf("3. Save name, town to file\n");
        printf("4. Read data from file\n");
        printf("5. Add last name and address, save to new file\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readPerson(people);
                break;
            case 2:
                printf("Enter name to search for: ");
                scanf(" %[^\n]%*c", searchName);
                char *town = searchTown(people, searchName);
                if (town != NULL) {
                    printf("Town of %s: %s\n", searchName, town);
                } else {
                    printf("Person not found.\n");
                }
                break;
            case 3:
                fp = fopen("people_data.txt", "a+");
                if (fp == NULL) {
                    printf("Error opening file for writing.\n");
                    return 1;
                }
                savePersonToFile(people, fp);
                fclose(fp);
                printf("Data saved to file successfully.\n");
                break;
            case 4:
                fp = fopen("people_data.txt", "r");
                if (fp == NULL) {
                    printf("Error opening file for reading.\n");
                    return 1;
                }
                readPersonFromFile(fp);
                fclose(fp);
                break;
            case 5:
                addAdditionalInfo(people);
                fp = fopen("extended_data.txt", "a+");
                if (fp == NULL) {
                    printf("Error opening file for writing.\n");
                    return 1;
                }
                saveExtendedInfoToFile(people, fp);
                fclose(fp);
                printf("Extended data saved to file.\n");
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}

