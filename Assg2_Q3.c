//3. Create array of 10 students(rollno, name, marks) and sort students by their marks. 

#include<stdio.h>
#define size 10;
#define SWAP(a,b) stud temp = a; a = b ; b = temp;

typedef struct stud{
    int rollno;
    char name[20];
    int mark;
}stud;
void stud_data(stud *);
void display_data(stud *s);
void data_sort(stud s[10]);
int main()
{
    stud s[10];

    for(int i=0;i<10;i++)
    {
        stud_data(&s[i]);
    }
    
    data_sort(s);
    for(int i=0;i<10;i++)
    {
        display_data(&s[i]);
    }
    data_sort(s);


}
void stud_data(stud *s)
{
    printf("enter student data: (rollno, name , maek)\n");
    scanf("%d%s%d",&s->rollno,s->name,&s->mark);
}
void display_data(stud *s)
{
    printf("\n%d\t%s\t%d",s->rollno,s->name,s->mark);
}
void data_sort(stud s[10])
{
    int its,pos,flag=0;
    
    for(its = 0; its < 10-1 ; its++)
    {
        
        for(pos=0;pos < 10-its-1 ; pos++ )
        {
            if((s[pos].rollno) > (s[pos+1].rollno))
            {
                // swap
                SWAP(s[pos],s[pos+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
/*
#include <stdio.h>
#include <string.h>

// Define a structure for Student
struct Student {
    int rollno;
    char name[50];
    float marks;
};

// Function to print the student array
void printStudents(struct Student students[], int size) {
    printf("Roll No\tName\t\tMarks\n");
    printf("----------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }
}

// Function to sort students using bubble sort
void bubbleSort(struct Student students[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the current student's marks are less than the next
            if (students[j].marks < students[j + 1].marks) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Student students[10] = {
        {1, "Alice", 85.5},
        {2, "Bob", 92.0},
        {3, "Charlie", 78.0},
        {4, "David", 88.5},
        {5, "Eve", 90.0},
        {6, "Frank", 67.0},
        {7, "Grace", 95.0},
        {8, "Heidi", 82.0},
        {9, "Ivan", 75.0},
        {10, "Judy", 89.0}
    };

    // Sort the students by marks using bubble sort
    bubbleSort(students, 10);

    // Print the sorted students
    printStudents(students, 10);

    return 0;
}
*/