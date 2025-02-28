#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FILENAME "students.dat"

struct Students{
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

int main(){
    int choice;
    while(1){
        printf("\nStudent Management System\n");
        printf("1. add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);
    }
}


