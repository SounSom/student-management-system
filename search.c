#include <stdio.h>
#include <string.h>
#include "student.h"

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
