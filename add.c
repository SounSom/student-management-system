#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(struct Student roster[], int *count) {
    // 1. Check Capacity
    if (*count >= max_student) {
        printf(bold_on "\nError: Database is full. Cannot add more students.\n" bold_off);
        return;
    }

    // 2. Get and Validate Student ID
    int id;
    printf(bold_on "\nEnter Student ID: " bold_off);
    if (scanf("%d", &id) != 1) {
        printf(bold_on "\nInvalid input for ID.\n" bold_off);
        while (getchar() != '\n'); // Clear buffer
        return;
    }

    // Check for duplicate ID
    for (int i = 0; i < *count; i++) {
        if (roster[i].id == id) {
            printf(bold_on "\nError: Student with ID %d already exists.\n" bold_off, id);
            while (getchar() != '\n'); // Clear buffer
            return;
        }
    }

    // 3. Get Student Information
    roster[*count].id = id; // Store the validated ID

    printf(bold_on "Enter Student Name: " bold_off);
    scanf(" %[^\n]%*c", roster[*count].name); // Read line with spaces

    printf(bold_on "Enter Gender (Male/Female/Other): " bold_off);
    scanf(" %[^\n]%*c", roster[*count].gender);

    // 4. Get and Validate Scores
    printf(bold_on "Enter scores for %d subjects:\n" bold_off, num_subject);
    float total = 0;
    int validInput = 1;

    for (int j = 0; j < num_subject; j++) {
        printf("  Subject %d: ", j+1);
        if (scanf("%f", &roster[*count].scores[j]) != 1) {
            printf(bold_on "\nInvalid score input.\n" bold_off);
            validInput = 0;
            // Clear remaining input
            while (getchar() != '\n');
            break;
        }

        // Validate score range (0-100)
        if (roster[*count].scores[j] < 0 || roster[*count].scores[j] > 100) {
            printf(bold_on "\nScore must be between 0 and 100.\n" bold_off);
            validInput = 0;
            break;
        }

        total += roster[*count].scores[j];
    }

    if (!validInput) {
        return; // Exit if any input was invalid
    }

    // 5. Calculate Average and Grade
    roster[*count].average = total / num_subject;

    // Determine grade based on average
    if (roster[*count].average >= 90) {
        strcpy(roster[*count].grade, "A");
    } else if (roster[*count].average >= 80) {
        strcpy(roster[*count].grade, "B");
    } else if (roster[*count].average >= 70) {
        strcpy(roster[*count].grade, "C");
    } else if (roster[*count].average >= 60) {
        strcpy(roster[*count].grade, "D");
    } else {
        strcpy(roster[*count].grade, "F");
    }

    // 6. Finalize and Confirm
    (*count)++; // Increment the student count

    printf(bold_on "\nStudent record added successfully!\n" bold_off);
    printf("Student ID: %d\n", id);
    printf("Name: %s\n", roster[*count-1].name); // Note: *count-1 is the index of the newly added student
}
