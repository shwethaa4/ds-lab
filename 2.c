#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    char usn[20];
    int marks;
};


void acceptStudent(struct Student *s) {
    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter USN: ");
    scanf("%s", s->usn);
    printf("Enter marks: ");
    scanf("%d", &s->marks);
}

void displayStudent(struct Student s) {
    printf("\nStudent Details:\n");
    printf("Name: %s\n", s.name);
    printf("USN: %s\n", s.usn);
    printf("Marks: %d\n", s.marks);
}

void compareMarks(struct Student s1, struct Student s2) {
    if (s1.marks > s2.marks) {
        printf("\n%s scored higher marks.\n", s1.name);
        displayStudent(s1);
    } else if (s2.marks > s1.marks) {
        printf("\n%s scored higher marks.\n", s2.name);
        displayStudent(s2);
    } else {
        printf("\nBoth students scored the same marks.\n");
        displayStudent(s1);
        displayStudent(s2);
    }
}

int main() {
    struct Student student1, student2;

    printf("Enter details for Student 1:\n");
    acceptStudent(&student1);

    printf("\nEnter details for Student 2:\n");
    acceptStudent(&student2);

    compareMarks(student1, student2);

    return 0;
}
