#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to represent a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Global array to store student records
struct Student *students[MAX_STUDENTS];
int numStudents = 0;

// Function prototypes
void addStudent();
void displayAllStudents();
void searchStudentByRollNumber();
void updateStudent();
void deleteStudent();
void saveDataToFile();
void loadDataFromFile();

int main() {
    int choice;

    loadDataFromFile();

    while (1) {
        printf("\nStudent Database Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Save Data to File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudentByRollNumber();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                saveDataToFile();
                break;
            case 7:
                saveDataToFile();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        printf("Cannot add more students. Database full.\n");
        return;
    }

    students[numStudents] = (struct Student *)malloc(sizeof(struct Student));

    printf("Enter roll number: ");
    scanf("%d", &students[numStudents]->rollNumber);

    printf("Enter name: ");
    scanf("%s", students[numStudents]->name);

    printf("Enter marks: ");
    scanf("%f", &students[numStudents]->marks);

    numStudents++;
}

void displayAllStudents() {
    if (numStudents == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("Roll Number\tName\tMarks\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d\t\t%s\t%.2f\n", students[i]->rollNumber, students[i]->name, students[i]->marks);
    }
}

void searchStudentByRollNumber() {
    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            printf("Student Found:\n");
            printf("Roll Number: %d\nName: %s\nMarks: %.2f\n", students[i]->rollNumber, students[i]->name, students[i]->marks);
            return;
        }
    }

    printf("Student with roll number %d not found.\n", rollNumber);
}

void updateStudent() {
    int rollNumber;
    printf("Enter roll number to update: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            printf("Enter new name: ");
            scanf("%s", students[i]->name);

            printf("Enter new marks: ");
            scanf("%f", &students[i]->marks);

            printf("Record updated successfully.\n");
            return;
        }
    }

    printf("Student with roll number %d not found.\n", rollNumber);
}

void deleteStudent() {
    int rollNumber;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < numStudents; i++) {
        if (students[i]->rollNumber == rollNumber) {
            free(students[i]);
            for (int j = i; j < numStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            numStudents--;
            printf("Record deleted successfully.\n");
            return;
        }
    }

    printf("Student with roll number %d not found.\n", rollNumber);
}

void saveDataToFile() {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fwrite(&numStudents, sizeof(int), 1, file);

    for (int i = 0; i < numStudents; i++) {
        fwrite(students[i], sizeof(struct Student), 1, file);
    }

    fclose(file);
    printf("Data saved to file successfully.\n");
}

void loadDataFromFile() {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("File not found. Starting with an empty database.\n");
        return;
    }

    fread(&numStudents, sizeof(int), 1, file);

    for (int i = 0; i < numStudents; i++) {
        students[i] = (struct Student *)malloc(sizeof(struct Student));
        fread(students[i], sizeof(struct Student), 1, file);
    }

    fclose(file);
    printf("Data loaded from file successfully.\n");
}
