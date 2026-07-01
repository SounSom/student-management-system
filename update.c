#include <stdio.h>
#include <string.h>
#include "student.h"

<<<<<<< HEAD
// Forward declarations for helper functions
void updateName(struct Student roster[], int index);
void updateGender(struct Student roster[], int index);
void updateScores(struct Student roster[], int index);

void updateStudent(struct Student roster[], int count) {
    if (count == 0) {
        printf(bold_on "\nNo student records available to update.\n" bold_off);
        return;
    }

    int id;
    printf(bold_on "\nEnter Student ID of record to update: " bold_off);

    if (scanf("%d", &id) != 1) {
        printf(bold_on "\nInvalid input.\n" bold_off);
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    // Find the student
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (roster[i].id == id) {
            index = i;
=======
void updateStudent(struct Student roster[], int count)
{

    if (count == 0)
    {
        printf("  [!] No students to update.\n");
        return;
    }

    int searchID, i, found = -1;
    printf("\nEnter Student ID to update: ");
    scanf("%d", &searchID);
    while (getchar() != '\n')
        ;

    for (i = 0; i < count; i++)
    {
        if (roster[i].id == searchID)
        {
            found = i;
>>>>>>> de18caa5c7f9f6cf707b06ffcef9e66dbd74542d
            break;
        }
    }

<<<<<<< HEAD
    if (index == -1) {
        printf(bold_on "\nNo student found with ID %d.\n" bold_off, id);
        return;
    }

    // Student found, now show what we have and what we can update
    printf(bold_on "\n=== CURRENT STUDENT INFORMATION ===\n" bold_off);
    printf("ID: %d\n", roster[index].id);
    printf("Name: %s\n", roster[index].name);
    printf("Gender: %s\n", roster[index].gender);
    printf("Scores: ");
    for (int j = 0; j < num_subject; j++) {
        printf("%.2f ", roster[index].scores[j]);
    }
    printf("\nAverage: %.2f\n", roster[index].average);
    printf("Grade: %s\n", roster[index].grade);

    // Update menu
    int updateChoice;
    do {
        printf(bold_on "\n=== SELECT FIELD TO UPDATE ===\n" bold_off);
        printf("1. Name\n");
        printf("2. Gender\n");
        printf("3. Scores (all subjects)\n");
        printf("4. Return to Main Menu\n");
        printf(bold_on "Enter your choice: " bold_off);

        if (scanf("%d", &updateChoice) != 1) {
            printf(bold_on "\nInvalid input.\n" bold_off);
            while (getchar() != '\n');
            updateChoice = 0;
            continue;
        }
        while (getchar() != '\n');

        switch(updateChoice) {
            case 1: updateName(roster, index); break;
            case 2: updateGender(roster, index); break;
            case 3: updateScores(roster, index); break;
            case 4: printf("Returning to main menu...\n"); break;
            default: printf(bold_on "\nInvalid choice. Please try again.\n" bold_off);
        }
    } while (updateChoice != 4);

    // Recalculate average and grade if scores were changed
    // (We'll handle this in the updateScores function or check if needed)
}

// Helper Functions for Each Field

// Update Name
void updateName(struct Student roster[], int index) {
    printf(bold_on "Enter new name (current: %s): " bold_off, roster[index].name);
    scanf(" %[^\n]%*c", roster[index].name);
    printf(bold_on "\nName updated successfully.\n" bold_off);
}

// Update Gender
void updateGender(struct Student roster[], int index) {
    printf(bold_on "Enter new gender (current: %s): " bold_off, roster[index].gender);
    scanf(" %[^\n]%*c", roster[index].gender);
    printf(bold_on "\nGender updated successfully.\n" bold_off);
}

// Update Scores
void updateScores(struct Student roster[], int index) {
    printf(bold_on "Enter new scores for %d subjects:\n" bold_off, num_subject);
    float total = 0;
    int validInput = 1;

    for (int j = 0; j < num_subject; j++) {
        printf("  Subject %d (current: %.2f): ", j+1, roster[index].scores[j]);
        if (scanf("%f", &roster[index].scores[j]) != 1) {
            printf(bold_on "\nInvalid score input.\n" bold_off);
            validInput = 0;
            while (getchar() != '\n');
            break;
        }

        // Validate score range
        if (roster[index].scores[j] < 0 || roster[index].scores[j] > 100) {
            printf(bold_on "\nScore must be between 0 and 100.\n" bold_off);
            validInput = 0;
            break;
        }

        total += roster[index].scores[j];
    }

    if (validInput) {
        // Update average and grade
        roster[index].average = total / num_subject;

        if (roster[index].average >= 90) {
            strcpy(roster[index].grade, "A");
        } else if (roster[index].average >= 80) {
            strcpy(roster[index].grade, "B");
        } else if (roster[index].average >= 70) {
            strcpy(roster[index].grade, "C");
        } else if (roster[index].average >= 60) {
            strcpy(roster[index].grade, "D");
        } else {
            strcpy(roster[index].grade, "F");
        }

        printf(bold_on "\nScores, average, and grade updated successfully.\n" bold_off);
    }
}
=======
    if (found == -1)
    {
        printf("  [!] Student ID %d not found.\n", searchID);
        return;
    }

    struct Student *s = &roster[found];

    printf("New Name   (current: %s): ", s->name);
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("New Gender (current: %s): ", s->gender);
    fgets(s->gender, sizeof(s->gender), stdin);
    s->gender[strcspn(s->gender, "\n")] = '\0';

    float total = 0.0f;
    for (i = 0; i < num_subject; i++)
    {
        printf("New Score %d (current: %.2f): ", i + 1, s->scores[i]);
        scanf("%f", &s->scores[i]);
        total += s->scores[i];
    }
    while (getchar() != '\n')
        ;

    s->average = total / num_subject;

    if (s->average >= 90.0f)
        strcpy(s->grade, "A");
    else if (s->average >= 80.0f)
        strcpy(s->grade, "B");
    else if (s->average >= 70.0f)
        strcpy(s->grade, "C");
    else if (s->average >= 60.0f)
        strcpy(s->grade, "D");
    else
        strcpy(s->grade, "F");

    printf("\n  [+] Student updated! Avg: %.2f | Grade: %s\n\n",
           s->average, s->grade);
}

>>>>>>> de18caa5c7f9f6cf707b06ffcef9e66dbd74542d
