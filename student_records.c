/*
 * Student Record System in C
 * Records are saved in a text file named students.txt
 * Every student has roll no, name, course and marks.
 */

#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    char course[30];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Could not open file.\n");
        return;
    }
    printf("Enter roll no: ");
    scanf("%d", &s.roll);
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter course (e.g. BCA, BTech): ");
    scanf("%s", s.course);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %s %.2f\n", s.roll, s.name, s.course, s.marks);
    fclose(fp);
    printf("Student added successfully.\n");
}

void displayAll() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found. Add a student first.\n");
        return;
    }
    printf("\nRoll  Name            Course      Marks\n");
    printf("-------------------------------------------\n");
    while (fscanf(fp, "%d %s %s %f", &s.roll, s.name, s.course, &s.marks) != EOF) {
        printf("%-5d %-15s %-11s %.2f\n", s.roll, s.name, s.course, s.marks);
    }
    fclose(fp);
}

void searchStudent() {
    struct Student s;
    int rollToFind, found = 0;
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }
    printf("Enter roll no to search: ");
    scanf("%d", &rollToFind);

    while (fscanf(fp, "%d %s %s %f", &s.roll, s.name, s.course, &s.marks) != EOF) {
        if (s.roll == rollToFind) {
            printf("Found: %d %s %s %.2f\n", s.roll, s.name, s.course, s.marks);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Student with roll %d not found.\n", rollToFind);
    }
    fclose(fp);
}

void deleteStudent() {
    struct Student s;
    int rollToDelete, found = 0;
    FILE *fp = fopen("students.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }
    printf("Enter roll no to delete: ");
    scanf("%d", &rollToDelete);

    while (fscanf(fp, "%d %s %s %f", &s.roll, s.name, s.course, &s.marks) != EOF) {
        if (s.roll == rollToDelete) {
            found = 1;
        } else {
            fprintf(temp, "%d %s %s %.2f\n", s.roll, s.name, s.course, s.marks);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found) printf("Record deleted.\n");
    else printf("Roll no not found, nothing deleted.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Student Record System ---\n");
        printf("1. Add student\n");
        printf("2. Display all students\n");
        printf("3. Search student by roll no\n");
        printf("4. Delete student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) addStudent();
        else if (choice == 2) displayAll();
        else if (choice == 3) searchStudent();
        else if (choice == 4) deleteStudent();
        else if (choice == 5) {
            printf("Program closed.\n");
            break;
        } else {
            printf("Wrong choice, try again.\n");
        }
    }
    return 0;
}
