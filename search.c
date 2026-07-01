#include <stdio.h>
#include <string.h>
#include "student.h"

<<<<<<< HEAD
// Forward declarations for helper functions
void searchById(struct Student roster[], int count);
void searchByName(struct Student roster[], int count);

void searchStudent(struct Student roster[], int count) {
    if (count == 0) {
        printf(bold_on "\nNo student records available to search.\n" bold_off);
        return;
    }

    int searchChoice;
    do {
        printf(bold_on "\n=== SEARCH STUDENT RECORDS ===\n" bold_off);
        printf("1. Search by Student ID\n");
        printf("2. Search by Name\n");
        printf("3. Display All Students\n");
        printf("4. Return to Main Menu\n");
        printf(bold_on "Enter your choice: " bold_off);

        if (scanf("%d", &searchChoice) != 1) {
            printf(bold_on "\nInvalid input. Please enter a number.\n" bold_off);
            while (getchar() != '\n');
            searchChoice = 0; // Invalid choice
            continue;
        }
        while (getchar() != '\n'); // Clear buffer

        switch(searchChoice) {
            case 1: searchById(roster, count); break;
            case 2: searchByName(roster, count); break;
            case 3: displayStudents(roster, count); break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf(bold_on "\nInvalid choice. Please try again.\n" bold_off);
        }
    } while (searchChoice != 4);
}

// Search by ID Function
void searchById(struct Student roster[], int count) {
    int id;
    printf(bold_on "\nEnter Student ID to search: " bold_off);

    if (scanf("%d", &id) != 1) {
        printf(bold_on "\nInvalid input.\n" bold_off);
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    // Linear search through array
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (roster[i].id == id) {
            // Found matching student - display their information
            printf(bold_on "\n=== STUDENT RECORD FOUND ===\n" bold_off);
            printf("ID: %d\n", roster[i].id);
            printf("Name: %s\n", roster[i].name);
            printf("Gender: %s\n", roster[i].gender);
            printf("Scores: ");
            for (int j = 0; j < num_subject; j++) {
                printf("%.2f ", roster[i].scores[j]);
            }
            printf("\nAverage: %.2f\n", roster[i].average);
            printf("Grade: %s\n", roster[i].grade);
            found = 1;
            break; // Assuming IDs are unique, we can stop after first match
        }
    }

    if (!found) {
        printf(bold_on "\nNo student found with ID %d.\n" bold_off, id);
    }
}

// Search by Name (Partial Match)
void searchByName(struct Student roster[], int count) {
    char name[50];
    printf(bold_on "\nEnter name (or part of name) to search: " bold_off);
    scanf(" %[^\n]%*c", name);

    int found = 0;
    printf(bold_on "\n=== SEARCH RESULTS FOR \"%s\" ===\n" bold_off, name);

    for (int i = 0; i < count; i++) {
        // strstr looks for the first occurrence of substring
        if (strstr(roster[i].name, name) != NULL) {
            printf("ID: %d | Name: %s | Gender: %s | Avg: %.2f | Grade: %s\n",
                   roster[i].id, roster[i].name, roster[i].gender,
                   roster[i].average, roster[i].grade);
            found = 1;
        }
    }

    if (!found) {
        printf(bold_on "\nNo students found matching \"%s\".\n" bold_off, name);
    }
}
=======
void searchStudent(struct Student roster[], int count)
{
    if (count == 0)
    {
        printf("\nNo students in the database.\n");
        return;
    }

    int choice;
    int found = -1;

    printf("\n===== Search Student =====\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Choose option: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int id;

        printf("Enter Student ID: ");
        scanf("%d", &id);
        while (getchar() != '\n');

        for (int i = 0; i < count; i++)
        {
            if (roster[i].id == id)
            {
                found = i;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        char name[50];

        while (getchar() != '\n');

        printf("Enter Student Name: ");
        fgets(name, sizeof(name), stdin);

        name[strcspn(name, "\n")] = '\0';

        for (int i = 0; i < count; i++)
        {
            if (strcmp(roster[i].name, name) == 0)
            {
                found = i;
                break;
            }
        }
    }
    else
    {
        printf("Invalid option.\n");
        return;
    }

    if (found == -1)
    {
        printf("\nStudent not found.\n");
    }
    else
    {
        printf("\n===== Student Information =====\n");
        printf("ID      : %d\n", roster[found].id);
        printf("Name    : %s\n", roster[found].name);
        printf("Gender  : %s\n", roster[found].gender);

        printf("Scores  : ");
        for (int i = 0; i < num_subject; i++)
        {
            printf("%.1f ", roster[found].scores[i]);
        }

        printf("\nAverage : %.2f\n", roster[found].average);
        printf("Grade   : %s\n", roster[found].grade);
    }
}
>>>>>>> de18caa5c7f9f6cf707b06ffcef9e66dbd74542d
