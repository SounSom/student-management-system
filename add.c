#include <stdio.h>
#include <string.h>
#include "student.h"

void addStudent(Student students[], int *count) {
    
    if (*count >= MAX_STUDENTS) {
        printf("\nError: Student database capacity reached (%d/%d).\n", *count, MAX_STUDENTS);
        return;
    }

    Student newStudent;
    printf("\n--- Add New Student Record ---\n");
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    
  
    for (int i = 0; i < *count; i++) {
        if (students[i].id == newStudent.id) {
            printf("Error: A student with ID %d already exists in the system.\n", newStudent.id);
            return; 
        }
    }

    printf("Enter Name: ");
    getchar(); r
    fgets(newStudent.name, NAME_MAX, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; 

   
    printf("Enter Major: ");
    fgets(newStudent.major, MAJOR_MAX, stdin);
    newStudent.major[strcspn(newStudent.major, "\n")] = 0; 

    printf("Enter Cumulative GPA: ");
    scanf("%f", &newStudent.gpa);

    students[*count] = newStudent;
    
    (*count)++;

    printf("\nSuccess: Student record added successfully!\n");
}
