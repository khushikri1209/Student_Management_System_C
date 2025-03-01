#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.dat"

struct Student
{
    int id;
    char name[50];
    int age;
    float marks;
};
void addStudent();
void displayStudents();
void searchStudent();
void deleteStudent();
void updateStudent();

int main()
{
    int choice;
    while (1)
    {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            updateStudent();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Add student
void addStudent()
{
    FILE *fp = fopen(FILENAME, "ab");
    if (!fp)
    {
        printf("Error opening file\n");
        return;
    }
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    getchar();
    scanf("%[^\n]", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("Student record added successfully!\n");
}

// Display student
void displayStudents()
{
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp)
    {
        printf("No records found!\n");
        return;
    }
    struct Student s;
    printf("\nID\tName\t\tAge\tMarks\n");
    while (fread(&s, sizeof(s), 1, fp))
    {
        printf("%d\t%s\t%d\t%.2f\n", s.id, s.name, s.age, s.marks);
    }
    fclose(fp);
}

// search student
void searchStudent()
{
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp)
    {
        printf("no records found!\n");
        return;
    }
    int id, found = 0;
    struct Student s;
    printf("Enter student Id to search: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.id == id)
        {
            printf("\nID: %d\nName:%s\nAge: %d\nMarks: %.2f\n", s.id, s.name, s.age, s.marks);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Students not found!\n");
    fclose(fp);
}

// delete student

void deleteStudent()
{
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp)
    {
        printf("No records found!\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    int id, found = 0;
    struct Student s;
    printf("Enter Student Id to delete: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.id != id)
            fwrite(&s, sizeof(s), 1, temp);
        else
            found = 1;
    }
    fclose(fp);
    fclose(temp);
    remove(FILENAME);
    rename("temp.dat", FILENAME);
    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Student not found!\n");
}

// Update student

void updateStudent()
{
    FILE *fp = fopen(FILENAME, "rb+");
    if (!fp)
    {
        printf("No records found!\n");
        return;
    }
    int id, found = 0;
    struct Student s;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.id == id)
        {
            printf("Enter new Name: ");
            getchar();
            scanf("%[^\n]", s.name);
            printf("Enter new Age: ");
            scanf("%d", &s.age);
            printf("Enter new Marks: ");
            scanf("%f", &s.marks);
            fseek(fp, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            found = 1;
            break;
        }
    }
    if (found)
        printf("Student record updated successfully!\n");
    else
        printf("Student not found!\n");
    fclose(fp);
}
