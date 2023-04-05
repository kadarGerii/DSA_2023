//
// Created by Administrator on 2023-03-22.
//

#include <string.h>
#include "../Headers/patients.h"
char* getDiseaseByEnum(enum Diseases type){
    switch(type){
        case INFLUENZA:
            return "INFLUENZA";
        case DIABETES:
            return "DIABETES";
        case CANCER:
            return "CANCER";
        case HYPERTENSION:
            return "HYPERTENSION";
        case ASTHMA:
            return "ASTHMA";
        case HEPATITIS:
            return "HEPATITIS";
        case DEPRESSION:
            return "DEPRESSION";
        case MIGRAINES:
            return "MIGRAINES";
        case ANEMIA:
            return "ANEMIA";
        case OBESITY:
            return "OBESITY";
        case ALLERGIE:
            return "ALLERGIE";
        default:
            return INFLUENZA;
    }
}
enum Diseases getDiseaseByChar(char *type){
    for (int i = 0; i < 11; ++i) {
        if(strcmp(getDiseaseByEnum(i), type) == 0){
            return i;
        }
    }
}
void readPatient(Patient *patient){
    scanf("%[^\n]", patient->fullName);
    scanf("%s", patient -> CNP);
    char diseases[20];
    scanf("%s", diseases);
    patient ->disease = getDiseaseByChar(diseases);
    scanf("%d%d%d", &patient ->date.day, &patient ->date.month, &patient ->date.year);
}
void printPatient(Patient patient){
    printf("Name: %s, CNP: %s, Disease: %s\n", patient.fullName, patient.CNP, getDiseaseByEnum(patient.disease));
}
void allocateMemoryForPatient(Patient **patient, int numberOfPatients){
    *patient =(Patient*) malloc(numberOfPatients*sizeof(Patient));
    if (!* patient) {
        printf("%s", MEMORY_ALLOCATION_ERROR_MESSAGE);
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
}
void deallocateMemoryForPatients(Patient *patient){
    free(patient);
}
void readAllPatientsDetails(Patient **patient, int *numberOfPatients, const char *input){
    if(!freopen(input, "r", stdin)){
        printf("%s", FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    scanf("%d", numberOfPatients);
    allocateMemoryForPatient(patient, *numberOfPatients);
    for (int i = 0; i < *numberOfPatients; i++) {
        readPatient(&(*patient)[i]);
    }
    freopen("CON", "r", stdin);
}
void printAllPatients(Patient *patient, int numberOfPatients, const char* destination){
    if(!freopen(destination, "w", stdout)){
        printf("%s", FILE_OPENING_ERROR_MESSAGE);
        exit(FILE_OPENING_ERROR_CODE);
    }
    for(int i = 0; i<numberOfPatients; ++i)
        printPatient(patient[i]);
    freopen("CON", "w", stdout);
}