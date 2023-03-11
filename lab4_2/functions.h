//
// Created by Administrator on 2023-03-11.
//

#ifndef LAB4_2_FUNCTIONS_H
#define LAB4_2_FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <constants.h>
#include <time.h>

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
typedef struct {
    int capacity;
    int size;
    Student_t *students;
}StudentArray;
char* charGender(enum Gender x);
void createStudentArray(int capacity, StudentArray* pArray);
void printStudent(Student_t student);
void printArray(StudentArray array);
bool isFull(StudentArray array);
bool isEmpty(StudentArray array);
char* getItemAt(StudentArray array, int position);
void insertFirst(StudentArray* pArray, Student_t item);
void insertLast(StudentArray* pArray, Student_t item);
void insertAt(StudentArray* pArray, int position, Student_t item);
void deleteItemAt(StudentArray* pArray, int position);
int cmp(const void* a, const void* b);
int search(StudentArray *pArray, char* item);
bool update(StudentArray* pArray, int position, Student_t newItem);
void deallocateIntArray(StudentArray *pArray);
#endif //LAB4_2_FUNCTIONS_H
