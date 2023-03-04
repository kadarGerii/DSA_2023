//
// Created by Administrator on 2023-02-27.
//

#include "student.h"
char* charGender(enum Gender x){
    switch(x){
        case 0:
            return "MALE";
        case 1:
            return "FEMALE";
    }
}
void readStudentDetails(Student_t *pStudent){

    scanf("\n%[^\n]", pStudent->name);

    scanf("\n%[^\n]", pStudent->neptunCode);

    scanf("\n%[^\n]", pStudent->birthPlace);

    scanf("%i%i%i", &pStudent->dateOfBirth.year, &pStudent -> dateOfBirth.month, &pStudent -> dateOfBirth.day);

    scanf("%d", &pStudent->gender);

    scanf("%f", &pStudent->examResult);
}
void printStudent(Student_t student){
    printf("Name: %s\n", student.name);
    printf("Neptun code: %s\n", student.neptunCode);
    printf("Birth place: %s\n", student.birthPlace);
    printf("Date of birth: %d / %d / %d\n", student.dateOfBirth.year, student.dateOfBirth.month, student.dateOfBirth.day);
    printf("Gender: %s\n", charGender(student.gender));
    printf("Exam result: %0.2f\n\n", student.examResult);
}
void allocateMemoryForStudents(Student_t **dpStudents, int numberOfStudents){
    *dpStudents = (Student_t *) malloc(numberOfStudents * sizeof(Student_t));
    if(dpStudents == NULL){
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void readAllStudentsDetails(Student_t **dpStudents, int *numberOfStudents, const char *input){
    if(!freopen(input, "r", stdin)){
        printf("%s", FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%d", numberOfStudents);
    allocateMemoryForStudents(dpStudents, *numberOfStudents);
    for (int i = 0; i < *numberOfStudents; ++i) {
        readStudentDetails(&(*dpStudents)[i]);
    }
    freopen("CON", "r", stdin);
}
void printAllStudents(Student_t *pStudents, int numberOfStudents, const char *destination){
    if(!freopen(destination, "w", stdout)){
        printf("%s", FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    for (int i = 0; i < numberOfStudents; ++i){
        printStudent(pStudents[i]);
    }

    freopen("CON", "w", stdout);
}
int getNumberOfStudentsByGender(Student_t *pStudents, int numberOfStudents, enum Gender gender){
    int sum = 0;
    for (int i = 0; i < numberOfStudents; ++i){
        if(pStudents[i].gender == gender)
            sum ++;
    }
    return sum;
}
void printStudentsFromSpecificCity(Student_t *pStudents, int numberOfStudents, const char *city){
    for (int i = 0; i < numberOfStudents; ++i) {
        if(strcmp(pStudents[i].birthPlace, city) == 0)
            printf("%s\n", pStudents[i].name);
    }
}
int cmp(const void *a, const void *b){
    Student_t *p = (Student_t *)a;
    Student_t *q = (Student_t *)b;
    return strcmp(p->neptunCode, q -> neptunCode);
}
Student_t findStudentByNeptunCode(Student_t *pStudents, int numberOfStudents, const char *nepCode){
    Student_t search;
    qsort(pStudents,numberOfStudents,sizeof(Student_t), cmp);
    strncpy(search.neptunCode, nepCode,sizeof(search.neptunCode));
    Student_t *searchResult = (Student_t * ) bsearch(&search, pStudents, numberOfStudents, sizeof(Student_t), cmp);
    return *searchResult;
}
int cmpABC(const void *a, const void *b){
    Student_t *p = (Student_t*)a;
    Student_t *q = (Student_t*)b;
    return strcmp(p->name, q->name);
}
void sortStudentsByName(Student_t *pStudents, int numberOfStudents){
    qsort(pStudents, numberOfStudents, sizeof(Student_t), cmpABC);
    printAllStudents(pStudents, numberOfStudents, "CON");
}
int cmpAge(const void *a, const void *b){
    Student_t *p = (Student_t*)a;
    Student_t *q = (Student_t*)b;
    if (p->dateOfBirth.year > q -> dateOfBirth.year){
        return 1;
    }
    else if (p -> dateOfBirth.year < q -> dateOfBirth.year) {
        return 0;
    }
    else{
        if (p -> dateOfBirth.month > q -> dateOfBirth.month)
            return 0;
        else if (p -> dateOfBirth.month < q -> dateOfBirth.month)
            return 1;
        else {
            if (p->dateOfBirth.day > q->dateOfBirth.day)
                return 1;
            else if (p->dateOfBirth.day < q->dateOfBirth.day)
                return 0;
            else{
                if(p->examResult > q->examResult)
                    return 0;
                else if(p->examResult < q -> examResult)
                    return 1;
                else return -1;
            }
        }
    }
}
void sortStudentsByAgeAndExam(Student_t *pStudents, int numberOfStudents){
    qsort(pStudents, numberOfStudents, sizeof(Student_t), cmpAge);
    printAllStudents(pStudents, numberOfStudents, "CON");
}