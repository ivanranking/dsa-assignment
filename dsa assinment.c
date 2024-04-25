// Part (a)
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_DOB_LEN 11
#define REG_NUM_LEN 6
#define MAX_PROG_CODE_LEN 4

typedef struct {
    char name[MAX_NAME_LEN];
    char dob[MAX_DOB_LEN];
    char regNum[REG_NUM_LEN];
    char progCode[MAX_PROG_CODE_LEN];
    float annualTuition;
} Student;

// Part (b)
#include <stdlib.h>

#define MAX_STUDENTS 100

Student students[MAX_STUDENTS];
int numStudents = 0;

void createStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    Student newStudent;
    printf("Enter student name: ");
    fgets(newStudent.name, MAX_NAME_LEN, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter date of birth (YYYY-MM-DD): ");
    fgets(newStudent.dob, MAX_DOB_LEN, stdin);
    newStudent.dob[strcspn(newStudent.dob, "\n")] = '\0';

    printf("Enter registration number: ");
    fgets(newStudent.regNum, REG_NUM_LEN + 1, stdin);
    newStudent.regNum[strcspn(newStudent.regNum, "\n")] = '\0';

    printf("Enter program code: ");
    fgets(newStudent.progCode, MAX_PROG_CODE_LEN + 1, stdin);
    newStudent.progCode[strcspn(newStudent.progCode, "\n")] = '\0';

    printf("Enter annual tuition: ");
    scanf("%f", &newStudent.annualTuition);
    getchar(); // Consume newline character

    students[numStudents++] = newStudent;
    printf("Student created successfully.\n");
}

void readStudent() {
    if (numStudents == 0) {
        printf("No students found.\n");
        return;
    }

    int regNum;
    printf("Enter registration number: ");
    scanf("%d", &regNum);
    getchar(); // Consume newline character

    for (int i = 0; i < numStudents; i++) {
        if (atoi(students[i].regNum) == regNum) {
            printf("Name: %s\n", students[i].name);
            printf("Date of Birth: %s\n", students[i].dob);
            printf("Registration Number: %s\n", students[i].regNum);
            printf("Program Code: %s\n", students[i].progCode);
            printf("Annual Tuition: %.2f\n", students[i].annualTuition);
            return;
        }
    }

    printf("Student not found.\n");
}

void updateStudent() {
    if (numStudents == 0) {
        printf("No students found.\n");
        return;
    }

    int regNum;
    printf("Enter registration number: ");
    scanf("%d", &regNum);
    getchar(); // Consume newline character

    for (int i = 0; i < numStudents; i++) {
        if (atoi(students[i].regNum) == regNum) {
            printf("Enter new student name: ");
            fgets(students[i].name, MAX_NAME_LEN, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter new date of birth (YYYY-MM-DD): ");
            fgets(students[i].dob, MAX_DOB_LEN, stdin);
            students[i].dob[strcspn(students[i].dob, "\n")] = '\0';

            printf("Enter new program code: ");
            fgets(students[i].progCode, MAX_PROG_CODE_LEN + 1, stdin);
            students[i].progCode[strcspn(students[i].progCode, "\n")] = '\0';

            printf("Enter new annual tuition: ");
            scanf("%f", &students[i].annualTuition);
            getchar(); // Consume newline character

            printf("Student updated successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void deleteStudent() {
    if (numStudents == 0) {
        printf("No students found.\n");
        return;
    }

    int regNum;
    printf("Enter registration number: ");
    scanf("%d", &regNum);
    getchar(); // Consume newline character

    for (int i = 0; i < numStudents; i++) {
        if (atoi(students[i].regNum) == regNum) {
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            printf("Student deleted successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

// Part (c)
void searchStudent() {
    if (numStudents == 0) {
        printf("No students found.\n");
        return;
    }

    int regNum;
    printf("Enter registration number: ");
    scanf("%d", &regNum);
    getchar(); // Consume newline character

    for (int i = 0; i < numStudents; i++) {
        if (atoi(students[i].regNum) == regNum) {
            printf("Name: %s\n", students[i].name);
            printf("Date of Birth: %s\n", students[i].dob);
            printf("Registration Number: %s\n", students[i].regNum);
            printf("Program Code: %s\n", students[i].progCode);
            printf("Annual Tuition: %.2f\n", students[i].annualTuition);
            return;
        }
    }

    printf("Student not found.\n");
}

// Part (d)
void sortStudents() {
    if (numStudents == 0) {
        printf("No students found.\n");
        return;
    }

    int choice;
    printf("Sort by:\n");
    printf("1. Name\n");
    printf("2. Registration Number\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); // Consume newline character

    switch (choice) {
        case 1:
            for (int i = 0; i < numStudents - 1; i++) {
                for (int j = 0; j < numStudents - i - 1; j++) {
                    if (strcmp(students[j].name, students[j + 1].name) > 0) {
                        Student temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
            printf("Students sorted by name:\n");
            for (int i = 0; i < numStudents; i++) {
                printf("%s\n", students[i].name);
            }
            break;
        case 2:
            for (int i = 0; i < numStudents - 1; i++) {
                for (int j = 0; j < numStudents - i - 1; j++) {
                    if (atoi(students[j].regNum) > atoi(students[j + 1].regNum)) {
                        Student temp = students[j];
                        students[j] = students[j + 1];
                        students[j + 1] = temp;
                    }
                }
            }
            printf("Students sorted by registration number:\n");
            for (int i = 0; i < numStudents; i++) {
                printf("%s\n", students[i].regNum);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

// Part (e)
void exportToFile() {
    if (numStudents == 0) {
        printf("No students found.\n");
        return;
    }

    FILE *file = fopen("students.csv", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s,%s,%s,%s,%.2f\n", students[i].name, students[i].dob, students[i].regNum, students[i].progCode, students[i].annualTuition);
    }

    fclose(file);
    printf("Students exported to students.csv successfully.\n");
}

int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Create Student\n");
        printf("2. Read Student\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Search Student\n");
        printf("6. Sort Students\n");
        printf("7. Export to File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                createStudent();
                break;
            case 2:
                readStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                sortStudents();
                break;
            case 7:
                exportToFile();
                break;
            case 8:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}
