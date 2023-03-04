//
// Created by Administrator on 2023-02-27.
//

#ifndef LAB3_1_STUDENT_H
#define LAB3_1_STUDENT_H
#include <stdio.h>
#include <stdlib.h>
#include <constants.h>
#include <string.h>
enum Gender{MALE, FEMALE};
typedef struct{
    int year;
    int month;
    int day;
}DateOfBirth;

typedef struct{
    char name[50];
    char neptunCode[9];
    char birthPlace[25];
    DateOfBirth dateOfBirth;
    enum Gender gender;
    float examResult;

}Student_t;
char* charGender(enum Gender x);
void readStudentDetails(Student_t *pStudent);
void printStudent(Student_t student);
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents);
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input);
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination);
int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender);
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city);
int cmp(const void *a, const void *b);
Student_t findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char *nepCode);
int cmpABC(const void *a, const void *b);
void sortStudentsByName(Student_t *pStudents, int numberOfStudents);
void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents);
#endif //LAB3_1_STUDENT_H
