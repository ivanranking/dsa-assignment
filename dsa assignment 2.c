#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 51
#define DATE_LENGTH 11
#define REGISTRATION_LENGTH 7
#define PROGRAM_CODE_LENGTH 5
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char dob[DATE_LENGTH];
    char registration[REGISTRATION_LENGTH];
    char program_code[PROGRAM_CODE_LENGTH];
    float tuition;
} Student;

void createStudent(Student *students, int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter student's name: ");
    scanf(" %[^\n]s", students[*numStudents].name);

    printf("Enter student's date of birth (YYYY-MM-DD): ");
    scanf(" %10s", students[*numStudents].dob);

    printf("Enter student's registration number: ");
    scanf(" %6s", students[*numStudents].registration);

    printf("Enter student's program code: ");
    scanf(" %4s", students[*numStudents].program_code);

    printf("Enter student's annual tuition: ");
    scanf("%f", &students[*numStudents].tuition);

    (*numStudents)++;
}

void readStudents(Student *students, int numStudents) {
    if (numStudents == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Date of Birth: %s, Registration: %s, Program Code: %s, Tuition: %.2f\n",
               students[i].name, students[i].dob, students[i].registration,
               students[i].program_code, students[i].tuition);
    }
}

void updateStudent(Student *students, int numStudents) {
    // Your code here
}

void deleteStudent(Student *students, int *numStudents) {
    // Your code here
}

void searchByRegistration(Student *students, int numStudents) {
    // Your code here
}

void sortStudents(Student *students, int numStudents) {
    // Your code here
}

void exportToFile(Student *students, int numStudents) {
    // Your code here
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create a new student\n");
        printf("2. Read students\n");
        printf("3. Update a student\n");
        printf("4. Delete a student\n");
        printf("5. Search by registration number\n");
        printf("6. Sort students\n");
        printf("7. Export records to a file\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createStudent(students, &numStudents);
                break;
            case 2:
                readStudents(students, numStudents);
                break;
            case 3:
                updateStudent(students, numStudents);
                break;
            case 4:
                deleteStudent(students, &numStudents);
                break;
            case 5:
                searchByRegistration(students, numStudents);
                break;
            case 6:
                sortStudents(students, numStudents);
                break;
            case 7:
                exportToFile(students, numStudents);
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 8.\n");
        }
    } while (choice != 8);

    return 0;
}
