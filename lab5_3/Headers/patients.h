//
// Created by Administrator on 2023-03-22.
//

#ifndef LAB5_3_PATIENTS_H
#define LAB5_3_PATIENTS_H
#include <stdlib.h>
#include <stdio.h>
#include <constants.h>
enum Diseases{
    INFLUENZA,
    DIABETES,
    CANCER,
    HYPERTENSION,
    ASTHMA,
    HEPATITIS,
    DEPRESSION,
    MIGRAINES,
    ANEMIA,
    OBESITY,
    ALLERGIE
};
typedef struct{
    int year;
    int month;
    int day;
}Date;
typedef struct{
    char fullName[40];
    char CNP[14];
    Date date;
    enum Diseases disease;
}Patient;
char* getDiseaseByEnum(enum Diseases type);
enum Diseases getDiseaseByChar(char *type);
void printPatient(Patient patient);
void readPatient(Patient *patient);
void allocateMemoryForPatient(Patient **patient, int numberOfPatients);
void deallocateMemoryForPatients(Patient *patient);
void readAllPatientsDetails(Patient **patient, int *numberOfPatients, const char *input);
void printAllPatients(Patient *patient, int numberOfPatients, const char* destination);
#endif //LAB5_3_PATIENTS_H
