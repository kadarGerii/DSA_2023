#include "student.h"

int main() {
    Student_t *student;
    int numOfStudent;
    readAllStudentsDetails(&student, &numOfStudent, "data.in");
    //printAllStudents(student, numOfStudent, "data.out");
    //printf("%d\n", getNumberOfStudentsByGender(student, numOfStudent, 1));
    //printStudentsFromSpecificCity(student, numOfStudent, "Big Bacon");
    //findStudentByNeptunCode(student, numOfStudent, "QSTRG9");
    sortStudentsByAgeAndExam(student, numOfStudent);
    return 0;
}
