#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n;
    float total = 0;
    struct employee *emp;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    emp = (struct employee *)malloc(n * sizeof(struct employee));
    printf("size of structure : %d bytes",(int)sizeof(struct employee));

    if (emp == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &emp[i].id);
        printf("Name: ");
        scanf("%s", emp[i].name);
        printf("Monthly Salary: ");
        scanf("%f", &emp[i].salary);

        total += emp[i].salary * 12;
    }

    printf("\nTotal annual salary expenditure: %f\n", total);

    free(emp);
    return 0;
}

