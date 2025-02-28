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

// Add students
void addStudent(){
    FILE *fp = fopen(FILENAME,"ab");
    if(!fp){
        printf("Error opening file\n");
        return;
    }
    struct Students s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%[^\n]",s.name);
    printf("Enter Age: ");
    scanf("%d",&s.age);
    printf("Enter Marks: ");
    scanf("%d",&s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    Printf("Student record added successfully!\n");
}

// Display student
void displayStudents(){
    FILE *fp =fopen(FILENAME,"rb");
    if(!fp){
        printf("No records found!\n");
        return;
    }
    struct Students s;
    printf("\nID\tName\t Age\tMarks\n");
    while(fread(&s,sizeof(s), 1,fp)){
        printf("%d\t%s\t%d\t%.2f\n",s.id,s.name,s.age,s.marks);
    }
    fclose(fp);
}

//search student
void searchStudent(){
    FILE *fp=fopen(FILENAME,"rb");
    if(!fp){
        printf("no records found!\n");
        return;
    }
    int id,found=0;
    struct Students s;
    printf("Enter student Id to search: ");
    scanf("%d",&id);
    while(fread(&s,sizeof(s), 1, fp)){
        if(s.id==id){
            printf("\nID: %d\nName:%s\nAge: %d\nMarks: %.2f\n",s.id,s.name,s.age,s.marks);
            found=1;
            break;
        }
    }    
    if(!found)printf("Students not found!\n");
    fclose(fp);
}
