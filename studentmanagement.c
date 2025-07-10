#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50

struct Student {
    int id;
    char name[MAX_NAME];
    float grade;
};

void addStudent(struct Student students[], int *count, FILE *file) {
    if (*count >= MAX_STUDENTS) {
        printf("Storage full!\n");
        return;
    }
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    getchar(); // Clear newline
    printf("Enter name: ");
    fgets(s.name, MAX_NAME, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline
    printf("Enter grade: ");
    scanf("%f", &s.grade);
    
    students[*count] = s;
    (*count)++;
    
    // Save to file
    fseek(file, 0, SEEK_END);
    fprintf(file, "%d,%s,%.2f\n", s.id, s.name, s.grade);
    printf("Student added!\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students found!\n");
        return;
    }
    printf("\nID\tName\tGrade\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void loadStudents(struct Student students[], int *count, FILE *file) {
    rewind(file);
    *count = 0;
    while (*count < MAX_STUDENTS && fscanf(file, "%d,%[^,],%f\n", 
           &students[*count].id, students[*count].name, &students[*count].grade) == 3) {
        (*count)++;
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    FILE *file = fopen("students.txt", "r+");
    if (!file) file = fopen("students.txt", "w+"); // Create if doesn't exist
    
    loadStudents(students, &count, file);
    
    int choice;
    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if (choice == 3) break;
        
        switch (choice) {
            case 1:
                addStudent(students, &count, file);
                break;
            case 2:
                displayStudents(students, count);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    
    fclose(file);
    return 0;
}
