
// Created by: Updated Code
#include "updated_school.h"
#define MAX_SIZE 10

void print_header() {
    printf("*********************************************\n");
    printf("**** WELCOME TO STUDENT MANAGEMENT SYSTEM ****\n");
    printf("*********************************************\n");
}

void APP_MENU(struct StudentNode** studentsList, int* numStudents) {
    printf("*******************************************\n");
    printf("*************Logged in successfully********\n");
    printf("****WELCOME TO STUDENT MANAGEMENT SYSTEM****\n");
    printf("*******************************************\n");
    printf("To Add a new student Enter [1] \n");
    printf("To Update Data about Student Enter [2] \n");
    printf("To Delete a student Enter [3]\n");
    printf("To View student list Enter [4] \n");
    printf("To Count number of students Enter [5]\n");
    printf("To Rank the top students Enter [6]\n");
    printf("To Exit Enter [7]\n");

    u32 choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            ADD_STUDENT(studentsList, numStudents);
            break;
        case 2:
            EDIT_STUDENT(*studentsList);
            break;
        case 3:
            REMOVE_STUDENT(studentsList, numStudents);
            break;
        case 4:
            DISPLAY_STUDENTS(*studentsList);
            break;
        case 5:
            printf("Number of students = %d\n", *numStudents);
            break;
        case 6:
            SORT_STUDENTS(*studentsList);
            break;
        case 7:
            printf("\nExiting the program\n\tGoodbye\n");
            exit(0);
        default:
            printf("\nPlease Enter a Valid Choice.\n");
            break;
    }
}

// Add new student to the list
void ADD_STUDENT(struct StudentNode** studentsList, int* numStudents) {
    if (*numStudents >= MAX_SIZE) {
        printf("The list is full. Cannot add more students.\n");
        return;
    }
    
    struct StudentNode* newNode = (struct StudentNode*)malloc(sizeof(struct StudentNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter student's ID: ");
    scanf("%u", &newNode->data.id);
    printf("Enter student's name: ");
    scanf("%s", newNode->data.name);
    printf("Enter student's date of birth (DD/MM/YYYY): ");
    scanf("%s", newNode->data.date_of_Birth);
    printf("Enter student's address: ");
    scanf("%s", newNode->data.address);
    printf("Enter student's phone number: ");
    scanf("%s", newNode->data.phoneNumber);
    printf("Enter computer science score: ");
    scanf("%f", &newNode->data.computerScienceScore);

    newNode->next = *studentsList;
    *studentsList = newNode;
    (*numStudents)++;

    printf("Student added successfully!\n");
}

// Edit an existing student's data
void EDIT_STUDENT(struct StudentNode* studentsList) {
    u32 studentID;
    printf("Enter the student's ID to edit: ");
    scanf("%u", &studentID);

    struct StudentNode* current = studentsList;
    while (current != NULL) {
        if (current->data.id == studentID) {
            printf("Editing details for student ID: %u\n", studentID);
            printf("Enter new name: ");
            scanf("%s", current->data.name);
            printf("Enter new date of birth (DD/MM/YYYY): ");
            scanf("%s", current->data.date_of_Birth);
            printf("Enter new address: ");
            scanf("%s", current->data.address);
            printf("Enter new phone number: ");
            scanf("%s", current->data.phoneNumber);
            printf("Enter new computer science score: ");
            scanf("%f", &current->data.computerScienceScore);

            printf("Student information updated successfully!\n");
            return;
        }
        current = current->next;
    }
    printf("Student with ID %u not found.\n", studentID);
}

// Display the list of students
void DISPLAY_STUDENTS(struct StudentNode* studentsList) {
    if (studentsList == NULL) {
        printf("No students in the list.\n");
        return;
    }

    printf("List of students:\n");
    struct StudentNode* current = studentsList;
    while (current != NULL) {
        printf("ID: %u, Name: %s, DOB: %s, Address: %s, Phone: %s, Score: %.2f\n",
               current->data.id, current->data.name, current->data.date_of_Birth,
               current->data.address, current->data.phoneNumber, current->data.computerScienceScore);
        current = current->next;
    }
}

// Remove a student from the list
void REMOVE_STUDENT(struct StudentNode** studentsList, int* numStudents) {
    u32 studentID;
    printf("Enter the student's ID to delete: ");
    scanf("%u", &studentID);

    struct StudentNode* current = *studentsList;
    struct StudentNode* prev = NULL;

    while (current != NULL && current->data.id != studentID) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID %u not found.\n", studentID);
        return;
    }

    if (prev == NULL) {
        *studentsList = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    (*numStudents)--;
    printf("Student removed successfully.\n");
}

// Sort students based on their computer science scores
void SORT_STUDENTS(struct StudentNode* studentsList) {
    if (studentsList == NULL) {
        printf("No students to sort.\n");
        return;
    }

    struct StudentNode* i = studentsList;
    while (i != NULL) {
        struct StudentNode* j = i->next;
        while (j != NULL) {
            if (i->data.computerScienceScore < j->data.computerScienceScore) {
                struct Student temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    printf("Students have been ranked by score.\n");
}
