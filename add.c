#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(struct Student roster[], int *count)
{
    if (*count >= max_student)
    {
        printf("\nDatabase is full! Cannot add more students.\n");
        return;
    }

    struct Student newStudent;

    printf("\n===== Add New Student =====\n");

    // Student ID
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    while (getchar() != '\n');

    // Check duplicate ID
    for (int i = 0; i < *count; i++)
    {
        if (roster[i].id == newStudent.id)
        {
            printf("Student ID already exists!\n");
            return;
        }
    }

    // Student Name
    printf("Enter Student Name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    // Gender
    printf("Enter Gender: ");
    fgets(newStudent.gender, sizeof(newStudent.gender), stdin);
    newStudent.gender[strcspn(newStudent.gender, "\n")] = '\0';

    // Scores
    float total = 0;

    for (int i = 0; i < num_subject; i++)
    {
        printf("Enter Score %d: ", i + 1);
        scanf("%f", &newStudent.scores[i]);
        total += newStudent.scores[i];
    }

    while (getchar() != '\n');

    // Calculate average
    newStudent.average = total / num_subject;

    // Assign grade
    if (newStudent.average >= 90)
        strcpy(newStudent.grade, "A");
    else if (newStudent.average >= 80)
        strcpy(newStudent.grade, "B");
    else if (newStudent.average >= 70)
        strcpy(newStudent.grade, "C");
    else if (newStudent.average >= 60)
        strcpy(newStudent.grade, "D");
    else
        strcpy(newStudent.grade, "F");

    // Save student
    roster[*count] = newStudent;
    (*count)++;

    printf("\nStudent added successfully!\n");
}
