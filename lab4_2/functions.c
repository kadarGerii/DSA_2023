//
// Created by Administrator on 2023-03-11.
//

#include "functions.h"
char* charGender(enum Gender x){
    switch(x){
        case 0:
            return "MALE";
        case 1:
            return "FEMALE";
    }
}
void createStudentArray(int capacity, StudentArray* pArray){
    pArray->capacity = capacity;
    pArray->size = 0;
    pArray->students = (Student_t *)calloc(pArray->capacity, sizeof(Student_t));
    if(pArray->students == NULL){
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void printStudent(Student_t student){
    printf("Name: %s\n", student.name);
    printf("Neptun code: %s\n", student.neptunCode);
    printf("Birth place: %s\n", student.birthPlace);
    printf("Date of birth: %d / %d / %d\n", student.dateOfBirth.year, student.dateOfBirth.month, student.dateOfBirth.day);
    printf("Gender: %s\n", charGender(student.gender));
    printf("Exam result: %0.2f\n\n", student.examResult);
}
void printArray(StudentArray array){
    if(isEmpty(array)){
        printf("%s\n", ARRAY_IS_EMPTY);
        return;
    }
    for (int i = 0; i < array.size; ++i) {
        printStudent(array.students[i]);
    }
    printf("\n");
}
bool isFull(StudentArray array){
    if (array.size == array.capacity)
        return true;
    return false;
}
bool isEmpty(StudentArray array){
    if (array.size == 0)
        return true;
    return false;
}
char* getItemAt(StudentArray array, int position){
    if (position >= 0 && position < array.size) {
        return array.students[position].name;
    }
    else{
        printf("%s\n", INVALID_POSITION);
        return "Not found";
    }
}
void insertFirst(StudentArray* pArray, Student_t item){
    if(isFull(*pArray)){
        printf("%s\n", ARRAY_IS_FULL);
        return;
    }
    for(int i = pArray->size; i > 0; --i){
        pArray->students[i] = pArray->students[i - 1];
    }
    pArray -> students[0] = item;
    pArray->size++;
}
void insertLast(StudentArray* pArray, Student_t item){
    if(isFull(*pArray)){
        printf("%s\n", ARRAY_IS_FULL);
        return;
    }
    pArray -> students[pArray->size++] = item;
}
void insertAt(StudentArray* pArray, int position, Student_t item){
    if(isFull(*pArray)){
        printf("%s\n", ARRAY_IS_FULL);
        return;
    }
    for (int i = position; i > 0; --i) {
        pArray -> students[i] = pArray -> students[i - 1];
    }
    pArray -> size++;
    pArray-> students[position] = item;
}
void deleteItemAt(StudentArray* pArray, int position){
    if(isEmpty(*pArray)){
        printf("%s\n", ARRAY_IS_EMPTY);
        return;
    }
    if(position >= 0 && position < pArray -> size){
        for (int i = position; i < pArray -> size - 1; ++i) {
            pArray -> students[i] = pArray -> students[i + 1];
        }
        pArray -> size--;
    }
}
int search(StudentArray *pArray, char* item){
    for(int i = 0; i < pArray->capacity; ++i){
        if(pArray -> students[i].name == item)
            return i;
    }
    return -1;
}
bool update(StudentArray* pArray, int position, Student_t newItem){
    if(position >= 0 && position <= pArray->size){
        pArray->students[position] = newItem;
        return true;
    }
    else{
        printf("%s\n", INVALID_POSITION);
        return false;
    }
}
void deallocateIntArray(StudentArray *pArray){
    free(pArray->students);
}