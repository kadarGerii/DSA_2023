#include "student.h"

int main() {
    Student_t student1 = {"Kadar Akos Gergo", "JK7WG7", "Sf Gheorghe", 2003, 10, 10, 0, 8.6};
    printStudent(student1);
    Student_t student2;
    freopen("data2.in", "r", stdin);
    readStudentDetails(&student2);
    printStudent(student2);
    freopen("CON", "r", stdin);
    Student_t *student3;
    int numOfStudents;
    readAllStudentsDetails(&student3, &numOfStudents, "data.in");
    printAllStudents(student3, numOfStudents, "CON");
    printf("Number of male students: %d\n", getNumberOfStudentsByGender(student3, numOfStudents, 0));
    printf("Born in Budapest: ");
    printStudentsFromSpecificCity(student3, numOfStudents, "Budapest");
    printf("\nNeptun code search:\n");
    printStudent(findStudentByNeptunCode(student3, numOfStudents, "QSTRG9"));
    printf("\nSort by name:\n");
    sortStudentsByName(student3, numOfStudents);
    printf("\nSort by age and exam:\n");
    sortStudentsByAgeAndExam(student3, numOfStudents);
    return 0;
}
