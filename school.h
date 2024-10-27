
#ifndef UPDATED_SCHOOL_H_
#define UPDATED_SCHOOL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Std_Types.h"

/* Student Data */
struct Student {
    u8 name[50];
    u8 date_of_Birth[10];
    u32 id;
    u8 address[50];
    u8 phoneNumber[15];
    f32 computerScienceScore;
};

/* Linked list node for Student */
struct StudentNode {
    struct Student data;
    struct StudentNode* next;
};

/* Function prototypes */
void print_header();
void APP_MENU(struct StudentNode** studentsList, int* numStudents);
void ADD_STUDENT(struct StudentNode** studentsList, int* numStudents);
void EDIT_STUDENT(struct StudentNode* studentsList);
void DISPLAY_STUDENTS(struct StudentNode* studentsList);
void REMOVE_STUDENT(struct StudentNode** studentsList, int* numStudents);
void SORT_STUDENTS(struct StudentNode* studentsList);

#endif
