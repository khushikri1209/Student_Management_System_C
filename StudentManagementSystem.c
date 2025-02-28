#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "students.dat"

struct Students
{
    int id;
    char name[50];
    int age;
    float marks;
};
void addStudent();
void displayStudent();
void searchStudfent();
void deleteStudent();
void updateStudent();

int main()
{
    int choice;
    while (1)
    {
        printf("\nStudent Management System\n");
        printf("1. add Student\n");
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
            addsStudents();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudents();
            break;
        case 4:
            deleteStudents();
            break;
        case 5:
            updateStudents();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void addStudent(){
    FILE *fp = fopen(FILENAME,"ab");
    if(!fp){
        printf("Erroe opening file\n");
        return;
    }
    
}
